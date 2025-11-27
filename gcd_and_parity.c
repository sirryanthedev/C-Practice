#include <stdio.h>
#include <ctype.h>

void parity_check(int num);             // function prototypes
void gcd(int num1, int num2);

int main(){
                                        // ex. 1.5.4 in book
    char option;
    int number;
    int number1;
    int number2;

    printf("\n\nSelect an option ...\n\n");
    printf("    e: even/odd\n");
    printf("    g: gcd\n");
    printf("    q: quit\n\n");

    scanf("%c", &option);
    option = tolower(option);           // to accept uppercase input as well
    
    switch(option){
        case 'e': 
                printf("\nEnter a number to check its parity: ");
                scanf("%d", &number);
                parity_check(number);
                break;
        case 'g': 
                printf("\nEnter 2 numbers to check their greatest common divider: ");
                scanf("%d %d", &number1, &number2);
                gcd(number1,number2);
                break;
        case 'q':
                printf("\nquitting...");
                return 0;
        default:
                printf("You did not enter a valid option (e - g - q)");
                return 1;
    }

    return 0;
    }
  
void parity_check(int num){
    (num % 2 == 0) ? printf("EVEN") : printf("ODD");
}

void gcd(int num1, int num2){
    
    int remainder;
    int max;
    int min;

    if (num1 > num2){
        max = num1;
        min = num2;
    }
    else {
        max = num2;
        min = num1;
    }
    
    while (1){
        remainder = max % min;

        if (remainder == 0){
            printf("The greatest common divider is %d", min);
            break;
        }

        else{
            max = min;
            min = remainder;
        }
    }
}