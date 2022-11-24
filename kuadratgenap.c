#include <stdio.h>
#include <math.h>

int counter = 0;
void main()
{
    while(counter <= 20) {
        int z = pow(counter, 2);
        printf("%d\n", z);
        counter+=2;
    }
}
