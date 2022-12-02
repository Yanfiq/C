#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    system("d:");
    system("D:\\Tweaks\\outro\\computer-outro-fake-bsod\\fake-bsod-cmdver\\play.vbs");
    for (int i=12;i>=0;i--){
        printf("Windows left the chat in %d second", i);
        sleep(1);
        system("cls");        
    }
    system("D:\\Tweaks\\outro\\BluescreenSimulator.exe --win10 -e "":)"" -m1 ""Your PC is running perfectly fine with no problems whatsoever."" -m2 ""There are no updates pending, and it does not need to restart.\nEnjoy your day!"" -sc ""Fun code: ALL_IS_WELL"" -oq");
    for(int i=13; i>=0; i--){
        sleep(1);
    }
    system("shutdown -s -t 0");
    return(0);
}