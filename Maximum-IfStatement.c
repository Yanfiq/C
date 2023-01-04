#include <stdio.h>
int max;
int a;
int b;
int main(void)
{
    printf("masukkan 3 angka yang akan dicari nilai tertingginya : ");
    scanf("%d %d %d", &max, &a, &b);
    if(a>max){
        max = a;
    }
    if(b>max){
        max = b;
    }
    printf("%d", max);
}