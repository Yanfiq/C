#include <stdio.h>
#include <signal.h>

void SignalFunc(int);

int main()
{
    signal(SIGABRT, SignalFunc);
    signal(SIGFPE, SignalFunc);
    signal(SIGILL, SignalFunc);
    signal(SIGINT, SignalFunc);
    signal(SIGSEGV, SignalFunc);
    signal(SIGTERM, SignalFunc);
    
    int c;
    
    Again:
    printf("Input : "); scanf("%d", &c);

    switch(c){
        case 1:
            raise(SIGABRT);
        break;
        case 2:
            raise(SIGFPE);
        break;
        case 3:
            raise(SIGILL);
        break;
        case 4:
            raise(SIGINT);
        break;
        case 5:
            raise(SIGSEGV);
        break;
        case 6:
            raise(SIGTERM);
        break;
    }
    goto Again;
}

void SignalFunc(int n){
    printf("This is ( %d ) signal\n", n);
}