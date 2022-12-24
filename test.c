//Muhammad Syafiq Ibrahim (L0122116) C
//Responsi 2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void cls();                                     //parameter cls
int Menu();                                     //parameter Menu
void hapus();                                   //parameter hapus
FILE *txt;                                      //global pointer
void readBin();
void savetxt();                                 //parameter savetxt
void pembatas();                                //parameter pembatas
void writeBin();
void keluarProgram();                           //parameter keluarProgram
void editDataMahasiswa();                       //parameter editDataMahasiswa
void lihatDataMahasiswa();                      //parameter lihatDataMahasiswa
void inputDataMahasiswa();                      //parameter inputDataMahasiswa

//struct Mahasiswa
struct Mahasiswa {
    char NIM[100];
    char Nama[100];
    char Jenis_Kelamin[100];
    char IPK[100];
};

struct Mahasiswa UNS[100] = {
    {"L0122113", "Muhammad Abdullah G", "Laki", "4,7"},
    {"L0122114", "Muhammad Harun R", "Laki", "3,6"},
    {"L0122115", "Muhammad Saifuddin E", "Laki", "3,5"},
    {"L0122116", "Muhammad Syafiq I", "Laki", "4,0"},  
};

typedef struct Mahasiswa mahasiswa;
mahasiswa UNS[100]; //istilah mahasiswa UNS berbentuk array

    //tipe data global                   
    char d, nama[20];
    unsigned int x,y;
    int i, j, jumlah, ulang, total;
    static char ubah[50], dir[500];

//main
void main() {
    system("cls");
    //infinite Loop
    while ((i = Menu())) {
        switch(i) {
            case 1:
                inputDataMahasiswa();          //pemanggil fungsi inputDataMahasiswa
            break;
            case 2:
                system("cls");                  //membersihkan layar
                lihatDataMahasiswa();           //pemanggil lihatDataMahaswa
                printf("\n\nTekan Enter Untuk Kembali...");
                cls();                          //pemanggil fungsi cls
            break;
            case 3 :
                system("cls");                  //membersihkan layar
                editDataMahasiswa();            //pemanggil fungsi editDataMahasiswa
                break;
            case 4 :
                system("cls");                  //membersihkan layar
                hapus();                      //!pemanggil fungsi savebit
                break;
            case 5 :
                system("cls");                  //membersihkan layar
                savetxt();                      //pemanggil fungsi save txt
                break;
            case 6 :
                system("cls");                  //membersihkan layar
                writeBin();                      //pemanggil fungsi savebit
                break;
            case 0 :
                system("cls");                  //membersihkan layar
                keluarProgram();                       //pemanggil fungsi keluarProgram
                break;
            default:
                system("cls");                  //pemanggil
                puts("Masukkan Angka Yang Sesuai");
            break;
        }
    }
}

//fungsi Menu
int Menu() {
    printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n\n%s", 
            "===========================",
            "            Menu           ",
            "===========================",
            "1. Tambah Data Mahasiswa",
            "2. Lihat Data Mahasiswa",
            "3. Edit Data Mahasiswa",
            "4. Hapus Data Mahasiswa",
            "5. Simpan Data (.txt)",
            "6. Input Data (input.txt)",
            "0. Keluar Dari Program",
            "Input : ");
    int k;
    scanf("%d", &k);
    return k;
}

//fungsi Input
void inputDataMahasiswa() {
    system("cls");
    printf("Berapa Data? "); scanf("%d", &ulang);

        //looping array of struc
        for (int i = jumlah; i < jumlah+ulang; i++) {
            printf("Nama Mahasiswa\t: ");scanf(" %50[^\n]", &UNS[i].Nama);
            printf("NIM\t\t: "); scanf("%s", &UNS[i].NIM);
            printf("Kelamin\t\t: "); scanf("%s", &UNS[i].Jenis_Kelamin);
            printf("IPK\t\t: ");scanf("%s", &UNS[i].IPK);
            system("cls");
        }
        jumlah+=ulang;
        total+=jumlah;
    system("cls");             //membersihkan layar
}

//fungsi savetxt
void savetxt() {
    xx :

    //ketika kondisi salah
    if((txt = fopen("input.txt", "w")) == NULL) { 
        printf("Gagal !!!\n");
        printf("\nTekan ENTER Untuk Melanjutkan...");
        goto xx;                    //ke poin xx
        cls();                      //pemanggil fungsi cls
    }

    //ketika kondisi berhasil
    else {
    fprintf(txt,"%3s %-20s\t\t%-10s %-15s %-5s\n",
            "No.","Nama Mahasiswa","NIM","Kelamin","IPK");
    for(int i=0; i<jumlah; i++) {
        fprintf(txt, "%.2d. %-20s\t\t%-10s %-15s %-5s\n", (i+1), UNS[i].Nama, 
        UNS[i].NIM, UNS[i].Jenis_Kelamin, UNS[i].IPK);
    }
    fclose(txt);
    printf("Silahkan Di Cek, Lalu Tekan Enter Untuk Melanjutkan Program");   
    cls();                          //pemanggil fungsi cls
    }
}

