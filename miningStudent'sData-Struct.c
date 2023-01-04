#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

/*
Maaf bu jika kodenya belum sempurna, mohon maaf jika kodenya berantakan
Saya sudah berusaha semaksimal mungkin
Known issues :
    1. ketika masuk daftar nilai, entah mengapa ketika memilih menu, daftar nilai dicetak dua kali
    2. autosave daftar nilai setelah mengedit, program langsung berhenti
    3. hasil save di file txt belum rapi
    4. terkadang ketika di menu nilai, ketika memilih menu, malah kembali ke menu nilai kembali
    5. saya belum membuat union
    6. masih ada warning di fungsi bitwise
    7. save txt belum ada keterangan
    8. opsi untuk keluar dari program belum selesai

    ditulis pada tanggal 3 November 2022 jam 23:00
*/

struct personal {
    int total;
    char nama[100][20];
    char umur[100][20];  
    char kota[100][20];  
    char nim[100][10];
    char gender[100][20];
    struct nilai {
        int KonsPro[100];
        int SisDig[100];
        int Fisika[100];
        int Kalkulus[100];
        int Stats[100];
    } skor;
};

enum saveMode{
    saveAs,
    updateNilai,
    updateBio,
};
enum delete{
    hapusDataNilai,
    hapusDataBio,
};
enum sortMode{
    byName,
    byNim,
    byUmur,
};
enum lists{
    bioList,
    gradeList,
};

typedef struct personal person;
int fileAction, choice;
static int by;
char char1[20], char2[20];
unsigned int value;
unsigned int x;
unsigned int y;
char dirGrade[50];
char dirBio[50];

void menu();
void menuBio();
void menuNilai();
void dataBio();
void dataNilai();
void printDaftarBio();
void printDaftarNilai();
void editDaftarBio();
void editDaftarNilai();
void sideBySide();
void hapusData(int which);
void sortList(int by);
void swapStr(char *str1, char *str2);
void swapInt(int int1, int int2);
int strcmpWithNull(char *str1, char *str2);
void Bits(unsigned int value);
int inputBit();
void and(unsigned int x, unsigned int y);
void or(unsigned int x, unsigned int y);
void xor(unsigned int x, unsigned int y);
void saveListtxt(int fileAction);
int openBioFile();
person mhs;

int main(){
    while(choice!=5){
        menu();
    }
    return 0;
}

void menu(){
    sideBySide();
    puts("");
    puts("=================== MENU PROGRAM MINING DATA MAHASISWA ======================");
    printf("1. Buka list Bio\n2. Buka list Nilai\n3. Bitwise\n4. Ubah mode sorting\n5. Exit\ncatatan : jika ingin memasukkan nilai, masukkan biodata mahasiswa terlebih dahulu !\nApa yang ingin kamu lakukan : ");
    scanf("%d", &choice);
    system("cls");
    if(choice==1){
        menuBio();
    }
    else if (choice==2){
        menuNilai();
    }
    else if (choice==3){
        inputBit();
        int a;
        printf("1. AND\n2. OR\n3. X-OR\nApa yang ingin dicari : "); scanf("%d", &a);
        switch (a)
        {
        case 1:
            and(x, y);
            break;
        case 2:
            or(x, y);
            break;
        case 3:
            xor(x, y);
            break;
        default:
            break;
        }
    }
    else if(choice==4){
        sideBySide();
        puts("=============== Menu untuk mengubah metode pengurutan daftar ===============");
        int urut;
        printf("1. Diurutkan berdasarkan nama\n2. Diurutkan berdasarkan NIM\n3. Diurutkan berdasarkan Umur\nBagaimana daftar diurutkan : "); scanf("%d", &urut);
        switch (urut)
        {
        case 1:
            by = byName;
            break;
        case 2:
            by = byNim;
            break;
        case 3:
            by = byUmur;
            break;
        }
        sortList(by);
        system("cls");
        menu();
    }
    else if(choice==5){
        system("cls");
        sideBySide();
    }
}

