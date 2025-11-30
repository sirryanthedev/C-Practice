#include <stdio.h>
#include <math.h>
#include <string.h>

int main(){

    // Compound interest calculator
    
    float principal = 0.0f;
    float rate = 0.0f;
    int years = 0;
    int times_compounded = 0;
    float total = 0.0f;
    char currency = '\0';

    printf("Compound Interest Calculator\n");

    printf("Enter the principal (p): ");
    scanf("%f", &principal);

    getchar();

    printf("Enter the currency as a symbol: ");
    scanf("%c", &currency);

    printf("Enter the rate (r) as a percentage: ");
    scanf("%f", &rate);
    rate /= 100;

    printf("Enter the # years (t): ");
    scanf("%d", &years);

    printf("Enter the # of times compounded per year (n): ");
    scanf("%d", &times_compounded);

    total = principal * pow(1 + rate/times_compounded, years*times_compounded);

    printf("After %d year/s, the total will be %c%.2f", years, currency, total);

    return 0;
}