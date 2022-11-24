#include <stdarg.h> 
#include <stdio.h>

int average(int i, ...);

int main(int argc, int argv[]) {
    printf("%s%d; %s%d; %s%d; %s%d\n\n",
        "w = ", &argv[1], "x = ", &argv[2], "y = ", &argv[3], "z = ", &argv[4]);
    printf("%s%.3f\n%s%.3f\n%s%.3f\n",
        "The average is ", average(4, &argv[1], &argv[2], &argv[3], &argv[4]));
} 


int average(int i, ...) {
    int total = 0;
    va_list ap;

    va_start(ap, i);

    for (int j = 1; j <= i; ++j) {
    total += va_arg(ap, int);
    } 

    va_end(ap);
    return total / i;
}