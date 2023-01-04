#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//deklarasi fungsi
int kelaz(int *tada_ptr, int *gktada_ptr);
int more(int *tada_ptr, unsigned int *add_ptr);

int main(){
    time_t t; //variabel untuk menyimpan time_t
    srand ((unsigned) time(&t));
    int tada;
    int gktada = 0;
    int *tada_ptr = &tada;
    int *gktada_ptr = &gktada;
    printf("Berapa soal algoritmaru yang diterima saat ini : ");
    scanf("%d",&tada); //program meminta input dari user yang digunakan sebagai titik awal
    printf("Total soal : %d\n", tada);
    while(1){ //program menggunakan while(1) untuk menciptakan infinity loop, yang nanti akan break apabila kondisi dalam if tercapai
        printf("Berapa soal yang kamu sudah kerjakan : ");
        scanf("%d", &gktada);
        unsigned int add = rand() % 7;
        unsigned int *add_ptr = &add;
        kelaz(&tada, &gktada);
        if(tada <= 0) { 
            break; //fungsi if untuk menghentikan loop
        } //catatan, "kenapa gk pakai while loop aja dengan syarat gktada<=tada ?", karena kalau pakai itu
          //nanti printf di bagian bawah while akan tetap diprint, sehingga wagu, awalnya mau saya taruh diatas
          //aja printf-nya, tapi sayangnya keliatannya wagu juga, akhirnya saya jadikan while-nya always true
          //kemudian membuat fungsi if untuk keluar dari while loop, mohon maaf kalau ternyata ada jalan lain
          //untuk mengimplementasikan ini, dikarenakan keterbatasan pengetahuan + waktu, jadi begini saja
        more(&tada, &add);
        printf("Sayang sekali anda belum dapat menyelesaikannya\n");
        printf("total soal sekarang karena evaluasi : %d\n", tada);
    }
    printf("Selamat, anda telah menyelesaikan osprodi");
}

int kelaz(int *tada_ptr, int *gktada_ptr) { //pendefinisian fungsi kelaz()
    *tada_ptr = *tada_ptr - *gktada_ptr;
}
int more(int *tada_ptr, unsigned int *add_ptr) { //pendefinisian fungsi more()
    *tada_ptr = *tada_ptr + *add_ptr;
}