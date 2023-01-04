//Fig. 3.6: fig03_06.c
//Class average program with counter-controlled iteration. 
#include <stdio.h>

//function main begins program execution 
int main( void )
{
    unsigned int counter; // number of grade to be entered next 
    int grade; //grade value 
    int total; // sum of grades entered by user 
    int average; // average of grades

    //initialization phase 
    total = 0; // initialize total 
    counter = 0; // initialize loop counter
    average = 0; //initialize average
    //processing phase
    while ( counter < 10 ) { //loop 10 times 
        printf("%s", "Enter grade: " ); //prompt for input 
        scanf( "%d", &grade ); // read grade from user
        total = total + grade; // add grade to total 
        counter = counter + 1; //increment counter }
        average = total / counter; //get the average score
    } //end while
    printf("your average score is %d\n", average); //print the average just in case
    printf("your score in total is %d\n", total); //print total score just in case
    printf("your lesson in total is %d\n", counter); //print the  counter just in case

    //if statement section
    if (average >= 85){
        printf("Your score is A");
    } else if (average >= 84){
        printf("Your score is A-");
    } else if (average >=79){
        printf("Your score is B+");
    } else if (average >=74){
        printf("Your score is B");
    } else if (average >=69){
        printf("Your score is C+");
    } else if (average >=64){
        printf("Your score is C");
    } else if (average >=59){
        printf("Your score is D");
    } else {
        printf("Your score is E");
    }

    while (grade != -1) {
        total += grade ;
    counter += 1;
    printf("%s", "enter grade, -1 to end : ");
    scanf("%d", &grade);
    }
    if(counter != 0){
        average = (float)total / counter;
        printf("class average is %.3f\n", average);
    }
}