void menuBio(){
    enum gradeOpt {
        noBioOpt = 1,
        openBioFileOpt,
        insertBioOpt,
        editBioListOpt,
        deleteBioOpt,
        saveBioListOpt,
        quitBioOpt,
    };
    int choice;
    printDaftarBio();
    printf("1. Ganti mode\n2. Import data\n3. Memasukkan biodata mahasiswa\n4. Mengedit daftar\n5. Menghapus data\n6. save daftar dalam file .txt\n7. Keluar ke menu utama\nApa yang ingin kamu lakukan : ");
    scanf("%d", &choice);
    puts("");
    system("cls");
    printDaftarBio();
    switch (choice)
    {
    case noBioOpt:
        system("cls");
        menuNilai();
        break;
    case insertBioOpt:
        dataBio();
        menuBio();
        break;
    case editBioListOpt:
        editDaftarBio();
        saveListtxt(updateBio);
        menuBio();
        break;
    case deleteBioOpt:
        hapusData(hapusDataBio);
        saveListtxt(updateBio);
        menuBio();
        break;
    case saveBioListOpt:
        saveListtxt(saveAs);
        menuBio();
        break;
    case quitBioOpt:
        system("cls");
        break;
    case openBioFileOpt:
        openBioFile();
        system("cls");
        menuBio();
        break;
    default:
        printf("Operasi tidak dikenali !!!\n");
        menuBio();
        break;
    }
}

void menuNilai(){
    enum gradeOpt {
        noGradeOpt = 1,
        insertGradeOpt,
        editGradeListOpt,
        deleteGradeOpt,
        saveGradeListOpt,
        quitGradeOpt,
    };
    int choice;
    printDaftarNilai();
    printf("1. Ganti Mode\n2. Memasukkan daftar nilai mahasiswa\n3. Edit daftar\n4. Hapus data\n5. Save daftar dalam file .txt\n6. Keluar ke menu utama\n");
    printf("Apa yang ingin kamu lakukan : ");
    scanf("%d", &choice);
    system("cls");
    printDaftarNilai();
    switch (choice)
    {
    case noGradeOpt:
        system("cls");
        menuBio();
        break;
    case insertGradeOpt:
        dataNilai();
        menuNilai();
        break;
    case editGradeListOpt:
        editDaftarNilai();
        saveListtxt(updateNilai);
        menuNilai();
        break;
    case deleteGradeOpt:
        hapusData(hapusDataNilai);
        saveListtxt(updateNilai);
        menuNilai();
        break;
    case saveGradeListOpt:
        saveListtxt(saveAs);
        menuNilai();
        break;
    case quitGradeOpt:
        system("cls");
        break;
    default:
        printf("Operasi tidak dikenali\n");
        menuNilai();
        break;
    }
}

static int plus;
void dataBio() {
    int now = mhs.total;
    printf("Berapa total mahasiswa yang ingin didata : ");
    scanf("%d", &plus);
    mhs.total = mhs.total + plus;
    system("cls");
    for(int i=now; i<mhs.total; i++){
        printDaftarBio();
        printf("Masukkan data biodata\n");
        printf("Nama\t: "); scanf(" %50[^\n]", &mhs.nama[i]);
        printf("NIM\t: "); scanf("%s", &mhs.nim[i]);
        printf("Gender\t: "); scanf(" %50[^\n]", &mhs.gender[i]);
        printf("Umur\t: "); scanf("%s", &mhs.umur[i]);
        printf("Kota\t: "); scanf("%s", &mhs.kota[i]);
        system("cls");
    }
}

void dataNilai(){
    static int first=0;
    int now;
    if(first==0){
        now=0;
        first++;
    }
    else{
        now = mhs.total - plus;
    }

    for(int i=now; i<mhs.total; i++){
        system("cls");
        printDaftarNilai();
        printf("Masukkan nilai mahasiswa\n");
        printf("%s\n", mhs.nama[i]);
        printf("KonsPro\t: "); scanf("%d", &mhs.skor.KonsPro[i]);
        printf("SisDig\t: "); scanf("%d", &mhs.skor.SisDig[i]);
        printf("Fisika\t: "); scanf("%d", &mhs.skor.Fisika[i]);
        printf("Kalku\t: "); scanf("%d", &mhs.skor.Kalkulus[i]);
        printf("Stats\t: "); scanf("%d", &mhs.skor.Stats[i]);
        system("cls");
    }
}


