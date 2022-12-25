#include <stdio.h>
#include <stdlib.h>
#include <string.h>
unsigned int total;
int blank=1;

typedef struct personal{
    char nama[26];
    char nim[10];
    float IPK;
    char gender[10];
}person;
person student[1000];

//bersih-bersih terminal untuk multi platform
void clear_screen(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

//ngotak-ngatik structure
int strcmpWithNull(char *str1, char *str2){
    if (str2[0] == '\0')
        return -1;
    return strcmp(str1, str2);
}
void swapStr(char *str1, char *str2) {
    char temp[20];
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
}
void sortList(){
    for(int h=0; h<total; h++){
        for(int i=0; i<total-1-h; i++){
            if(strcmp(student[i].nama, student[i+1].nama)>0){
                swapStr(student[i].nama, student[i+1].nama); swapStr(student[i].nim, student[i+1].nim); swapStr(student[i].gender, student[i+1].gender); 
                student[i].IPK=student[i].IPK+student[i+1].IPK;
                student[i+1].IPK = student[i].IPK-student[i+1].IPK;
                student[i].IPK = student[i].IPK-student[i+1].IPK;
            }
        }
    }
}

void printData(){
    sortList();
    printf("%3s %-26s%-10s%-10s%-3s\n", "No.", "Nama", "NIM", "Gender", "IPK");
    for (int i=0; i<total; i++) {
        if(strcmp(student[i].gender, "L")==0||strcmp(student[i].gender, "l")==0||strcmp(student[i].gender, "Laki-laki")==0){
            strcpy(student[i].gender, "Laki-laki");
        }
        else if(strcmp(student[i].gender, "P")==0||strcmp(student[i].gender, "p")==0||strcmp(student[i].gender, "Perempuan")==0){
            strcpy(student[i].gender, "Perempuan");
        }
        else{
            strcpy(student[i].gender, "Undefined");
        }
        printf("%.2d. %-26s%-10s%-10s%-.2f\n", (i+1),student[i].nama, student[i].nim, student[i].gender, student[i].IPK);
    }
}

void addData(){
    static unsigned int new;
    static int current;
    current=total;
    printData();
    printf("Berapa total mahasiswa yang ingin didata : "); scanf("%u", &new);
    clear_screen();
    for(int i=current; i<new+current; i++){
        printData();
        printf("======Siswa ke-%d=======\n", (i+1));
        printf("NIM\t\t: "); scanf("%s", &student[i].nim);
        printf("Nama\t\t: "); scanf(" %[^\n]", &student[i].nama);
        printf("Gender(L/P)\t: "); scanf("%s", &student[i].gender);
        printf("IPK\t\t: "); scanf("%f", &student[i].IPK);
        clear_screen();
        total++;
    }
}

void deleteData(){
    char del[50];
    int found;
    printf("Data siapa yang ingin kamu hapus : "); scanf(" %[^\n]", &del);
    for(int i=0; i<total; i++){
        if(strcmp(del, student[i].nama)==0){
            float temp;
            for(int j=i; j<total; j++){
                strcpy(student[j].nama, student[j+1].nama); strcpy(student[j].nim, student[j+1].nim); strcpy(student[j].gender, student[j+1].gender); 
                temp = student[j].IPK;
                student[j].IPK=student[j+1].IPK;
                student[j].IPK=temp;
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
    clear_screen();
}

void clearArray(){
    for(int i=0; i<total; i++){
        strcpy(student[i].nama, ""); strcpy(student[i].nim, ""); strcpy(student[i].gender, ""); student[i].IPK=0; 
    }
    blank=1;
    total=0;
}

void editData(){
    char changeStr[20];
    float changeNum;
    char name[20];
    int found=0;
    enum editBio{
        Nama = 1,
        NIM,
        Gender,
        Ipk,
    };
    int which;
    printf("================= EDIT BIO ====================\n");
    printf("Masukkan nama mahasiswa : "); scanf(" %[^\n]", &name);
    for(int i=0; i<total; i++){
        if(strcmp(name, student[i].nama)==0){
            printf("1. Nama\n2. NIM\n3. Gender\n4. IPK\nApa yang ingin diedit : "); scanf("%d", &which);
            switch (which)
            {
            case Nama:
                printf("Bagaimana seharusnya tertulis : "); scanf(" %[^\n]", &changeStr);
                strcpy(student[i].nama, changeStr);
                break;
            case NIM:
                printf("Bagaimana seharusnya tertulis : "); scanf(" %[^\n]", &changeStr);
                strcpy(student[i].nim, changeStr);
                break;
            case Gender:
                char MoF[1];
                printf("Bagaimana seharusnya tertulis (L/P) : "); scanf("%s", &MoF);
                if(strcmp(MoF, "L")==0){
                    strcpy(student[i].gender, "Laki-laki");
                } else if(strcmp(MoF, "P")==0){
                    strcpy(student[i].gender, "Perempuan");
                } else{
                    strcpy(student[i].gender, "Undefined");
                }
                break;
            case Ipk:
                printf("Bagaimana seharusnya tertulis : "); scanf("%f", &changeNum);
                student[i].IPK = changeNum;
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
    clear_screen();
}

//Bagian  file handling .dat
static char dirDat[100];
void openDataDat(){
    FILE *database;
    printf("Masukkan direktori file .dat yang ingin diimport\nContoh : D:\\konspro\\praktikum\\student.txt\n"); scanf(" %[^\n]", &dirDat);
    database = fopen(dirDat, "rb+");
    if (database != NULL){
        while(fread(&student[total], sizeof(person), 1, database) == 1 ) {
            printf("%.2d. %-26s%-10s%-10s%-.2f\n", (total+1), student[total].nama, student[total].nim, student[total].gender, student[total].IPK);
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
    clear_screen();
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
    clear_screen();
}

void updateDataDat(){
    FILE *database;
    database = fopen(dirDat, "w");
    if (database != NULL){
        fwrite(student, sizeof(person), total, database); 
        printf("Data di %s telah berhasil diupdate\n", dirDat);
    }
    else{
        printf("Error: anda belum membuka file apapun\n");
    }
    fclose(database);
    printf("Tekan ENTER untuk kembali ke menu...");
    while(getchar() != '\n');
    getchar();
    clear_screen();
}

//bagian file handling file .txt
static char dirTxt[100];
void openDataTxt(){
    FILE *txtfile;
    printf("=================== IMPORT TXT ======================\n");
    printf("Masukkan direktori file .txt yang anda inginkan\nContoh : D:\\konspro\\praktikum\\student.txt\nCatatan : secara default file .txt akan disimpan di lokasi yang sama dengan file .c ini\n"); scanf(" %[^\n]", &dirTxt);
    txtfile = fopen(dirTxt, "r");
    if(txtfile!=NULL){
        char chr = getc(txtfile);
        while (chr != EOF)
        {
            if (chr == 'n')
                {
                    total++;
                }
            chr = getc(txtfile);
        }
        rewind(txtfile);
        total--;
        char none[5];
        printf("%3s %-25s%-10s%-10s%-2s\n", "No.", "Nama", "NIM", "Gender", "IPK");
        fseek(txtfile, 57, SEEK_SET );
        for (int i=0; i<total; i++) {
            fscanf(txtfile, "%3s %25[^\n] %s %s %f\n", none, student[i].nama, student[i].nim, student[i].gender, &student[i].IPK);
            printf("%.2d. %-25s%-10s%-10s%-.2f\n", (i+1),student[i].nama, student[i].nim, student[i].gender, &student[i].IPK);
        }
        printf("Data berhasil diimport dari %s :)\n", dirTxt);
    }
    else{
        printf("Tidak ada direktori semacam itu :(\n");
    }
    fclose(txtfile);
    printf("Tekan ENTER untuk kembali ke menu...");
    while(getchar() != '\n');
    getchar();
    clear_screen();
}

void saveDataTxt(){
    FILE *txtfile;
    printf("=================== SAVE TXT ======================\n");
    printf("Masukkan direktori file .txt yang anda inginkan\nContoh : D:\\konspro\\praktikum\\student.txt\nCatatan : secara default file .txt akan disimpan di lokasi yang sama dengan file .c ini\n"); 
    scanf(" %[^\n]", &dirTxt);
    txtfile = fopen(dirTxt, "w+");
    if(txtfile!=NULL){
        fprintf(txtfile, "%3s %-27s%-10s%-10s%-2s\n", "No.", "Nama", "NIM", "Gender", "Umur");
        for (int i=0; i<total; i++) {
            fprintf(txtfile, "%.2d. %-27s%-10s%-10s%-.2f\n", (i+1),student[i].nama, student[i].nim, student[i].gender, student[i].IPK);
        }
        printf("Data berhasil diekspor ke %s :)\n", dirTxt);
    }
    else{
        printf("Tidak ada direktori semacam itu :(\n");
    }
    fclose(txtfile);
    printf("Tekan ENTER untuk kembali ke menu...");
    while(getchar() != '\n');
    getchar();
    clear_screen();
}

void updateDataTxt(){
    FILE *txtfile;
    txtfile = fopen(dirTxt, "w");
    if(txtfile!=NULL)
    {
        fprintf(txtfile, "%3s %-27s%-10s%-10s%-2s\n", "No.", "Nama", "NIM", "Gender", "IPK");
        for (int i=0; i<total; i++)
        {
            fprintf(txtfile, "%.2d. %-27s%-10s%-10s%-.2f\n", (i+1),student[i].nama, student[i].nim, student[i].gender, student[i].IPK);
        }
    }
    else
    {
        printf("Anda belum save file .txt samsek\n");
    }
    fclose(txtfile);
    printf("Tekan ENTER untuk kembali ke menu...");
    while(getchar() != '\n');
    getchar();
    clear_screen();
}

int main() {
    while(1){
        int choice;
        if(blank==0){
            printData();
        }
        enum option{
            exit, importDat, importTxt, add,
            edit, delete, cls, updateDat,
            updateTxt, saveDat, saveTxt,
        };
        printf("%s\n%s%s\n%s%s\n%s%s\n%s%s\n%s%s\n%s\n%s", 
        "\t======================== MENU ===========================",
        "\t|1. Import data dari file .dat", "\t|7. Update student.dat",
        "\t|2. Import data dari file .txt", "\t|8. Update student.txt",
        "\t|3. Menambah data", "\t\t|9. Save as student.dat",
        "\t|4. Edit data", "\t\t\t|10. Save as student.txt",
        "\t|5. Hapus data", "\t\t\t|0. Keluar dari program",
        "\t|6. Bersihkan struct",
        "\tApa yang ingin kamu lakukan : "); scanf("%d", &choice);
        clear_screen();
        if(choice==0){
            break;
        }
        switch (choice)
        {
        case importDat:
            blank=0;
            openDataDat();
            break;
        case importTxt:
            blank=0;
            openDataTxt();
            break;
        case add:
            blank=0;
            addData();
            break;
        case edit:
            editData();
            break;
        case delete:
            printData();
            deleteData();
            break;
        case cls:
            clearArray();
            break;
        case updateDat:
            updateDataDat();
            break;
        case updateTxt:
            updateDataTxt();
            break;
        case saveDat:
            saveDataDat();
            break;
        case saveTxt:
            saveDataTxt();
            break;
        default:
            printf("Opsi tidak diketahui!!!");
            break;
        }
    }
    printf("Terimakasih sudah menggunakan program saya :)");
}