//fungsi editDataMahasiswa
void editDataMahasiswa() {
    enum editData {
        Nama = 1,
        NIM,
        Jenis_Kelamin,
        IPK,
    };
    int opsi, menu;
    pembatas();                             //pemanggil fungsi pembatas
    printf("\t\t\t    Edit");
    pembatas();                             //pemanggil fungsi pembatas
    printf("Masukkan Nama Mahasiswa : "); scanf(" %50[^\n]", &nama);

    //looping untuk mengecek nama
    for(int i=0; i<jumlah; i++) {
        if(strcmp(nama, UNS[i].Nama)==0) {
            printf("%s\n%s\n%s",
            "1. Hapus Data","2. Edit Data", "Input : "); scanf("%d", &menu);
        switch (menu) {
            case 1 :
                hapus();                    //pemanggil fungsi hapus
                break;
            case 2 :
                system("cls");
                printf("\n%s\n%s\n%s\n%s\n%s\n%s",
                "=======Menu=======",
                "1. Nama",
                "2. NIM",
                "3. Kelamin",
                "4. IPK",
                "Masukkan Nomor : ");scanf("%d", &opsi);
                switch (opsi) {
                    case Nama:
                        printf("Seharusnya Tertulis : "); scanf(" %50[^\n]", &ubah);
                        strcpy(UNS[i].Nama, ubah);
                        break;
                    case NIM:
                        printf("Seharusnya Tertulis : "); scanf("%s", &ubah);
                        strcpy(UNS[i].NIM, ubah);
                        break;
                    case Jenis_Kelamin:
                        printf("Seharusnya Tertulis : "); scanf("%s", &ubah);
                        strcpy(UNS[i].Jenis_Kelamin, ubah);
                        break;
                    case IPK:
                        printf("Seharusnya Tertulis : "); scanf("%s", &ubah);
                        strcpy(UNS[i].IPK, ubah);
                        break;
                    default:
                        system("cls");
                        printf("Masukkan Input Sesuai Pilihan");
                        break;
                }
            }
        }
    }
    system("cls");
}

//fungsi hapus
void hapus() { 
    lihatDataMahasiswa();
    pembatas();                             //pemanggil fungsi pembatas
    printf("\t\t\t    Edit");
    pembatas();                             //pemanggil fungsi pembatas
    printf("Masukkan Nama Mahasiswa : "); scanf(" %50[^\n]", &nama);

    //looping untuk mengecek nama
    for (int i = 0; i < jumlah; i++) {
        if (strcmp(nama, UNS[i].Nama)==0) {
            for (int k = i; k < jumlah; k++) {
                strcpy(UNS[k].Nama, UNS[k+1].Nama);
                strcpy(UNS[k].NIM, UNS[k+1].NIM);
                strcpy(UNS[k].Jenis_Kelamin, UNS[k+1].Jenis_Kelamin);
                strcpy(UNS[k].IPK, UNS[k+1].IPK);
            }
            jumlah--;
        }
    }  
}     


//fungsi cls
void cls() {
    while(getchar() != '\n');       //syarat input  
    getchar();
    system("cls");                  //membersihkan layat
}

//fungsi pembatas
void pembatas () {
    printf("\n============================================================\n");
}
//fungsi lihatDataMahasiswa
void lihatDataMahasiswa(){
        printf("%-10s %-20s\t\t %-15s %-5s\n",
        "NIM","Nama Mahasiswa","Kelamin","IPK");
    for(int i=0; i<jumlah; i++) {
        printf("%-10s %-20s\t\t %-15s %-5s\n", UNS[i].NIM, UNS[i].Nama, 
        UNS[i].Jenis_Kelamin, UNS[i].IPK);
    }
}

void writeBin() {

    jumlah += 4;
    FILE *fPtr;
    fPtr = fopen("input.txt", "w");
    if(fPtr != NULL) {
        fprintf(fPtr,"%-10s %-20s\t\t %-15s %-5s\n",
            "NIM","Nama Mahasiswa","Kelamin","IPK");
        for(int i = jumlah+1; i < 4; i++) {
            fprintf(fPtr,"%-10s %-20s\t\t %-15s %-5s\n", UNS[i].NIM, UNS[i].Nama, 
            UNS[i].Jenis_Kelamin, UNS[i].IPK);
        }
        fclose(fPtr);
        printf("Write data ke file tamanbacaan.bin telah berhasil!\n");
    } else {
        printf("Tidak dapat write data ke file tamanbacaan.bit\n");
    }
}
/*
void readBin() {
    FILE *fPtr;
    fPtr = fopen("input.txt", "r");
    if(fPtr != NULL) {
        rewind(fPtr);
            printf("%3s %-20s\t\t%-10s %-15s %-5s\n",
            "No.","Nama Mahasiswa","NIM","Kelamin","IPK");
        for(int i = 0; i < 4; i++) {
            fread(&UNS[i], sizeof(UNS), 1, fPtr);
            printf("%-20s\t\t%-10s %-15s %-5s\n", UNS[i].Nama, 
            UNS[i].NIM, UNS[i].Jenis_Kelamin, UNS[i].IPK);
    
        }
        fclose(fPtr);
    } else {
        printf("File tamanbacaaan.bin tidak tersedia.\n");
    }
}
*/

//fungsi keluarProgram
void keluarProgram() {
    system("cls");
    pembatas();                     //memanggil fungsi pembatas
    printf("\n\t\t  Terima Kasih\n");
    pembatas();                     //memanggil fungsi pembatas
    exit(0);                        //keluarProgram dari program/code
}