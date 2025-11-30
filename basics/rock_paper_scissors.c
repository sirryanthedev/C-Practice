#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    int rock = 1;
    int paper = 2;
    int scissors = 3;
    int user_choice = 0;

    printf("*** ROCK PAPER SCISSORS ***\n\n");
    printf("Enter your choice: ");
    scanf("%d", &user_choice);

    printf("\n");

    switch (user_choice){
    case 1:
        printf("You chose ROCK!\n\n");
        break;
    case 2:
        printf("You chose PAPER!\n\n");
        break;
    case 3:
        printf("You chose SCISSORS!\n\n");
        break;
    default:
        printf("Input should be 1, 2 or 3");
        return 1;
        break;
    }

    srand(time(NULL));
    int min = 1;
    int max = 3;
    int computer_choice = (rand() % (max - min + 1)) + min;

    switch(computer_choice){
        case 1:
            printf("Computer chose ROCK!\n\n");
            break;
        case 2:
            printf("Computer chose PAPER!\n\n");
            break;
        case 3:
            printf("Computer chose SCISSORS!\n\n");
            break;
    }

    if(user_choice == computer_choice){
        printf("It's a tie.\n");
    }
    else if(user_choice == 1 && computer_choice == 2){
        printf("You lose!\n");
    }
    else if(user_choice == 1 && computer_choice == 3){
        printf("You win!\n");
    }
    else if(user_choice == 2 && computer_choice == 1){
        printf("You win!\n");
    }
    else if(user_choice == 2 && computer_choice == 3){
        printf("You lose!\n");
    }
    else if(user_choice == 3 && computer_choice == 1){
        printf("You lose!\n");
    }
    else if(user_choice == 3 && computer_choice == 2){
        printf("You win!\n");
    }

    return 0;
}