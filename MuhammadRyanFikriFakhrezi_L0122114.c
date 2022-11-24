#include <stdio.h>
#include <string.h>

//fungsi pangkat
float pangkat(float num, float kali) {
    if(kali==1) {
        return num; //semua bilangan dipangkatkan 1 hasilnya adalah bilangan itu sendiri
    }
    else if(kali == 0) {
        return 1; //semua bilangan dipangkatkan 0 hasilnya 0
    }
    else {
        return num * pangkat(num, kali-1);
    }
}

//fungsi faktorial
float faktorial(float num) {
    if(num == 1){
        return 1; //untuk stop recursion
    }
    else {
        return num * faktorial(num-1);
    }
}

int main() {

    //deklarasi variabel
    float num;
    float kali;
    char opt[]="c";
    char again[]="y";

    //pakai while loop supaya programnya bisa di restart
    while (strcmp(again, "y")==0){ //program diulang setiap again bernilai y
        printf("apa yang ingin kamu cari (a. pangkat, b. faktorial) :"); 
        scanf("%s", opt); //input memilih antara 2 fungsi
        printf("masukkan angka :");
        scanf("%f", &num); //input huruf
        if(strcmp(opt, "a")==0){ //if jika user memasukkan input a
            printf("angkanya di pangkat berapa : "); //meminta input tambahan 
            scanf("%f", &kali); //input tambahan angkanya di pangkat berapa
            printf("hasil pangkatnya adalah : %f\n", pangkat(num, kali)); //menampilkan hasil pangkat
        }
        else if(strcmp(opt, "b")==0){ //if jika user memasukkan input b
            printf("hasil faktorial adalah : %f\n", faktorial(num)); //menampilkan hasil faktorial
        }
        else { //jika user memasukkan opsi selain 1 dan 2
            printf("opsi tidak dikenal !!!\n");
        }
        printf("apakah anda ingin mengulangi (y/n) : "); //menanyakan apakah user ingin me-restart program ini
        scanf("%s", again); //input variabel again, jika user memasukkan y maka program akan dimulai ulang
    }
    printf("terimakasih telah menggunakan program saya"); //end code
}