void printDaftarBio(){
    sortList(by);
    puts("========================= BIO =============================");
    printf("%3s %-11s%-9s%-11s%-11s%-2s\n", "No.", "Nama", "NIM", "Gender", "Kota", "Umur");
    for(int i=0; i<mhs.total; i++){
        printf("%.2d. %-11s%-9s%-11s%-11s%-2s\n", (i+1), mhs.nama[i], mhs.nim[i], mhs.gender[i], mhs.kota[i], mhs.umur[i]);
    }
    puts("===========================================================");
}

void printDaftarNilai(){
    puts("========================= SKOR ============================");
    printf("%3s %-11s%-9s%-9s%-9s%-9s%-9s\n", "No.", "Nama", "KonsPro", "SisDig", "Fisika", "Kalku", "Stats");
    for(int i=0; i<mhs.total; i++){
        printf("%.2d  %-13s%-9d%-9d%-9d%-9d%-9d\n", (i+1), mhs.nama[i], mhs.skor.KonsPro[i], mhs.skor.SisDig[i], mhs.skor.Fisika[i], mhs.skor.Kalkulus[i], mhs.skor.Stats[i]);
    }
    puts("===========================================================");
}

void sideBySide(){
    printf("========================= BIO =============================\t========================= SKOR ============================\n");
    printf("%3s %-11s%-9s%-11s%-11s%-2s\t\t%3s %-11s%-9s%-9s%-9s%-9s%-9s\n", "No.", "Nama", "NIM", "Gender", "Kota", "Umur", "No.", "Nama", "KonsPro", "SisDig", "Fisika", "Kalku", "Stats");
    for(int i=0; i<mhs.total; i++){
        printf("%.2d. %-11s%-9s%-11s%-11s%-2s\t\t%.2d  %-13s%-9d%-9d%-9d%-9d%-9d\n", (i+1), mhs.nama[i], mhs.nim[i], mhs.gender[i], mhs.kota[i], mhs.umur[i], (i+1), mhs.nama[i], mhs.skor.KonsPro[i], mhs.skor.SisDig[i], mhs.skor.Fisika[i], mhs.skor.Kalkulus[i], mhs.skor.Stats[i]);
    }
    printf("===========================================================\t===========================================================\n");
}

void editDaftarBio(){
    char change[20];
    char name[20];
    enum editBio{
        Nama = 1,
        NIM = 2,
        Gender = 3,
        Kota = 4,
        Umur = 5,
    };
    int which;
    printf("============ EDIT BIO ===============\n");
    printf("Masukkan nama mahasiswa : "); scanf(" %50[^\n]", &name);
    for(int i=0; i<mhs.total; i++){
        if(strcmp(name, mhs.nama[i])==0){
            printf("1. Nama\n2. NIM\n3. Gender\n4. Kota\n5. Umur\nApa yang ingin diedit : "); scanf("%d", &which);
            printf("Bagaimana seharusnya tertulis : "); scanf(" %50[^\n]", &change);
            switch (which)
            {
            case Nama:
                strcpy(mhs.nama[i], change);
                break;
            case NIM:
                strcpy(mhs.nim[i], change);
                break;
            case Gender:
                strcpy(mhs.gender[i], change);
                break;
            case Kota:
                strcpy(mhs.kota[i], change);
                break;
            case Umur:
                strcpy(mhs.umur[i], change);
                break;
            default:
                printf("Operasi tidak dikenali !!!");
                break;
            }
        }
    }
}

