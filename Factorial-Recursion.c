 #include <stdio.h>

int angka;
int i;

int faktorial(int angka) {
    if(angka == 1){
        return 1;
    }
    else {
        return angka * faktorial(angka-1);
    }
}
int main(){
    printf("masukkan angka yang akan dicari faktorialnya : ");
    scanf("%d", &angka);
    printf("faktorial dari angka tersebut adalah %d", faktorial(angka));
}