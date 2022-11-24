void printBioList(){
    puts("========================= BIO ============================");
    printf("%3s %-11s%-9s%-11s%-11s%-2s\n", "No.", "Nama", "NIM", "Gender", "Kota", "Umur");
    for(int i=0; i<mhs.total; i++){
        printf("%.2d. %-11s%-9s%-11s%-11s%-2s\n", (i+1), mhs.nama[i], mhs.nim[i], mhs.gender[i], mhs.kota[i], mhs.umur[i]);
    }
    puts("===========================================================");
}