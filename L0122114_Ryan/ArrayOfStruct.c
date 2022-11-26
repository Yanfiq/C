#include <stdio.h>
#include <stdlib.h>
#include <string.h>
unsigned int total;
 
typedef struct personal{
    char nama[50];
    char nim[50];
    char umur[50];
    char kota[50];
    char gender[50];
}person;
person student[100];

void addData();
void saveDataDat();
void updateDataDat();
void openData();
void printData();
void editData();
void deleteData();
void clearArray();
void swapStr(char *str1, char *str2);
void sortList();
void exportTxt();
 
int main() {
    while(1){
        int choice;
        enum option{
            open=1,
            see,
            add,
            edit,
            delete,
            clear,
            update,
            saveTxt,
            saveDat,
            exit,
        };
        printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s", 
        "\t|1. Import data di student.dat",
        "\t|2. Lihat data",
        "\t|3. Masukkan data", 
        "\t|4. Edit data", 
        "\t|5. Hapus data",
        "\t|6. Hapus seluruh data dalam struct",
        "\t|7. Update student.dat",
        "\t|8. Simpan data dalam file student.txt", 
        "\t|9. Simpan data dalam file student.dat",
        "\t|0. Keluar dari program",
        "\tApa yang ingin kamu lakukan : "); scanf("%d", &choice);
        system("cls");
        if(choice==0){
            break;
        }
        switch (choice)
        {
        case open:
            openData();
            break;
        case see:
            printData();
            break;
        case add:
            addData();
            break;
        case edit:
            editData();
            break;
        case delete:
            deleteData();
            break;
        case clear:
            clearArray();
            break;
        case update:
            updateDataDat();
            break;
        case saveDat:
            saveDataDat();
            break;
        case saveTxt:
            exportTxt();
            break;
        default:
            printf("Opsi tidak diketahui!!!");
            break;
        }
    }
    printf("Terimakasih sudah menggunakan program saya :)");
}

void addData(){
    int new;
    printf("Berapa total mahasiswa yang ingin didata : "); scanf("%u", &new);
    for(int i=total; i<total+new; i++){
        printf("Nama : "); scanf(" %[^\n]", &student[i].nama);
        printf("NIM : "); scanf("%s", &student[i].nim);
        printf("Umur : "); scanf("%s", &student[i].umur);
        printf("Kota : "); scanf("%s", &student[i].kota);
        printf("Gender : "); scanf(" %[^\n]", &student[i].gender);
        system("cls");
    }
    total+=new;
    sortList();
}

void exportTxt(){
    FILE *txtfile;
    static char dir[100];
    printf("=================== EXPORT ======================\n");
    printf("Masukkan direktori file .txt yang anda inginkan\nContoh : D:\\konspro\\praktikum\\student.txt\nCatatan : secara default file .txt akan disimpan di lokasi yang sama dengan file .c ini\n"); scanf(" %[^\n]", &dir);
    txtfile = fopen(dir, "w");
    if(txtfile!=NULL){
        fprintf(txtfile, "%3s %-20s%-9s%-11s%-11s%-2s\n", "No.", "Nama", "NIM", "Gender", "Kota", "Umur");
        for (int i=0; i<total; i++) {
            fprintf(txtfile, "%.2d. %-20s%-9s%-11s%-11s%-2s\n", (i+1),student[i].nama, student[i].nim, student[i].gender, student[i].kota, student[i].umur);
        }
        fclose(txtfile);
        printf("Data berhasil diekspor ke %s :)\n", dir);
    }
    else{
        printf("Tidak ada direktori semacam itu :(\n");
    }
    printf("Tekan ENTER untuk kembali ke menu...");
    while(getchar() != '\n');
    getchar();
    system("cls");
}

static char dirDat[100];
void openData(){
    FILE *database;
    printf("Masukkan direktori file .dat yang ingin diimport\nContoh : D:\\konspro\\praktikum\\student.txt\n"); scanf(" %[^\n]", &dirDat);
    database = fopen(dirDat, "rb+");
    if (database != NULL){
        while(fread(&student[total], sizeof(person), 1, database) == 1 ) {
            printf("%.2d. %-20s%-9s%-11s%-11s%-2s\n", (total+1), student[total].nama, student[total].nim, student[total].gender, student[total].kota, student[total].umur);
            total++;
        }
        printf("Data berhasil diimport :)\n");
    }
    else{
        printf("Tidak ada direktori semacam itu :(\n");
    }
    fclose(database);
    printf("Tekan ENTER untuk kembali ke menu...");
    while(getchar() != '\n');
    getchar();
    system("cls");
}

