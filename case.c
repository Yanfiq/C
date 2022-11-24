#include <stdio.h>
int main(void){
char nilai;
printf("masukkan nilaimu\n");
scanf("%s", &nilai);
        switch (nilai) {
            case 'A':
            case 'a':
                puts("nilaimu bagus");
                break;
            case 'B':
            case 'b':
                puts("nilaimu biasa aja");
                break;
            default:
                puts("nilaimu gajelas");
                break;
            }

}