#include <stdio.h>

float kell(float y);
float y;
int main(void)
{
    printf("masukkan jari-jari lingkaran : ");
    scanf("%f", &y);
    printf("keliling lingkaran tersebut adalah %f", kell(y));
}

float kell(float y)
{
    return 22*y*2/7;
}