void editDaftarNilai(){
    int change;
    char name[20];
    enum editGrade{
        KonsPro = 1,
        SisDig = 2,
        Fisika = 3,
        Kalkulus = 4,
        Stats = 5,
    };
    int which;
    printf("============ EDIT NILAI ===============\n");
    printf("Masukkan nama mahasiswa : "); scanf(" %50[^\n]", &name);
    for(int i=0; i<mhs.total; i++){
        if(strcmp(name, mhs.nama[i])==0){
            printf("1. KonsPro\n2. SisDig\n3. Fisika\n4. Kalkulus\n5. Stats\nApa yang ingin diedit : "); scanf("%d", &which);
            printf("Bagaimana seharusnya tertulis : "); scanf("%d", &change);
            switch (which)
            {
            case KonsPro:
                mhs.skor.KonsPro[i] = change;
                break;
            case SisDig:
                mhs.skor.SisDig[i] = change;
                break;
            case Fisika:
                mhs.skor.Fisika[i] = change;
                break;
            case Kalkulus:
                mhs.skor.Kalkulus[i] = change;
                break;
            case Stats:
                mhs.skor.Stats[i] = change;
                break;
            default:
                printf("Operasi tidak dikenali !!!");
                break;
            }
        }
    }
}

void saveListtxt(int fileAction){
    FILE *txtfile;
    txtfile = fopen("gerhgie\\wfuwfiwef\\ewfuewfi", "w");
    int choose;
    if(fileAction==saveAs){
        printf("1. List biodata\n2. List nilai\nApa yang ingin disave : "); scanf("%d", &choose);
        printf("Masukkan Direktori output tanpa tanda petik (contoh: E:\\cprogram\\daftar.txt)\n");
        if(choose==1){
            scanf("%s", &dirBio);
            txtfile = fopen(dirBio, "w");
        }
        else if(choose==2){
            scanf("%s", &dirGrade);
            txtfile = fopen(dirGrade, "w");
        }

        if(txtfile == NULL) {
            printf("Tidak ada direktori semacam itu !!!\n");
            printf("Tekan ENTER untuk kembali ke menu...");
            while(getchar() != '\n');
            getchar();
            system("cls");
        }
    }
    else if(fileAction==updateNilai){
        txtfile = fopen(dirGrade, "w");
        if(txtfile == NULL){
            system("cls");
            menuNilai();
        }
    }
    else if(fileAction==updateBio){
        txtfile = fopen(dirBio, "w");
        if(txtfile == NULL){
            system("cls");
            menuBio();
        }
    }

    if(txtfile!=NULL && (fileAction==updateNilai || fileAction==updateBio) || fileAction==saveAs) {
        fprintf(txtfile, "======================== REKAP MAHASISWA =======================\n");
        if(choose==2 || fileAction==updateNilai){
            txtfile = fopen(dirGrade, "w");
            fprintf(txtfile, "%3s %-11s%-9s%-9s%-9s%-9s%-9s\n", "No.", "Nama", "KonsPro", "SisDig", "Fisika", "Kalku", "Stats");
            for(int i=0; i<mhs.total; i++) {
                fprintf(txtfile, "%.2d  %-13s%-9d%-9d%-9d%-9d%-9d\n", (i+1), mhs.nama[i], mhs.skor.KonsPro[i], mhs.skor.SisDig[i], mhs.skor.Fisika[i], mhs.skor.Kalkulus[i], mhs.skor.Stats[i]);
            }
        }
        else if(choose==1 || fileAction==updateBio){
            txtfile = fopen(dirBio, "w");
            fprintf(txtfile, "%3s %-11s%-9s%-11s%-11s%-2s\n", "No.", "Nama", "NIM", "Gender", "Kota", "Umur");
            for(int i=0; i<mhs.total; i++) {
                fprintf(txtfile, "%.2d. %-11s%-9s%-11s%-11s%-2s\n", (i+1), mhs.nama[i], mhs.nim[i], mhs.gender[i], mhs.kota[i], mhs.umur[i]);
            }
        }
        fclose(txtfile);
        if(fileAction==saveAs){
            if(choose==1){
                printf("Daftar sudah tersimpan di %s\n", dirBio);
            }
            else if(choose==2){
                printf("Daftar sudah tersimpan di %s\n", dirGrade);
            }
        printf("Tekan ENTER untuk kembali ke menu...");
        while(getchar() != '\n');
        getchar();
        system("cls");
    }
    }
}

