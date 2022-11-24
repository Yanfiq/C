//fig02_04.std::cin

#include <stdio.h>
int main (void)
{
    int panjang;
    int lebar;
    int tinggi;
    printf ("masukkan panjang\n");
    scanf ("%d", &panjang);
    printf ("masukkan lebar\n");
    scanf ("%d", &lebar);
    printf ("masukkan tinggi\n");
    scanf ("%d", &tinggi);

    if (panjang == lebar == tinggi)
    {
        printf ("benda tersebut merupakan kubus\n");
    }
    if (panjang > lebar)
    {
        printf ("benda tersebut merupakan balok\n");
    }
    else {
        printf("btw, baloknya aneh\n");
    }
    printf("omong-omong nih luas dan volumenya\n");
    int luas;
    int volume;
    luas = panjang * lebar * 2 + panjang * tinggi * 2 + lebar * tinggi * 2;
    printf ("luas balok tersebut adalah %d\n", luas);
    volume = panjang * lebar * tinggi;
    printf ("volume balok tersebut adalah %d\n", volume);
}