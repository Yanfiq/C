#include <stdio.h>
int main(void) 
{
    int i=1000;
    int tahun=0;
    int z;

    while(tahun <= 10){
        tahun += 1;
        int z = i + (5/100)*i;
    }
    printf("total pinjaman setelah 10 tahun adalah %d\n", z);
    printf("%d", tahun);
}