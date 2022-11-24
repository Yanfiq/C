#include <stdio.h>
struct mahasiswa {
    char *nama;
    char *nim;
    struct nilai *nilaiptr;
};
struct nilai {
    int *uts;
    int *uas;
    int *nilaiakhir;
};

int main(void) 
{
    struct mahasiswa maba;

    maba.nama = "Ryan";
    maba.nim = "L0122114";
    printf("%s%s%s", maba.nama, " dengan NIM ", maba.nim);
    maba.nilaiptr->uas = 
}