void Bits(unsigned int value) {
    unsigned int displayMask = 1 << 31;
    printf("%10u = ", value);

    for (unsigned int c = 1; c <= 32; ++c) { 
    putchar((value & displayMask) ? '1':'0');
    value <<= 1; 

        if (c % 8 == 0) { 
        putchar(' ');
            }
        }
        putchar('\n');
}

int inputBit(){
    printf("%s", "Masukkan bilangan positif 1: ");scanf("%u", &x);
    printf("%s", "Masukkan bilangan positif 2: ");scanf("%u", &y);
    return x,y;
}

void and(unsigned int x, unsigned int y){
    puts("Hasil :");
    Bits(x); 
    Bits(y);
    puts("Bitwise AND operator & adalah");
    Bits(x & y);  
}

void or(unsigned int x, unsigned int y){
    puts("\nHasil :");
    Bits(x);
    Bits(y);
    puts("Bitwise inclusive OR operator | adalah");
    Bits(x | y);    
}

void xor(unsigned int x, unsigned int y){
    puts("\nHasil :");
    Bits(x);
    Bits(y);
    puts("Bitwise exclusive OR operator ^ adalah");
    Bits(x ^ y);
}

void hapusData(int which){
    char name[50];
    printf("Data siapa yang ingin kamu hapus : "); scanf(" %50[^\n]", &name);
    for(int i=0; i<mhs.total; i++){
        if(strcmp(name, mhs.nama[i])==0){
            if(which==hapusDataBio){
                strcpy(mhs.nama[i], mhs.nama[mhs.total-1]); strcpy(mhs.nama[mhs.total-1], "");
                strcpy(mhs.nim[i], mhs.nim[mhs.total-1]); strcpy(mhs.nim[mhs.total-1], "");
                strcpy(mhs.gender[i], mhs.gender[mhs.total-1]); strcpy(mhs.gender[mhs.total-1], "");
                strcpy(mhs.kota[i], mhs.kota[mhs.total-1]); strcpy(mhs.kota[mhs.total-1], "");
                strcpy(mhs.umur[i], mhs.umur[mhs.total-1]); strcpy(mhs.umur[mhs.total-1], "");
            }
            else if(which==hapusDataNilai){
                mhs.skor.KonsPro[i] = mhs.skor.KonsPro[mhs.total-1]; mhs.skor.KonsPro[mhs.total-1] = 0;
                mhs.skor.SisDig[i] = mhs.skor.SisDig[mhs.total-1]; mhs.skor.SisDig[mhs.total-1] = 0;
                mhs.skor.Fisika[i] = mhs.skor.Fisika[mhs.total-1]; mhs.skor.Fisika[mhs.total-1] = 0;
                mhs.skor.Kalkulus[i] = mhs.skor.Kalkulus[mhs.total-1]; mhs.skor.Kalkulus[mhs.total-1] = 0;
                mhs.skor.Stats[i] = mhs.skor.Stats[mhs.total-1]; mhs.skor.Stats[mhs.total-1] = 0;
            }
        }
        else if((strcmp(name, mhs.nama[i])==0) && (strcmp(name, mhs.nama[mhs.total])==0)) {
            if(which==hapusDataBio){
                strcpy(mhs.nama[i], "");
                strcpy(mhs.nim[i], "");
                strcpy(mhs.gender[i], "");
                strcpy(mhs.kota[i], "");
                strcpy(mhs.umur[i], "");
            }
            else if(which==hapusDataNilai){
                mhs.skor.KonsPro[i] = 0;
                mhs.skor.SisDig[i] = 0;
                mhs.skor.Fisika[i] = 0;
                mhs.skor.Kalkulus[i] = 0;
                mhs.skor.Stats[i] = 0;
            }
        }

    }
    mhs.total--;
}

