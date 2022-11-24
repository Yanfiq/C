#include <stdio.h>

int angka;
int pangkat;
int kali = 0;

int hasil(int angka; int pangkat)
{
    if(int pangkat == 0){
        return 1;
    }
    else{
        while(kali<=pangkat){
            angka = angka*angka;
        }
    }
    printf("%d", &angka);
}

