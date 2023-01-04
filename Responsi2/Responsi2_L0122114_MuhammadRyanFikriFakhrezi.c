/*
Nama    : Muhammad Ryan Fikri Fakhrezi
NIM     : L0122114
Kelas   : C
Angkatan: 2022
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
unsigned int total=0;
int blank=1;

//deklarasi array of struct yang berguna sebagai media penyimpanan sementara data mahasiswa
typedef struct personal{
    char nama[30];
    char nim[10];
    float IPK;
    char gender[10];
}person;
person student[1000];

//fungsi untuk bersih-bersih terminal untuk multi platform
void clear_screen(){
    #ifdef _WIN32 //jika OS yang digunakan merupakan windows, maka clear_screen akan menggunakan system("cls")
        system("cls"); 
    #else //jika OS yang digunakan selain windows, maka clear_screen akan menggunakan system("clear")
        system("clear");
    #endif
}

/*============================================================bagian ngotak-ngatik structure========================================================*/

//fungsi ini digunakan untuk menukar isi antara dua variabel string
void swapStr(char *str1, char *str2) {
    char temp[20];
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
}

//fungsi ini digunakan untuk mengurutkan struct berdasarkan nama, algoritma yang digunakan adalah bubble sort
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
    sortList(); //setiap fungsi printData dipanggi, fungsi ini akan selalu memanggil fungsi sortList untuk mengurutkan data berdasarkan alfabet
    printf("%3s %-30s%-10s%-10s%-3s\n", "No.", "Nama", "NIM", "Gender", "IPK");
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
        printf("%.2d. %-30s%-10s%-10s%-.2f\n", (i+1),student[i].nama, student[i].nim, student[i].gender, student[i].IPK);
    }
}

