#include <stdio.h>

int main(){

    // simple calculator which performs a mathematical operation between 2 numbers

    float first_number = 0.0f;
    float second_number = 0.0f;
    char operator = '\0';
    float result = 0.0f;

    printf("simple calculator\n\n");

    printf("Enter the first number: ");
    scanf("%f", &first_number);

    printf("Enter an operator (+ - * /): ");
    scanf(" %c", &operator);

    printf("Enter the second number: ");
    scanf("%f", &second_number);

    printf("\n");

    switch(operator){
        case '+':
            result = first_number + second_number;
            printf("The result is %.1f", result);
            break;
        case '-':
            result = first_number - second_number;
            printf("The result is %.1f", result);
            break;
        case '*':
            result = first_number * second_number;
            printf("The result is %.1f", result);
            break;
        case '/':
            result = first_number / second_number;
            printf("The result is %.1f", result);
            break;
        default:
            printf("You did not enter a valid input (+ - * /)");
            break;
    }

    return 0;
}