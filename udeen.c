#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

unsigned int total;
char namaFile[100];

void listData();
void buatData();
void tampilkanData();
void editData();
void gantiNama();
void hapusFile();

typedef struct mahasiswa
{
    char nama[50], prodi[30], nim[10], kelamin[10], angkatan[10];
} data;
data input[50];

void sort(char *string1, char *string2);
void sort(char *string1, char *string2)
{
    char temp[20];
    strcpy(temp, string1);
    strcpy(string1, string2);
    strcpy(string2, temp);
}

void listData()
{
    for (int a = 0; a < total; a++)
    {
        for (int b = 0; b < total - 1 - a; b++)
        {
            if (strcmp(input[b].nama, input[b + 1].nama) > 0)
            {
                sort(input[b].nama, input[b + 1].nama);
                sort(input[b].prodi, input[b + 1].prodi);
                sort(input[b].nim, input[b + 1].nim);
                sort(input[b].kelamin, input[b + 1].kelamin);
                sort(input[b].angkatan, input[b + 1].angkatan);
            }
        }
    }
}

void buatData()
{
    FILE *saveAs;
    int banyak;

    system("cls");
    puts("==== Input Data ====");
    printf("Banyak Data\t: ");
    scanf("%u", &banyak);

    for (int i = total; i < total + banyak; i++)
    {
        printf("\n-- Data %d --\n", i + 1);
        printf("Nama\t\t: ");
        scanf("%s", &input[i].nama);
        printf("Prodi Studi\t: ");
        scanf("%s", &input[i].prodi);
        printf("NIM\t\t: ");
        scanf("%s", &input[i].nim);
        printf("Jenis Kelamin\t: ");
        scanf("%s", &input[i].kelamin);
        printf("Tahun Masuk\t: ");
        scanf("%s", &input[i].angkatan);
    }
    total += banyak;
    listData();

    printf("\nNama File(.bin): ");
    scanf("%s", namaFile);
    saveAs = fopen(namaFile, "wb");
    if (saveAs != NULL)
    {
        fwrite(input, sizeof(data), total, saveAs);
        fclose(saveAs);
        printf("Data is already saved in %s\n", namaFile);

        printf("\nPress any key to menu..");
        getch();
        system("cls");
    }
    else
    {
        printf("\nFailed to save data to %s\n", namaFile);
        printf("\nPress any key to menu..");
        getch();
        system("cls");
    }
}

void tampilkanData()
{
    FILE *openFile;
    char namaFile[100];

    system("cls");
    printf("Nama File(.bin): ");
    scanf("%s", namaFile);

    openFile = fopen(namaFile, "rb");
    if (openFile != NULL)
    {

        listData();
        puts("================================ Rekap Data ================================");
        printf("%3s%-15s%-20s%-15s%-15s%9s\n", "No.", "Nama", "Program Studi", "NIM", "Kelamin", "Angkatan");
        puts("============================================================================");
        while (fread(&input[total], sizeof(data), 1, openFile) == 1)
        {
            // for (int i = 0; i < total; i++)
            //{
            printf("%.2d.%-15s%-20s%-15s%-15s%9s\n", (total + 1), input[total].nama, input[total].prodi, input[total].nim, input[total].kelamin, input[total].angkatan);
            //}
            total++;
        }

        printf("\nPress any key to menu..");
        getch();
        system("cls");
        fclose(openFile);
    }
    else
    {
        printf("\nFile %s not found.\nCheck the file name and try again.\n", namaFile);
        printf("\nPress any key to menu..");
        getch();
        system("cls");
    }
}

void editData()
{
    FILE *change;
    char ubah[10], namaa[50];
    int choice, get = 0;

    enum editData
    {
        nama = 1,
        prodi,
        nim,
        kelamin,
        angkatan,
    };

    system("cls");
    printf("Nama File(.bin): ");
    scanf("%s", namaFile);
    printf("Cari Nama\t: ");
    scanf("%s", &namaa);

    for (int i = 0; i < total; i++)
    {
        if (strcmp(namaa, input[i].nama) == 0)
        {
            printf("1. Ubah Nama\n2. Ubah Program Studi\n3.Ubah NIM\n4. Ubah Jenis Kelamin\n5. Ubah Tahun Masuk");
            scanf("%s", &choice);
            printf("Ubah -> ");
            scanf("%s", &ubah);

            switch (choice)
            {
            case nama:
                strcpy(input[i].nama, ubah);
                break;
            case prodi:
                strcpy(input[i].prodi, ubah);
                break;
            case nim:
                strcpy(input[i].nim, ubah);
                break;
            case kelamin:
                strcpy(input[i].kelamin, ubah);
                break;
            case angkatan:
                strcpy(input[i].angkatan, ubah);
                break;
            }
            printf("Data is already saved in %s\n", namaFile);
            get = 1;

            printf("\nPress any key to menu..");
            getch();
            system("cls");
        }
    }
    if ((strcmp(namaa, input[total - 1].nama) != 0 && get == 0))
    {
        printf("\nFile %s not found.\nCheck the file name and try again.\n", namaFile);
        printf("\nPress any key to menu..");
        getch();
        system("cls");
    }
}

void gantiNama()
{
    int code;
    char namaFileLama[20], namaFileBaru[20];

    system("cls");
    puts("==== Ganti Nama File ====");
    printf("Nama File Lama\t: ");
    scanf("%s", namaFileLama);
    printf("Nama File Baru\t: ");
    scanf("%s", namaFileBaru);

    code = rename(namaFileLama, namaFileBaru);
    if (code == 0)
    {
        printf("The file %s has been changed to %s\n", namaFileLama, namaFileBaru);

        printf("\nPress any key to menu..");
        getch();
        system("cls");
    }
    else
    {
        printf("\nFailed to save data %s to %s\nCheck the file name and try again.\n", namaFileLama, namaFileBaru);
        printf("\nPress any key to menu..");
        getch();
        system("cls");
    }
}

void hapusFile()
{
    int code;
    char namaFile[20];

    system("cls");
    puts("==== Hapus File ====");
    printf("Nama File\t: ");
    scanf("%s", namaFile);

    code = remove(namaFile);
    if (code == 0)
    {
        printf("The file %s has been deleted.\n", namaFile);

        printf("\nPress any key to menu..");
        getch();
        system("cls");
    }
    else
    {
        printf("\nCannot delete file %s\nCheck the file name and try again.\n", namaFile);
        printf("\nPress any key to menu..");
        getch();
        system("cls");
    }
}

int main()
{
    enum opsiMenu
    {
        buat = 1,
        tampilkan,
        edit,
        ganti,
        hapus,
    };
    int choice;
    do
    {
        printf("==== Menu ====");
        printf("\n1. Buat Data");
        printf("\n2. Tampilkan Data");
        printf("\n3. Edit Data");
        printf("\n4. Ganti Nama File");
        printf("\n5. Hapus File");
        printf("\n6. Keluar");
        printf("\nPilih: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case buat:
            buatData();
            break;
        case tampilkan:
            tampilkanData();
            break;
        case edit:
            editData();
            break;
        case ganti:
            gantiNama();
            break;
        case hapus:
            hapusFile();
            break;
        }
    } while (choice != 6);
    return 0;
}