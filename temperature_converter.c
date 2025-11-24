#include <stdio.h>

int main(){

    // temperature conversion program

    float temperature = 0.0f;
    char choice = '\0';

    printf("Temperature Conversion Program\n\n");
    printf("C. Celsius to Fahrenheit\n");
    printf("F. Fahrenheit to Celsius\n\n");
    printf("Make your choice (C or F): ");

    scanf(" %c", &choice);

    if(choice == 'C'){
        printf("Enter the temperature in Celsius: ");
        scanf("%f", &temperature);
        temperature = temperature * 1.8 + 32; 
        printf("The temperature in Fahrenheit equals %.1f", temperature);
    }

    else if(choice == 'F'){
        printf("Enter the temperature in Fahrenheit: ");
        scanf("%f", &temperature);
        temperature = (temperature - 32)/1.8;
        printf("The temperature in Celsius equals %.1f", temperature);
    }

    else{
        printf("You did not enter a valid input (C or F)");
    }

    return 0;
    }