void saveDataDat(){
    FILE *database;
    printf("Masukkan direktori file .dat yang anda inginkan\nContoh : D:\\konspro\\praktikum\\student.txt\nCatatan : secara default file .dat akan disimpan di lokasi yang sama dengan file .c ini\n"); scanf(" %[^\n]", &dirDat);
    database = fopen(dirDat, "w");
    if (database != NULL){
        fwrite(student, sizeof(person), total, database); 
        printf("Data berhasil disimpan di %s\n", dirDat);
    }
    else{
        printf("Tidak ada direktori semacam itu :(\n");
    }
    fclose(database);
    printf("Tekan ENTER untuk kembali ke menu...");
    while(getchar() != '\n');
    getchar();
    system("cls");
}

void updateDataDat(){
    FILE *database;
    database = fopen(dirDat, "w");
    if (database != NULL){
        fwrite(student, sizeof(person), total, database); 
        fclose(database);
        printf("Data di %s telah berhasil diupdate\n", dirDat);
    }
    else{
        printf("Error: anda belum membuka file apapun\n");
    }
    fclose(database);
    printf("Tekan ENTER untuk kembali ke menu...");
    while(getchar() != '\n');
    getchar();
    system("cls");
}

void printData(){
    sortList();
    printf("%3s %-20s%-9s%-11s%-11s%-2s\n", "No.", "Nama", "NIM", "Gender", "Kota", "Umur");
    for (int i=0; i<total; i++) {
        printf("%.2d. %-20s%-9s%-11s%-11s%-2s\n", (i+1),student[i].nama, student[i].nim, student[i].gender, student[i].kota, student[i].umur);
    }
    printf("Tekan ENTER untuk kembali ke menu...");
    while(getchar() != '\n');
    getchar();
    system("cls");
}

void sortList(){
    for(int h=0; h<total; h++){
        for(int i=0; i<total-1-h; i++){
            if(strcmp(student[i].nama, student[i+1].nama)>0){
                swapStr(student[i].nama, student[i+1].nama); swapStr(student[i].nim, student[i+1].nim); swapStr(student[i].gender, student[i+1].gender); swapStr(student[i].kota, student[i+1].kota); swapStr(student[i].umur, student[i+1].umur); 
            }
        }
    }
}

void deleteData(){
    char del[50];
    int found;
    printf("Data siapa yang ingin kamu hapus : "); scanf(" %[^\n]", &del);
    for(int i=0; i<total; i++){
        if(strcmp(del, student[i].nama)==0){
            for(int j=i; j<total; j++){
                strcpy(student[j].nama, student[j+1].nama); strcpy(student[j].nim, student[j+1].nim); strcpy(student[j].gender, student[j+1].gender); strcpy(student[j].kota, student[j+1].kota); strcpy(student[j].umur, student[j+1].umur); 
            }
            total--;
            sortList();
            printf("Data berhasil dihapus :)\n");
            found=1;
        }
        else if((strcmp(del, student[i].nama)!=0)&&(i==(total-1))&&found!=1){
            printf("Data mahasiswa tidak ditemukan :(\nPerhatikan penulisan nama!!!\n");
        }
    }
    printf("Tekan ENTER untuk kembali ke menu...");
    while(getchar() != '\n');
    getchar();
    system("cls");
}

void clearArray(){
    for(int i=0; i<total; i++){
        strcpy(student[i].nama, ""); strcpy(student[i].nim, ""); strcpy(student[i].gender, ""); strcpy(student[i].kota, ""); strcpy(student[i].umur, ""); 
    }
    total=0;
}

void swapStr(char *str1, char *str2) {
    char temp[20];
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
}

void editData(){
    char change[20];
    char name[20];
    int found=0;
    enum editBio{
        Nama = 1,
        NIM,
        Gender,
        Kota,
        Umur,
    };
    int which;
    printf("================= EDIT BIO ====================\n");
    printf("Masukkan nama mahasiswa : "); scanf(" %[^\n]", &name);
    for(int i=0; i<total; i++){
        if(strcmp(name, student[i].nama)==0){
            printf("1. Nama\n2. NIM\n3. Gender\n4. Kota\n5. Umur\nApa yang ingin diedit : "); scanf("%d", &which);
            printf("Bagaimana seharusnya tertulis : "); scanf(" %[^\n]", &change);
            switch (which)
            {
            case Nama:
                strcpy(student[i].nama, change);
                break;
            case NIM:
                strcpy(student[i].nim, change);
                break;
            case Gender:
                strcpy(student[i].gender, change);
                break;
            case Kota:
                strcpy(student[i].kota, change);
                break;
            case Umur:
                strcpy(student[i].umur, change);
                break;
            default:
                printf("Operasi tidak dikenali !!!");
                break;
            }
            printf("Data berhasil diedit :)\n");
            found=1;
        }
    }
    if((strcmp(name, student[total-1].nama)!=0&&found==0)){
        printf("Data mahasiswa tidak ditemukan!!!\n");
    }
    printf("Tekan ENTER untuk kembali ke menu...");
    while(getchar() != '\n');
    getchar();
    system("cls");
}