void sortList(int by){
    for(int h=0; h<mhs.total; h++){
        for(int i=0; i<mhs.total-1-h; i++){
            if((strcmpWithNull(mhs.nama[i], mhs.nama[i+1])>0) && by==byName){
                swapStr(mhs.nama[i], mhs.nama[i+1]); swapStr(mhs.nim[i], mhs.nim[i+1]); swapStr(mhs.gender[i], mhs.gender[i+1]); swapStr(mhs.kota[i], mhs.kota[i+1]); swapStr(mhs.umur[i], mhs.umur[i+1]); swapInt(mhs.skor.KonsPro[i], mhs.skor.KonsPro[i+1]); swapInt(mhs.skor.SisDig[i], mhs.skor.SisDig[i+1]);  swapInt(mhs.skor.Fisika[i], mhs.skor.Fisika[i+1]);  swapInt(mhs.skor.Kalkulus[i], mhs.skor.Kalkulus[i+1]);  swapInt(mhs.skor.Stats[i], mhs.skor.Stats[i+1]); 
            }
            else if((strcmpWithNull(mhs.nim[i], mhs.nim[i+1])>0) && by==byNim){
                swapStr(mhs.nama[i], mhs.nama[i+1]); swapStr(mhs.nim[i], mhs.nim[i+1]); swapStr(mhs.gender[i], mhs.gender[i+1]); swapStr(mhs.kota[i], mhs.kota[i+1]); swapStr(mhs.umur[i], mhs.umur[i+1]); swapInt(mhs.skor.KonsPro[i], mhs.skor.KonsPro[i+1]); swapInt(mhs.skor.SisDig[i], mhs.skor.SisDig[i+1]);  swapInt(mhs.skor.Fisika[i], mhs.skor.Fisika[i+1]);  swapInt(mhs.skor.Kalkulus[i], mhs.skor.Kalkulus[i+1]);  swapInt(mhs.skor.Stats[i], mhs.skor.Stats[i+1]); 
            }
            else if((strcmpWithNull(mhs.umur[i], mhs.umur[i+1])>0) && by==byUmur){
                swapStr(mhs.nama[i], mhs.nama[i+1]); swapStr(mhs.nim[i], mhs.nim[i+1]); swapStr(mhs.gender[i], mhs.gender[i+1]); swapStr(mhs.kota[i], mhs.kota[i+1]); swapStr(mhs.umur[i], mhs.umur[i+1]); swapInt(mhs.skor.KonsPro[i], mhs.skor.KonsPro[i+1]); swapInt(mhs.skor.SisDig[i], mhs.skor.SisDig[i+1]);  swapInt(mhs.skor.Fisika[i], mhs.skor.Fisika[i+1]);  swapInt(mhs.skor.Kalkulus[i], mhs.skor.Kalkulus[i+1]);  swapInt(mhs.skor.Stats[i], mhs.skor.Stats[i+1]); 
            }
        }
    }
}

void swapStr(char *str1, char *str2) {
    char temp[20];
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
}

void swapInt(int int1, int int2) {
    int temp;
    temp = int1;
    int1 = int2;
    int2 = temp;
}

int strcmpWithNull(char *str1, char *str2){
    if (str2[0] == '\0')
        return -1;
    return strcmp(str1, str2);
}

int openBioFile(){
    printf("Masukkan direktori file txt : "); scanf("%s", dirBio);
    FILE *txt = fopen(dirBio, "r");

    if (txt == NULL) {
		printf("no such file.");
		return 0;
	}
    else{
        int recordTotal = 0;
        char filechar[40], chr;
        chr = getc(txt);

        while (chr != EOF) {
            if (chr == '\n') {
                recordTotal = recordTotal + 1;
            }
            chr = getc(txt);
        }
        mhs.total = recordTotal;
        rewind(txt);
        for(int i=0; i<mhs.total; i++){
            fscanf(txt, "%*s%s%s%s%s%s", mhs.nama[i], mhs.nim[i], mhs.gender[i], mhs.kota[i], mhs.umur[i]);
        }
    }
    return 0;
}