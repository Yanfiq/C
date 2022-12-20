#include<stdio.h>

int looping();

struct data {
    char NIK[30];
    int nomor;
};


int main() {
    FILE *e;
    int d;
    struct data j;

    while ((d=looping()) !=4) {
        switch(d) {
            case 1:
                printf("masukkan NIK peserta:");
            scanf("%s", j.NIK);
            e=fopen("NIK peserta", "w");

            if (e !=NULL) {
                fprintf(e, "%s\n", j.NIK);
                fclose(e);
                printf("sukses");
            }

            break;

            case 2: 
            if ((e=fopen("NIK peserta", "r"))==NULL) {
                printf("Error: File tidak ada!");
            }

            while(fgets(j.NIK, sizeof(j.NIK), e)) {
                printf("%s\n", j.NIK);
            }

            fclose(e);
            break;

            case 3: if((e=fopen("NIK peserta", "rb+"))==NULL) {
                puts("file tidak ditemukan");
            }

            else {
                struct data h;
                printf("masukkan nomor file terakhir:");
                scanf("%d", &h.nomor);

                    printf("masukkan NIK peserta:");
                    fscanf(stdin, "%d", &h.NIK);
                    fseek(e, (h.nomor - 1)*sizeof(struct data), SEEK_SET);
                    fwrite(&h, sizeof(struct data), 1, e);

                fclose(e);
            }

            break;
            
            default:
            printf("tidak sesuai petunjuk yang tersedia");
            break;


        }
    }
}

int looping() {
    int menu=0;
    printf("\n masukkan pilihan\n"
        "1-membuat file kembali\n"
        "2-membaca file file kembali\n"
        "3-menambah file kembali\n"
        "4-mengakhiri program\n");
    scanf("%d", &menu);
    return menu;
}