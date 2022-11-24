#include <stdio.h>
#include <string.h>



long long int bjorka_leak[100];
int bjorka_leak_count = 0;
int phone_num_change();
int phone_num_add();

int main() {
    int i;
    printf("########## WELCOME TO BJORKANESIAN ##########\n");
    printf("How many people with leaked phone number : ");
    scanf("%d", &bjorka_leak_count);
    for (i = 0; i < bjorka_leak_count; i++) {
        printf("Enter the phone number with the country code (example : 62879767343) : ");
        scanf("%lli", &bjorka_leak[i]);
    }
    puts("");
    printf("##### BJORKA'S LEAKED PHONE NUMBERS #####\n");
    for (i = 0; i < bjorka_leak_count; i++) {
        printf("%d: %lli\n", (1+i), bjorka_leak[i]);
    }
    printf("#########################################\n");
    puts("");
    while (1) {
        char operation[1] = "a";
        long long int change;
        long long int line;

        printf("#### OPERATION ####\na. See the current list\nb. Edit the existing phone number\nc. Add more phone number\nd. Exit this program\nWhat do you want to do (don't use capital letter) : ");
        scanf("%s", operation);
        printf("###################\n");
        puts("");
        if (strcmp(operation, "a")==0) {
            printf("##### BJORKA'S LEAKED PHONE NUMBERS #####\n");
            for (i = 0; i < bjorka_leak_count; i++) {
                printf("%d: %lli\n", (i + 1), bjorka_leak[i]);
            }
            printf("#########################################\n");
            puts("");
        }
        else if (strcmp(operation, "b")==0) {
            printf("#### MENU TO EDIT AN EXISTING PHONE NUMBER ####\n");
            printf("Which number is wrong : ");
            scanf("%lli", &line);
            printf("How it should be written : ");
            scanf("%lli", &change);
            phone_num_change(bjorka_leak, line, change);
            printf("###############################################\n");
            puts("");
        } 
        else if (strcmp(operation, "c")==0) {
            printf("#### MENU TO ADD A NEW PHONE NUMBER ####\n");
            printf("Enter the phone number : ");
            scanf("%lli", &change);
            phone_num_add(change);
            printf("########################################\n");
            puts("");
        }
        else if (strcmp(operation, "d")==0) {
            break;
        }
        else {
            printf("unknown operation");
            puts("");
            break;
        }
    }
    printf("##### BJORKA'S LEAKED PHONE NUMBERS #####\n");
    for (i = 0; i < bjorka_leak_count; i++) {
        printf("%d: %lli\n", (i + 1), bjorka_leak[i]);
    }
    printf("#########################################\n");
    printf("ps : it's a joke, don't take it seriously");
}

int phone_num_change(long long int bjorka_leak[100], long long int line, long long int change) {
    int i;
    for (i=0; i<bjorka_leak_count; i++) {
        if(bjorka_leak[i+1] == line) {
            bjorka_leak[i+1] = change;
        }
    }
}

int phone_num_add(long long int change) {
    bjorka_leak[bjorka_leak_count] = change;
    bjorka_leak_count = bjorka_leak_count + 1;
}