//fungsi yang digunakan untuk menambahkan data secara manual kedalam struct
void addData(){
    unsigned int new;
    int current;
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

//fungsi yang digunakan untuk menghapus data yang diinginkan dari struct
void deleteData(){
    char del[50];
    int found;
    printf("Masukkan NIM yang datanya ingin kamu hapus : "); scanf(" %[^\n]", &del);
    for(int i=0; i<total; i++){                     //program melakukan for loop terhadap seluruh struct
        if(strcmp(del, student[i].nim)==0){         //jika ditemukan kecocokan antara NIM siswa dengan NIM yang dimaksud
            float temp;                             //maka data siswa yang bersangkutan akan dihapus
            for(int j=i; j<total; j++){             //dengan cara data siswa yang terletak disetelahnya akan dicopy ke lokasi dirinya
                strcpy(student[j].nama, student[j+1].nama); strcpy(student[j].nim, student[j+1].nim); strcpy(student[j].gender, student[j+1].gender); 
                temp = student[j].IPK;
                student[j].IPK=student[j+1].IPK;
                student[j].IPK=temp;
            }
            total--;    //setelah data dihapus, maka nilai total akan dikurangi satu
            printf("Data berhasil dihapus :)\n");
            found=1;    //dan mengubah nilai found menjadi satu supaya if dibawah tidak dijalankan
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

//fungsi ini digunakan untuk membersihkan seluruh struct dengan cara mengisi seluruh struct dengan data kosong
void clearArray(){
    for(int i=0; i<total; i++){
        strcpy(student[i].nama, ""); strcpy(student[i].nim, ""); strcpy(student[i].gender, ""); student[i].IPK=0; 
    }
    blank=1;
    total=0;
}

//fungsi ini digunakan untuk mengedit isi struct
void editData(){
    char changeStr[30];
    float changeNum;
    char nim[10];
    int found=0;
    enum editBio{
        Nama = 1,
        NIM,
        Gender,
        Ipk,
    };
    int which;
    printf("================= EDIT BIO ====================\n");
    printf("Masukkan NIM mahasiswa : "); scanf(" %[^\n]", &nim);
    for(int i=0; i<total; i++){                             //disini metode yang digunakan serupa dengan fungsi deleteData()
        if(strcmp(nim, student[i].nim)==0){
            printf("1. Nama\n2. NIM\n3. Gender\n4. IPK\nApa yang ingin diedit : "); scanf("%d", &which);
            switch (which)
            {
            case Nama:
                printf("Bagaimana seharusnya tertulis : "); scanf(" %[^\n]", &changeStr);
                strcpy(student[i].nama, changeStr);
                break;
            case NIM:
                printf("Bagaimana seharusnya tertulis : "); scanf("%s", &changeStr);
                strcpy(student[i].nim, changeStr);
                break;
            case Gender:
                printf("Bagaimana seharusnya tertulis (L/P) : "); scanf("%s", &changeStr);
                strcpy(student[i].gender, changeStr);
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
    if((strcmp(nim, student[total-1].nim)!=0&&found==0)){
        printf("Data mahasiswa tidak ditemukan!!!\n");
    }
    printf("Tekan ENTER untuk kembali ke menu...");
    while(getchar() != '\n');
    getchar();
    clear_screen();
}

/*=============================================bagian  file handling .dat=================================================*/
static char dirDat[100];
//fungsi dibawah digunakan untuk mengimport data dari file .dat yang sebelumnya dibuat oleh program ini
//jika dianalogikan dengan ms office, fungsi ini serupa dengan fitur open
void openDataDat(){
    FILE *database;
    printf("=================== IMPORT DAT ======================\n");
    printf("Masukkan direktori dan nama file .dat yang ingin diimport\nContoh : D:\\konspro\\praktikum\\student.txt\nCatatan : secara default file .dat akan disimpan di lokasi yang sama dengan file .c ini\n"); scanf(" %[^\n]", &dirDat);
    database = fopen(dirDat, "rb+");
    if (database != NULL){
        printf("%3s %-30s%-10s%-10s%-3s\n", "No.", "Nama", "NIM", "Gender", "IPK");
        while(fread(&student[total], sizeof(person), 1, database) == 1 ) {
            printf("%.2d. %-30s%-10s%-10s%-.2f\n", (total+1), student[total].nama, student[total].nim, student[total].gender, student[total].IPK);
            total++;
        }
        printf("Data berhasil diimport dari %s :)\n", dirDat);
    }
    else{
        printf("Tidak ada direktori semacam itu :(\n");
        blank=1;
    }
    fclose(database);
    printf("Tekan ENTER untuk kembali ke menu...");
    while(getchar() != '\n');
    getchar();
    clear_screen();
}

//fungsi dibawah ini digunakan untuk menyimpan data dalam bentuk binary ke file .dat
//jika dianalogikan dengan ms office, fungsi ini serupa dengan fitur save as
void saveDataDat(){
    FILE *database;
    printf("Masukkan direktori dan nama file .dat yang anda inginkan\nContoh : D:\\konspro\\praktikum\\student.dat\nCatatan : secara default file .dat akan disimpan di lokasi yang sama dengan file .c ini\n"); scanf(" %[^\n]", &dirDat);
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

//fungsi ini digunakan untuk mengupdate file binary yang telah dibuat sebelumnya
//jika dianalogikan dengan ms office, fungsi ini serupa dengan fitur save
void updateDataDat(){
    FILE *database;
    database = fopen(dirDat, "w");
    if (database != NULL){
        fwrite(student, sizeof(person), total, database); 
        printf("Data di %s telah berhasil diupdate\n", dirDat);
    }
    else{
        printf("Anda belum save file .dat sama sekali, apanya yang mau diupdate :)\n");
    }
    fclose(database);
    printf("Tekan ENTER untuk kembali ke menu...");
    while(getchar() != '\n');
    getchar();
    clear_screen();
}

/*============================================ bagian file handling file .txt =====================================*/
static char dirTxt[100];
//fungsi ini digunakan untuk mengimport data dari file .txt yang sebelumnya dibuat oleh program ini
//jika dianalogikan dengan ms office, fungsi ini serupa dengan fitur open
void openDataTxt(){
    FILE *txtfile;
    int new;
    printf("=================== IMPORT TXT ======================\n");
    printf("Masukkan direktori dan nama file .txt yang anda ingin import\nContoh : D:\\konspro\\praktikum\\student.txt\nCatatan : secara default file .txt terletak di lokasi yang sama dengan file .c ini\n"); scanf(" %[^\n]", &dirTxt);
    txtfile = fopen(dirTxt, "r");
    if(txtfile!=NULL){
        char chr = getc(txtfile);
        while (chr != EOF)
        {
            if (chr == '\n')
                {
                    new++;
                }
            chr = getc(txtfile);
        }
        rewind(txtfile);
        char none[5];
        fseek(txtfile, 61, SEEK_SET );
        for (int i=total; i<total+new; i++) {
            fscanf(txtfile, "%3s %29[^\n] %s %s %f\n", none, student[i].nama, student[i].nim, student[i].gender, &student[i].IPK);
        }
        total=total+new;
        printData();
        printf("Data berhasil diimport dari %s :)\n", dirTxt);
    }
    else{
        printf("Tidak ada direktori semacam itu :(\n");
        blank=1;
    }
    fclose(txtfile);
    printf("Tekan ENTER untuk kembali ke menu...");
    while(getchar() != '\n');
    getchar();
    clear_screen();
}

//fungsi ini digunakan untuk menyimpan struct dalam file teks
//jika dianalogikan dengan ms office, fungsi ini serupa dengan fitur save as
void saveDataTxt(){
    FILE *txtfile;
    printf("=================== SAVE TXT ======================\n");
    printf("Masukkan direktor dan nama file .txt yang anda inginkan\nContoh : D:\\konspro\\praktikum\\student.txt\nCatatan : secara default file .txt akan disimpan di lokasi yang sama dengan file .c ini\n"); 
    scanf(" %[^\n]", &dirTxt);
    txtfile = fopen(dirTxt, "w+");
    if(txtfile!=NULL){
        fprintf(txtfile, "%3s %-30s%-10s%-10s%-3s\n", "No.", "Nama", "NIM", "Gender", "IPK");
        for (int i=0; i<total; i++) {
            fprintf(txtfile, "%.2d. %-30s%-10s%-10s%-.2f\n", (i+1),student[i].nama, student[i].nim, student[i].gender, student[i].IPK);
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

//fungsi ini digunakan untuk mengupdate file teks
//jika dianalogikan dengan ms office, fungsi ini serupa dengan fitur save
void updateDataTxt(){
    FILE *txtfile;
    txtfile = fopen(dirTxt, "w");
    if(txtfile!=NULL)
    {
        fprintf(txtfile, "%3s %-30s%-10s%-10s%-3s\n", "No.", "Nama", "NIM", "Gender", "IPK");
        for (int i=0; i<total; i++)
        {
            fprintf(txtfile, "%.2d. %-30s%-10s%-10s%-.2f\n", (i+1),student[i].nama, student[i].nim, student[i].gender, student[i].IPK);
        }
        printf("Data di %s telah berhasil diupdate :)\n", dirTxt);
    }
    else
    {
        printf("Anda belum save file .txt sama sekali, apanya yang mau diupdate :)\n");
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
        "\t|1. Import data dari file .dat", "\t|7. Update student.dat\t|",
        "\t|2. Import data dari file .txt", "\t|8. Update student.txt\t|",
        "\t|3. Menambah data", "\t\t|9. Save as student.dat\t|",
        "\t|4. Edit data", "\t\t\t|10. Save as student.txt|",
        "\t|5. Hapus data", "\t\t\t|0. Keluar dari program\t|",
        "\t|6. Bersihkan struct",
        "\t|Apa yang ingin kamu lakukan : "); scanf("%d", &choice);
        clear_screen();
        if(choice==0){
            break;
        }
        switch (choice)
        {
        case importDat: blank=0;                    openDataDat();  break;
        case importTxt: blank=0;                    openDataTxt();  break;
        case add:       blank=0;                    addData();      break;
        case edit:                  printData();    editData();     break;
        case delete:                printData();    deleteData();   break;
        case cls:       blank=1;                    clearArray();   break;
        case updateDat:             printData();    updateDataDat();break;
        case updateTxt:             printData();    updateDataTxt();break;
        case saveDat:                               saveDataDat();  break;
        case saveTxt:                               saveDataTxt();  break;
        default:
            printf("Opsi tidak diketahui!!!");
            break;
        }
    }
    printf("Terimakasih sudah menggunakan program saya :)");
}
