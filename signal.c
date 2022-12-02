#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <process.h>
void signalHandler();

int i;
int line;
int main( void ){
    printf("I'll keep counting number\nGood luck stopping me\n");
    printf("Process ID : %d\n", getpid());
    start:
    sleep(1);
    signal(SIGINT, signalHandler);
    printf("%-4d", i);
    i++;
    line++;
    if (line % 10 == 0) {
        puts("");
        line=0;
    }
    goto start;
}

void signalHandler(){
    signal(SIGINT, signalHandler);
    printf("\nHey, you can't stop me :)\n");
    line=0;
}