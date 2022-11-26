#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <process.h>
void signanHandler();
void sigillHandler();

int i;
int line;
int main( void ){
    printf("I'll keep counting number\nGood luck to stopping me\n");
    printf("Process ID : %d\n", getpid());
    start:
    signal(SIGINT, signanHandler);
    sleep(1);
    printf("%-4d", i);
    i++;
    line++;
    if (line % 10 == 0) {
        puts("");
        line=0;
    }
    goto start;
}

void signanHandler(){
    printf("\nHey, you can't stop me :)\n");
    line=0;
}

void sigillHandler(){
    printf("\nHey, that's illegal :)\n");
    line=0;
}
