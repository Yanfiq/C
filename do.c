#include <stdio.h>
int main(void)
{
    unsigned int x = 1;
    for (int x > 1; x < 10; ++x) {
        if(x%2 != 0 && x>=5){
            printf("%u", &x);
        }
    }
}