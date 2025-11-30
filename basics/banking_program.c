#include <stdio.h>

float check_balance(float number);

int main(){
    
    // banking program

    float account_balance = 0;
    int choice = 0;
    float operation_value = 0.0f;
    char currency = '$';

    printf("Enter your current balance: ");
    scanf("%f", &account_balance);
    printf("\n\n");

    while(choice != 4){
        operation_value = 0;
        printf("Select an option:\n\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n\n");

        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
    printf("\nInvalid input! Enter a number.\n\n");

    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF)
        ;

    choice = 0;
    continue;
}

        printf("\n");

        switch(choice){
                case 1:
                    printf("Your current balance: ");
                    printf("%c%.2f\n\n", currency, check_balance(account_balance));
                    break;
                case 2:
                    printf("Enter amount to deposit: ");
                    scanf("%f", &operation_value);
                    account_balance += operation_value;
                    printf("\nYou successfully deposited %c%.2f\n\n", currency, operation_value);
                    break;
                case 3:
                    printf("Enter the amount to withdraw: ");
                    scanf("%f", &operation_value);
                    if(operation_value > account_balance){
                        printf("\nInsufficient funds\n\n");
                        break;
                    }
                    else if(operation_value < 0){
                        printf("\nInvalid amount\n\n");
                        break;
                    }
                    else{
                        account_balance -= operation_value;
                        printf("\nYou successfully withdrew %c%.2f\n\n", currency, operation_value);
                        break;
                    }
                case 4:
                    printf("Quiting program...");
                    break;
                default:
                    printf("Input is invalid!\n\n");
                    break;
            }
    }
    printf("\n");
    printf("You exited the program successfully.");


    return 0;
}


float check_balance(float number){
    return number;
}