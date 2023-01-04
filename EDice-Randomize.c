#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10 // Maximum size of array

int Random(int min, int max){
    return min + (rand() % max);
}

int main()
{
    time_t t;
    srand((unsigned) time(&t));
    int i = 0;
    
    do{
        unsigned int d1 = Random(1, 6);
        unsigned int d2 = Random(1, 6);
        unsigned int total = d1 + d2;
        printf("%d, %d, %d\n", d1, d2, total);
        
        if(total == 12){
            total += Random(1, 6) + Random(1, 6);
            printf("Anda maju %d langkah\n", total);
            i = 2;
        }
        else{
            printf("Anda maju %d langkah\n", total);
        }
        
        int a;
    printf("Input : "); scanf("%d", &a);
    int n[a];
    
    printf("%s%8s\n", "Element", "Value");
    for(size_t i = 0; i < a; i++){
        n[i] = i * 3;
        printf("%7zu%8d\n", i, n[i]);
    }
    }while(i < 1);
}