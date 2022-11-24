#include <stdio.h>
#include <stdlib.h>

int main()
{

    unsigned int d1;
    unsigned int d2;
    unsigned int langkah;
    srand(d1);
    srand(d2);
    d1 = rand()%6 + 1;
    d2 = rand()&6 +1;
    langkah = d1+d2;
    printf("total dadu adalah %u\n", &langkah);
    
    if(langkah==12) {
        langkah += d1+d2;
        printf("anda maju &u\n");
    }
    else {
        printf("anda maju %u\n", &langkah);
    }
}