#include "abstract.h"
//BASIC
Baddr createElmBis(string name){
    Baddr X=new elmBis();
    name(X)=name;
    slot(X)=0;
    createListSupir(X->supir);
    next(X)=prev(X)=NULL;
    return X;
}
Saddr createElmSupir(string name){
    Saddr X=new elmSupir();
    name(X)=name;
    his(X)=bis(X)=0;
    createListBis(X->dikendarai);
    createListBis(X->history);
    next(X)=prev(X)=NULL;
    return X;
}
void createListBis(Bis &B){
    firstB(B)=NULL;
}
void createListSupir(Supir &S){
    firstS(S)=NULL;
}
bool isEmptyBis(Bis B){
    return firstB(B)==NULL;
}
bool isEmptySupir(Supir S){
    return firstS(S)==NULL;
}
void tambahSupir(Supir &S){
    string name;
    printf("Masukan Nama Supir : ");cin>>name;
    if(cariSupir(S,name))cout<<"Supir Sudah Ada.\n";
    else addSupir(S,createElmSupir(name));
}
void tambahBis(Bis &B){
    string name;
    printf("Masukan Nama Bis : ");cin>>name;
    if(cariBis(B,name))cout<<"Bis Sudah Ada.\n";
    else addBis(B,createElmBis(name));
}
//SOAL SOAL
void addSupir(Supir &S,Saddr SPO){ //1
    if(isEmptySupir(S)){
        firstS(S)=SPO;
        next(firstS(S))=prev(firstS(S))=SPO; //Supir objek
    }else{
        next(SPO)=firstS(S);
        prev(SPO)=prev(firstS(S));
        next(prev(SPO))=SPO;
        prev(next(SPO))=SPO;
    }
}
void addBis(Bis &B,Baddr BSO){ //2
    if(isEmptyBis(B)){
        firstB(B)=BSO;
        next(firstB(B))=prev(firstB(B))=BSO; //Bis objek
    }else{
        next(BSO)=firstB(B);
        prev(BSO)=prev(firstB(B));
        Baddr temp=prev(firstB(B));
        prev(firstB(B))=BSO;
        next(temp)=BSO;
    }
}
void createHubungan(Bis &B,Supir &S,string nameSupir,string nameBis){ //3
    Baddr X=cariBis(B,nameBis);
    Saddr Y=cariSupir(S,nameSupir);
    if(X==NULL&&Y==NULL)cout<<"Bis dan Supir Tidak Ditemukan.\n";
    else if(X==NULL)cout<<"Bis Tidak Ditemukan.\n";
    else if(Y==NULL)cout<<"Supir Tidak Ditemukan.\n";
    else{
        if(slot(X)>=2)cout<<"Bis Sudah Memiliki Kondektur & Supir.\n";
        else if(cariSupir(supirBis(X),nameSupir))cout<<"Sudah Dipekerjakan Disini.\n";
        else{
            addBis(bisDikendarai(Y),createElmBis(name(X)));
            addBis(historyBis(Y),createElmBis(name(X)));
            addSupir(supirBis(X),createElmSupir(name(Y)));
            slot(X)++;
            his(Y)++;
            bis(Y)++;
        }
    }
}
void deleteSupir(Supir &S,Bis &B,string nameSupir){ //4
    if(isEmptySupir(S))cout<<"Tidak Ada Supir.\n";
    else{
        Saddr X=cariSupir(S,nameSupir);
        if(X==NULL)cout<<"Supir Tidak Ditemukan.\n";
        else{
            if(bis(X)>0){
                Baddr C=firstB(X->dikendarai);
                Baddr A;
                while(bis(X)>0){
                    A=cariBis(B,name(C));
                    deleteSupirBasic(A->supir,nameSupir);
                    slot(A)--;
                    bis(X)--;
                    C=next(C);
                }
            }
            deleteSupirBasic(S,nameSupir);
        }
    }
}
void deleteBis(Supir &S,Bis &B,string nameBis){ //5
    if(isEmptyBis(B))cout<<"Tidak Ada Bis.\n";
    else{
        Baddr X=cariBis(B,nameBis);
        if(X==NULL)cout<<"Bis Tidak Ditemukan.\n";
        else{
            if(slot(X)>0){
                Saddr C=firstS(X->supir);
                Saddr A;
                while(slot(X)>0){
                    A=cariSupir(S,name(C));
                    deleteBisBasic(A->dikendarai,nameBis);
                    slot(X)--;
                    bis(A)--;
                    C=next(C);
                }
            }
            deleteBisBasic(B,nameBis);
        }
    }
}
void tampilkanHistorySemuaSupir(Supir S){ //6
    if(isEmptySupir(S))cout<<"Tidak Ada Supir.\n";
    else{
        Saddr X=firstS(S);
        do{
            cout<<name(X)<<" : ";
            printAllBis(X->history);
            X=next(X);
        }while(X!=firstS(S));
    }
}
void tampilkanSupirBis(Bis B,string nameBis){ //7
    if(isEmptyBis(B))cout<<"Tidak Ada Bis.\n";
    else{
        Baddr X=cariBis(B,nameBis);
        if(X==NULL)cout<<"Bis Tidak Ditemukan.\n";
        else printAllSupir(supirBis(X));
    }
}
void tampilkanSupirDenganBisTerbanyak(Supir S){ //8
    int X=kuantitasBis(S,"banyak");
    Saddr curr=firstS(S);
    do{
        if(bis(curr)==X){
            cout<<"Nama : "<<name(curr)<<endl;
            cout<<"History Bis : ";printAllBis(curr->history);
        }
        curr=next(curr);
    }while(curr!=firstS(S));
}
void tampilkanSupirDenganBisTerdikit(Supir S){ //9
    int X=kuantitasBis(S,"sedikit");
    Saddr curr=firstS(S);
    do{
        if(bis(curr)==X){
            cout<<"Nama : "<<name(curr)<<endl;
            cout<<"History Bis : ";printAllBis(curr->history);
        }
        curr=next(curr);
    }while(curr!=firstS(S));
}
//ADDITION
void tampilkanSupirDanBisDikendarai(Supir S){
    if(isEmptySupir(S))cout<<"Tidak Ada Supir.\n";
    else{
        Saddr X=firstS(S);
        do{
            cout<<name(X)<<" : ";
            printAllBis(X->dikendarai);
            X=next(X);
        }while(X!=firstS(S));
    }
}
void printAllBis(Bis B){
    if(isEmptyBis(B))cout<<"Tidak Ada Bis.\n";
    else{
        Baddr X=firstB(B);
        do{
            cout<<name(X);
            printf(" - ");
            X=next(X);
        }while(X!=(firstB(B)));
        cout<<"End.\n";
    }
}
void printAllSupir(Supir S){
    printf("Supir Tersedia : ");
    if(isEmptySupir(S))cout<<"Tidak Ada Supir.\n";
    else{
        Saddr X=firstS(S);
        do{
            cout<<name(X);
            printf(" - ");
            X=next(X);
        }while(X!=(firstS(S)));
        cout<<"End.\n";
    }
}
void printBisTersedia(Bis B){
    printf("Bis Tersedia : ");
    if(isEmptyBis(B))cout<<"Tidak Ada Bis.\n";
    else{
        Baddr X=firstB(B);
        int banyak=0;
        do{
            if(slot(X)<2){
                cout<<name(X);
                printf(" - ");
                banyak++;
            }
            X=next(X);
        }while(X!=(firstB(B)));
        if(banyak=0)cout<<"Tidak Ada Bis Tersedia.\n";
        else cout<<"Bis Terakhir.\n";
    }
}
Baddr cariBis(Bis B,string nameBis){
    if(isEmptyBis(B))return NULL;
    else{
        Baddr curr=firstB(B);
        while(curr!=prev(firstB(B))&&name(curr)!=nameBis)curr=next(curr);
        if(name(curr)==nameBis)return curr;
        return NULL;
    }
}
Baddr cariBisDalamSupir(Supir S,string nameSupir,string nameBis){
    if(isEmptySupir(S))return NULL;
    else{
        Saddr X=cariSupir(S,nameSupir);
        if(isEmptyBis(X->dikendarai))return NULL;
        else return cariBis(X->dikendarai,nameBis);
    }
}
Saddr cariSupir(Supir S,string nameSupir){
    if(isEmptySupir(S))return NULL;
    else{
        Saddr curr=firstS(S);
        while(curr!=prev(firstS(S))&&name(curr)!=nameSupir)curr=next(curr);
        if(name(curr)==nameSupir)return curr;
        return NULL;
    }
}
int kuantitasBis(Supir S,string mode){
    if(isEmptySupir(S))return NULL;
    else{
        Saddr curr=firstS(S);
        int help=bis(curr);
        do{
            if(help<bis(curr)&&mode=="banyak")
                help=bis(curr);
            else if(help>bis(curr)&&mode=="sedikit")
                help=bis(curr);
            curr=next(curr);
        }while(curr!=firstS(S));
        return help;
    }
}
void deleteBisBasic(Bis &B,string nameBis){
    if(isEmptyBis(B))cout<<"Tidak ada Bis.\n";
    else{
        Baddr X=cariBis(B,nameBis);
        if(next(firstB(B))==firstB(B)){
            firstB(B)=NULL;
        }else if(X==firstB(B)){
            firstB(B)=next(firstB(B));
            prev(firstB(B))=prev(X);
            next(prev(X))=firstB(B);
        }else{
            next(prev(X))=next(X);
            prev(next(X))=prev(X);
        }
    }
}
void deleteSupirBasic(Supir &S,string nameSupir){
    if(isEmptySupir(S))cout<<"Tidak ada Supir.\n";
    else{
        Saddr X=cariSupir(S,nameSupir);
        if(next(firstS(S))==firstS(S)){
            firstS(S)=NULL;
        }else if(X==firstS(S)){
            firstS(S)=next(firstS(S));
            prev(firstS(S))=prev(X);
            next(prev(X))=firstS(S);
        }else{
            next(prev(X))=next(X);
            prev(next(X))=prev(X);

        }
    }
}
void hapusHubungan(Supir S,Bis B,string nameSupir, string nameBis){
    if(isEmptyBis(B)&&isEmptySupir(S))cout<<"Tidak ada Supir dan Bis.\n";
    else if(isEmptySupir(S))cout<<"Tidak ada Supir.\n";
    else if(isEmptyBis(B))cout<<"Tidak ada Bis.\n";
    else {
        Saddr supir=cariSupir(S,nameSupir);
        Baddr bis=cariBis(B,nameBis);
        if(supir==NULL||bis==NULL)cout<<"Supir atau Bis Tidak Ditemukan.\n";
        else{
            bis->slot--;
            supir->bis--;
            deleteBisBasic(supir->dikendarai,nameBis);
            deleteSupirBasic(bis->supir,nameSupir);
        }
    }
}
