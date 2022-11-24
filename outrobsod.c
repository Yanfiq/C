#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    clock_t begin;
    double time_spent;
    unsigned int i;
    system("D:\\Tweaks\\outro\\computer-outro-fake-bsod\\fake-bsod-cmdver\\play.vbs");
    begin = clock();
    for (i=0;1;i++)
        {
        time_spent = (double)(clock() - begin) / CLOCKS_PER_SEC;
        if (time_spent>=10){
            system("D:\\Tweaks\\outro\\bsod.exe");
        }
        if (time_spent>=25.0)
            system("start shutdown -s -t 0");
        }
    return(0);
}