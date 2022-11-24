#include <stdio.h>

int siswa = 6;
const int nilai[6][10] = {{73, 52, 81, 67, 84, 42, 79, 85, 58, 92}, {75, 83, 69, 85, 56, 93, 82, 90, 97, 75}, {82, 76, 97, 94, 73, 87, 85, 66, 99, 63}, {75, 83, 97, 99, 64, 76, 87, 94, 46, 33}, {55, 63, 56, 84, 96, 93, 36, 25, 57, 93}, {95, 78, 55, 97, 94, 57, 35, 47, 38, 95}};
char murid[6][5] = {{"Anto"}, {"Siti"}, {"Tejo"}, {"Heru"}, {"Ryan"}, {"Alma"}};
int main(){
    int baris;
    int skor;
    printf("Name  1st   2nd   3rd   4th   5th   6th   7th   8th   9th   10th\n");
    for(baris=0; baris<siswa; baris++) {
        printf("%s   ", &murid[baris]);
        for(skor=0; skor<10; skor++){
            printf("%d    ", nilai[baris][skor]);
        }
        puts("");
    }
    puts("\n================================================================");
    printf("=============LOWEST AND HIGHEST SCORE FOR EACH TEST=============\n");
    printf("        1st   2nd   3rd   4th   5th   6th   7th   8th   9th   10th\n");    
    printf("Lowest  ");
    int lesson;
    for(lesson=0; lesson<10; lesson++){
        int low = 100;
        for(skor=0; skor<siswa; skor++){
            if(nilai[skor][lesson] < low) {
                low = nilai[skor][lesson];
        }
    }
    printf("%d    ", low);
    }
    puts("");
    printf("Highest ");
    for(lesson=0; lesson<10; lesson++){
        int high = 0;
        for(skor=0; skor<siswa; skor++){
            if(nilai[skor][lesson] > high) {
                high = nilai[skor][lesson];
        }
    }
    printf("%d    ", high);
    }
    puts("");
    puts("\n================================================================");
    printf("============LOWEST AND HIGHEST SCORE FOR EACH PERSON============\n");
    printf("      Lowest    Highest\n");
    for(baris=0; baris<siswa; baris++) {
        int low = 100;
        int high = 0;
        printf("%s    ", &murid[baris]);
        for(skor=0; skor<10; skor++){
            if(nilai[baris][skor]<low) {
                low = nilai[baris][skor];
            }
            if(nilai[baris][skor]>high) {
                high = nilai[baris][skor];
            }
        }
        printf("%2d", low);
        printf("%10d", high);
        puts("");
    }
    puts("\n================================================================");
    printf("=====================EACH PERSON'S AVERAGE======================\n");
    printf("Name    Average\n");
    for(baris=0; baris<siswa; baris++) {
        float sum = 0;
        float counter = 0;
        printf("%s     ", &murid[baris]);
        for(skor=0; skor<10; skor++){
            sum = sum + nilai[baris][skor];
            counter++;
        }
        float average = sum/counter;
        printf("%.2f\n", average);
    }
    puts("\n================================================================");
    printf("======================EACH TEST'S AVERAGE=======================\n");
    printf("       1st     2nd     3rd     4th     5th     6th     7th     8th     9th     10th\n");
    printf("Avg   ");
    for(lesson=0; lesson<10; lesson++){
        float sum = 0;
        float counter = 0;
        for(skor=0; skor<siswa; skor++){
            sum = sum + nilai[skor][lesson];
            counter++;
        }
        float average = sum/counter;
    printf("%.2f   ", average);
    }
}