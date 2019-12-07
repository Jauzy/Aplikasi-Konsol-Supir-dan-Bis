#include "abstract.h"

using namespace std;

int main()
{
    Bis B;createListBis(B);
    Supir S;createListSupir(S);
    string nS,nB;
    char pilihan;
    do{
        system("cls");
        printf("===============PROGRAM BIS DAN SUPIR===============\n");
        printf("---------------------------------------------------\n");
        printBisTersedia(B);
        printAllSupir(S);
        printf("1. Tambah Supir Baru.\n");
        printf("2. Tambah Bis Baru.\n");
        printf("3. Pekerjakan Supir Ke Bis.\n");
        printf("4. Hapus Supir.\n");
        printf("5. Hapus Bis.\n");
        printf("6. Tampilkan History Bis Semua Supir.\n");
        printf("7. Tampilkan Supir Untuk Bis Tertentu.\n");
        printf("8. Supir Dengan Bis Paling Banyak.\n");
        printf("9. Supir Dengan Bis Paling Sedikit.\n");
        printf("X.Tampilkan Semua Supir Dan Bis Yang Dikendarai.\n");
        printf("Y.Delete Hubungan Supir dan Bis Tertentu.\n");
        printf("Masukan Pilihan Anda : ");cin>>pilihan;
        system("cls");
        printf("===============PROGRAM BIS DAN SUPIR===============\n");
        printf("---------------------------------------------------\n");
        printBisTersedia(B);
        printAllSupir(S);
        switch(tolower(pilihan)){
            case '1':
                tambahSupir(S);system("pause");
                break;
            case '2':
                tambahBis(B);system("pause");
                break;
            case '3':
                printf("Masukan Nama Supir : ");cin>>nS;
                printf("Masukan Nama Bis : ");cin>>nB;
                createHubungan(B,S,nS,nB);system("pause");
                break;
            case '4':
                printf("Masukan Nama Supir : ");cin>>nS;
                deleteSupir(S,B,nS);
                system("pause");
                break;
            case '5':
                printf("Masukan Nama Bis : ");cin>>nB;
                deleteBis(S,B,nB);
                system("pause");
                break;
            case '6':
                tampilkanHistorySemuaSupir(S);system("pause");
                break;
            case '7':
                printf("Masukan Nama Bis : ");cin>>nB;
                tampilkanSupirBis(B,nB);system("pause");
                break;
            case '8':
                tampilkanSupirDenganBisTerbanyak(S);system("pause");
                break;
            case '9':
                tampilkanSupirDenganBisTerdikit(S);system("pause");
                break;
            case 'x':
                tampilkanSupirDanBisDikendarai(S);system("pause");
                break;
            case 'y':
                printf("Masukan Nama Supir : ");cin>>nS;
                printf("Masukan Nama Bis : ");cin>>nB;
                hapusHubungan(S,B,nS,nB);system("pause");
                break;
            default:
                cout<<"Anda Memasukan Pilihan Menu Yang Salah.\n";system("pause");
        }
    }while(pilihan!='0');
    return 0;
}
