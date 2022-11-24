#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char movie[100][50];
int movie_counter = 0;
char operation[1];
void start();
void menu();
void movies_edit();
void movies_add();
void movies_save();
void movies_list();

int main() {
    start();
    system("cls");
    while (strcmp(operation, "d")!=0) {
        movies_list();
        menu();
    }
    movies_list();
    return 0;
}

void start(){
    printf("===============LIST OF WISHLISTED MOVIES===============\n");
    printf("How many movies that you want to watch : ");
    scanf("%d", &movie_counter);
    for (int i = 0; i < movie_counter; i++) {
        printf("Enter the movie's title : ");
        scanf(" %50[^\n]", &movie[i]);
    }
    puts("");
}

void menu() {
    printf("======================= OPERATION =======================\na. Edit the wishlist\nb. Add more title\nc. save the list as .txt file\nd. Exit this program\nWhat do you want to do (don't use capital letter) : ");
    scanf("%s", &operation);
    system("cls");
    if (strcmp(operation, "a")==0) {
        movies_list();
        movies_edit();
    }
    else if (strcmp(operation, "b")==0) {
        movies_list();
        movies_add();
    }
    else if (strcmp(operation, "c")==0) {
        movies_list();
        movies_save();
    }
    else if (strcmp(operation, "d")==0) {
        system("cls");
    }
    else {
        movies_list();
        printf("unknown operation\n");
        printf("Press ENTER key to enter the menu...");
        while(getchar() != '\n');
        getchar();
        system("cls");
    }
}

void movies_list(){
    printf("====================== MOVIES LIST ======================\n");
    for (int i = 0; i < movie_counter; i++) {
        printf("%d: %s\n", (1+i), &movie[i]);
    }
    printf("=========================================================\n");
    puts("");
}

void movies_edit(){
    char change[50];
    int line;
    printf("========== MENU TO EDIT AN EXISTING TITLES ==========\n");
    printf("which line do you want to movies_edit : ");
    scanf("%d", &line);
    printf("How should it be written : ");
    scanf(" %50[^\n]", &change);
    strcpy(movie[line-1], change);
    printf("=====================================================\n");
    puts("");
    system("cls");
}

void movies_add(){
    char change[50];
    int line;
    printf("========== MENU TO ADD A NEW MOVIE'S TITLE ==========\n");
    printf("Enter the movie's title : ");
    scanf(" %50[^\n]", &change);
    strcpy(movie[movie_counter], change);
    movie_counter = movie_counter + 1;
    printf("=====================================================\n");
    puts("");
    system("cls");
}

void movies_save(){
    FILE *txtfile;
    char dir[50];
    printf("Enter the output directory without quote or double quote (example: E:\\cprogram\\movies.txt)\n");
    scanf("%s", dir);
    txtfile = fopen(dir, "w");
    if(txtfile == NULL) {
        printf("No such directory !!!\n");
        printf("Press ENTER key to enter the menu...");
        while(getchar() != '\n');
        getchar();
        system("cls");
    }
    else{
        fprintf(txtfile, "===================== MOVIES LIST =====================\n");
        for(int i=0; i<movie_counter; i++) {
            fprintf(txtfile, "%d: %s\n", (i+1), movie[i]);
        }
        fprintf(txtfile, "=======================================================\n");
        fclose(txtfile);
        printf("The movie wishlist is already saved in %s\n", dir);
        printf("Press ENTER key to enter the menu...");
        while(getchar() != '\n');
        getchar();
        system("cls");
    }
}