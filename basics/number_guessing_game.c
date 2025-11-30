#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){

    // number guessing game - guess the randomly chosen number in your chosen in your chosen interval

    int x = 0;
    int y = 0;

    printf("*** NUMBER GUESSING GAME ***\n\n");
    printf("Create an interval [x,y]\n");

    printf("Define the lower end (x): ");
    scanf("%d", &x);

    printf("Define the upper end (y): ");
    scanf("%d", &y);

    if(x > y){
        printf("Input error: the lower end can't be greater than the higher end...");
        return 1;
    }

    printf("\n");
    printf("Let's start!\n\n");
    
    printf("Now to win, guess the random number within your chosen interval [%d,%d]\n\n", x, y);

    int min = x;
    int max = y;
    int guess = 0;
    srand(time(NULL));
    int rand_num = (rand() % (max - min + 1)) + min;
    int counter = 0;

    do{ 
        counter++;
        printf("take a guess %d - %d: ", x, y);
        scanf("%d", &guess);

        if(guess == rand_num){
            printf("\n");
            printf("Well done, you guessed the number!\n");
            printf("It was %d.\n", rand_num);
            break;
        }

        else if(guess < x || guess > y){
            printf("Guess within the defined interval...\n\n");
        } 

        else if(guess < rand_num){
            printf("Too low, try again.\n\n");
        }
        
        else if(guess > rand_num){
            printf("Too high, try again.\n\n");
        }   

    }while(guess != rand_num);

    if(counter == 1){
        printf("It took you %d try.\n", counter);
    }
    else{
        printf("It took you %d tries.\n", counter);
    }
    
    return 0;
}