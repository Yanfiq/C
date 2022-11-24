#include <stdio.h>
#include <string.h>

int main()
{
    float num1;
    float num2;
    float ans;
    char opt;
    char again[]= "y";
    printf("Selamat datang di calcunium\n");
    printf("\\calcunium adalah akronim dari calculator minimum\\\n");
    do {
        printf("Masukkan angka pertama : ");
        scanf("%f", &num1);
        printf("Masukkan angka kedua : ");
        scanf("%f", &num2);
        printf("Masukkan operasi (* / + -) : ");
        scanf("%s", &opt);
        switch(opt){
            case '*':
                ans = num2*num1;
                break;
            case '/':
                ans = num1/num2; 
                break;
            case '+':
                ans = num1+num2;
                break;
            case '-':
                ans = num1-num2;
                break;
            default:
                printf("gajelas cok");
        }
        printf("%f\n", ans);
        printf("apakah anda ingin mengulangi (y/n) : ");
        scanf("%s", again);
    } while (strcmp(again, "y")==0);
    printf("terimakasih telah menggunakan program saya");
}