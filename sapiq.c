//Nama  : Muhammad Syafiq Ibrahim
//NIM   : L0122116

#include <stdio.h>

void serangan(int *HP_ptr, int atk );//parameter
//Program Inti
int main(){
    int HP = 100;
    int atk,opsi;
    printf("HP Musuh : %d\n", HP);
//Pengulangan sampai target yang ditentukan
    for (int i; i > -1; i++){
//Pilihan senjata serta damage yang diberikan
        printf("Serang Musuh Dengan :\n");
        printf("1. Pedang [20]\n");
        printf("2. Kapak [25]\n");
        printf("3. Panah [15]\n");
        printf("4. Ultimate [100]\n");
        printf("Masukkan Jenis Serangan : ");
        scanf("%d",&opsi);
//Penerapan pointer untuk menyimpan HP musuh
    if (opsi == 1){
        serangan(&HP, 20);
    }
    if (opsi == 2){
        serangan(&HP, 25);
    }
    if (opsi == 3){
        serangan(&HP, 15);
    }
    if (opsi == 4){
        serangan(&HP, 100);
    }
    printf("\nHP Musuh Sekarang : %d\n", HP);
    if(HP<=0){
        printf("Musuh Mati\n");
        i=-2;
    }
    printf("Kamu Menang");
    return 0;
    }
}
void serangan(int *HP_ptr, int atk ){//fungsi mengurangi HP musuh
    *HP_ptr = *HP_ptr - atk;
}