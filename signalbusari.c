#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <time.h>
void signalHandler( int signalVa1ue );

int main( void ){
    int i;
    int x;
    signal (SIGINT, signalHandler);
    srand(time(NULL));
    for (i=1; i<=100; ++i){
        x = 1 + rand() % 50;
        if(x==25){ 
            raise(SIGINT);
        }
        printf("%4d", i);
        if (i % 10 == 0) {
            printf("%s", "\n");
        }
    }
}

void signalHandler( int signalValue ){
    int response;
    printf("%s%d%s\n%s",
    "\nlnterrupt signal (", signalValue, ") received. ",
    "Do you wish to continue ( 1= yes or 2 = no)?");
    scanf("%d", &response);
    while ( response != 1 && response != 2){
        printf("%s", "(1=yes or 2=no)?");
        scanf("%d", &response);
    }
    if(response==1){
        signal(SIGINT, signalHandler);
    }
    else{
        exit(EXIT_SUCCESS);
    }
}