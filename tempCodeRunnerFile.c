#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <process.h>
void signalHandler();

int i;
int line;
int main( void ){
    printf("I'll keep counting number\n");
    printf("Process ID : %d\n", getpid());
    start:
    signal(SIGINT, signalHandler);
    sleep(1);
    printf("%4d", i);
    i++;
    line++;
    if (line % 10 == 0) {
        puts("");
        line=0;
    }
    goto start;
}

void signalHandler(){
    write(STDOUT_FILENO, "\nHey, you can't stop me :)\n", 30);
    line=0;
}