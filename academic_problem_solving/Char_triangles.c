#include <stdio.h>

int main(){

    // (ex. char triangle) program which outputs formatted triangle of n rows of chosen characters where n is the number inputted by the user

    char character; // initialization - variables          
    int number;
    int n;

    // branch/label
    begin:
    printf("Enter a number (1 - 8): ");
    scanf("%d", &number);

    // if condition not met, branch to begin - else, just ignore this block
    if (number < 1 || number > 8){
        printf("Invalid input, please try again...\n");
        goto begin;
    }

    // width of the lowest row (row with most characters)
    int max_width = (number * 2) - 1;

    printf("Enter a character: ");
    scanf(" %c", &character);
    printf("\n");

    for (int i = 1; i <= number ; i++){
        // amount of characters per row
        n = 2 * i - 1;                                             

        // printing spaces
        int spaces = (max_width - n) / 2;
        for (int s = 0; s < spaces ; s++){
            printf(" ");
        }
        
        // printing the characters
        for (int counter = 0; counter < n; counter++){
            printf("%c", character);
        }
        printf("\n"); // at the end of each row: print a newline
    }

    return 0;
    }