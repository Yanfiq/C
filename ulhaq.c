//Mochammad Dhiya Ulhaq
//L0122095
//Kelas C

#include<stdio.h>

int detmatriks(int x[2][2]);            //deklrasasi fungsi detmatriks

int main(){
    int A[2][2];           //dekralasi variabel array untuk menyimpan angka
    int i,j,q;
    int m = 2;
    int n = 2;
    char opsi;
    char opsi2;

    for (int i ; i > -1; i++)           //Untuk fungsi pengulangan
{
    printf("===============================================\n");            //fungsi untuk menampilkan teks
    printf("            MATRIKS BERORDO 2 x 2\n");\
    printf("===============================================\n");
    printf("-----------------------------------------------\n");
    for(i = 0; i < m; i++){             //untuk fungsi pengulangan 
        for(j = 0; j < n; j++){
            printf("Masukkan Elemen Matriks (%d, %d) : ", i+1, j+1);            
            scanf("%3d", &A [i][j]);            //fungsi untuk memasukkan input ke variabel array
        }
    }
    printf("-----------------------------------------------\n");
    printf("\nMatriks 2 x 2 = \n\n");
    for(i = 0; i < m; i++){         //untuk fungsi pengulangan
        for(j = 0; j < n; j++){
            printf("%3d", A[i] [j]);
        }
    printf ("\n\n");
    }

    printf("Apakah Anda Ingin Mengubah Elemen Matriks? ");
    printf("\n( y / n ) : ");
    scanf("%s", &opsi);             //fungsi untuk memasukkan input ke variabel opsi

    switch (opsi)           //fungsi untuk menentukan user ingin mengganti elemen matriks
    {
    case 'y':               
        printf("Elemen Matriks Mana Yang Ingin Diubah?");
        printf("\nA(1,1)  B(1,2)");
        printf("\nC(2,1)  D(2,2)");
        printf("\nPilihan Anda (A / B / C / D): ");
        scanf("%s", &opsi2);            //fungsi untuk memasukkan input ke variabel opsi2
        switch (opsi2)              //fungsi untuk menentukan elemen matriks yang ingin diganti
        {
        case 'A':
            printf("Masukkan Elemen Baru: ");
            scanf("%d", &q);                //fungsi untuk memasukkan input ke variabel q
            A [0][0] = q;               //maka elemen array [0][0] akan diganti oleh input user
            printf("\nMatriks A = \n\n");
            for(i = 0; i < m; i++){             //untuk fungsi pengulangan
                for(j = 0; j < n; j++){
                printf("%3d", A[i] [j]);            //untuk menampilkan hasil perubahan
            }
            printf ("\n\n");
            }
            break;
        case 'B':
            printf("Masukkan Elemen Baru: ");
            scanf("%d", &q);            //fungsi untuk memasukkan input ke variabel q
            A [0][1] = q;           //maka elemen array [0][1] akan diganti oleh input user
            printf("\nMatriks A = \n\n");
            for(i = 0; i < m; i++){             //untuk fungsi pengulangan
                for(j = 0; j < n; j++){
                printf("%3d", A[i] [j]);            //untuk menampilkan hasil perubahan
            }
            printf ("\n\n");
            }
            break;
        case 'C':
            printf("Masukkan Elemen Baru: ");
            scanf("%d", &q);            //fungsi untuk memasukkan input ke variabel q
            A [1][0] = q;           //maka elemen array [1][0] akan diganti oleh input user
            printf("\nMatriks A = \n\n");
            for(i = 0; i < m; i++){         //untuk fungsi pengulangan
                for(j = 0; j < n; j++){
                printf("%3d", A[i] [j]);            //untuk menampilkan hasil perubahan
            }
            printf ("\n\n");
            }
            break;
        case 'D':
            printf("Masukkan Elemen Baru: ");
            scanf("%d", &q);            //fungsi untuk memasukkan input ke variabel q
            A [1][1] = q;           //maka elemen array [1][1] akan diganti oleh input user
            printf("\nMatriks A = \n\n");
            for(i = 0; i < m; i++){         //untuk fungsi pengulangan
                for(j = 0; j < n; j++){
                printf("%3d", A[i] [j]);            //untuk menampilkan hasil perubahan
            }
            printf ("\n\n");
            }
            break;
        default:
            printf("Input Salah Program Berhenti\n");           //Jika user salah menginput maka program berhenti
            break;
        }
        break;
    case 'n':           //case untuk switch line 42
            printf("\nMatriks A = \n\n");
            for(i = 0; i < m; i++){         //untuk fungsi pengulangan
                for(j = 0; j < n; j++){
                printf("%3d", A[i] [j]);            //untuk menampilkan hasil tanpa perubahan
            }
            printf ("\n\n");
            }
        break;
    default:
        printf("Input Salah Program Berhenti\n");           //Jika user salah menginput maka program berhenti
        break;
    }
    printf("Determinannya adalah %d\n", detmatriks(A));
    printf("-----------------------------------------------\n");
    printf("Ulang Program?");
    printf("\n( y / n ) : ");
    scanf("%s", &opsi2);            //Meminta input dari user

    switch (opsi2){
        case 'y':           //Jika 'y' maka program akan mengulang kembali
            i=2;
            break;
        case 'n':           //Jika 'n' maka program akan berhenti
            i=-2;
        break;
        default:
            printf("Input Salah Program Berhenti");         //Jika user salah menginput maka program berhenti
            return 0;
        }
    }
}

int detmatriks(int x[2][2]){
    return x[0][0] * x [1][1] - x[0][1] * x[1][0];          //fungsi untuk menghitung determinan matriks
}