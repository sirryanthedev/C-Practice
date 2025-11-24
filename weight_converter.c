#include <stdio.h>

int main(){

    // weight converter program

    float weight = 0.0f;
    float new_weight = 0.0f;
    int choice = 0;

    printf("1. Kilograms to Pounds\n");
    printf("2. Pounds to Kilograms\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    if(choice == 1){
        printf("Enter the weight in kilogram/s: ");
        scanf("%f", &weight);
        new_weight = weight * 2.205;
        printf("%.1f kilogram/s equals %.1f pound/s\n", weight, new_weight);
    }

    else if(choice == 2){
        printf("Enter the weight in pounds: ");
        scanf("%f", &weight);
        new_weight = weight / 2.205;
        printf("%.1f pound/s equals %.1f kilogram/s\n", weight, new_weight);
    }

    else{
        printf("You did not enter a valid choice (1 or 2)\n");
    }
    return 0;
}