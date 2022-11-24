#include <stdio.h>
int main(void)
{
    unsigned int counter;
    for (counter=1; counter <= 10; ++counter){
        if((counter+3)%2==0){
            puts("genap");
        }
        else{
            puts("ganjil");
        }
        printf("nilai counter anda adalah = %d\n", counter);
    }
}