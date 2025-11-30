#include <stdio.h>
#include <ctype.h>
#include <math.h>

void parity_check(int num);             // function prototypes
void gcd(int num1, int num2);
void add(float num1, float num2);
void subtract(float num1, float num2);
void multiply(float num1, float num2);
void divide(float num1, float num2);
float factorial(float number);
void special_divisors(int a, int b);

int main(){
    
    // (ex. 1.5.4) + (ex. 2.4.1)

    char option = '\0';
    int number = 0;
    int number1 = 0;
    int number2 = 0;
    float a = 0.0f;
    float b = 0.0f;

    printf("\n\nSelect an option ...\n\n");
    printf("    e: even/odd\n");
    printf("    g: gcd\n");

    printf("    a: addition\n");
    printf("    b: subtraction\n");
    printf("    m: multiplication\n");
    printf("    d: division\n");
    printf("    s: sinus\n");
    printf("    n: natural logaritm\n");
    printf("    r: square root\n");
    printf("    p: power\n");
    printf("    f: factorial\n");
    printf("    z: divisors of a which are less than b\n");

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
        case 'a':
                printf("\nEnter 2 numbers (a b): ");
                scanf("%f %f", &a, &b);
                add(a, b);
                break;
        case 'b':
                printf("\nEnter 2 numbers (a b): ");
                scanf("%f %f", &a, &b);
                subtract(a, b);
                break;
        case 'm':
                printf("\nEnter 2 numbers (a b): ");
                scanf("%f %f", &a, &b);
                multiply(a, b);
                break;
        case 'd':
                printf("\nEnter 2 numbers (a b): ");
                scanf("%f %f", &a, &b);
                divide(a, b);
                break;
        case 's':
                printf("\nEnter a number: ");
                scanf("%f", &a);
                printf("The sinus of %.1f is %.1f", a, sin(a));
                break;
        case 'n':
                printf("\nEnter a number: ");
                scanf("%f", &a);
                printf("The natural logarithm of %.1f is %.1f", a, log(a));
                break;
        case 'r':
                printf("\nEnter a number: ");
                scanf("%f", &a);
                printf("The square root of %.1f is %.1f", a, sqrt(a));
                break;
        case 'p':
                printf("\nEnter 2 numbers (a b): ");
                scanf("%f %f", &a, &b);
                printf("%.0f to the power of %.0f is %.0f", a, b, pow(a,b));
                break;
        case 'f':
                printf("\nEnter a number: ");
                scanf("%f", &a);
                printf("The factorial of %.1f is %.1f", a, factorial(a));
                break;
        case 'z':
                printf("\nEnter 2 numbers (a b): ");
                scanf("%f %f", &a, &b);
                special_divisors(a, b);
                break;
        case 'q':
                printf("\nquitting...");
                return 0;
        default:
                printf("You did not enter a valid option (e - g - a - b - m - d - s - n - r - p - f - z - q)");
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

void add(float num1, float num2){
    float result = num1 + num2;
    printf("%.4f + %.4f = %.4f", num1, num2, result);
}

void subtract(float num1, float num2){
    float result = num1 - num2;
    printf("%.4f - %.4f = %.4f", num1, num2, result);
}

void multiply(float num1, float num2){
    float result = num1 * num2;
    printf("%.4f * %.4f = %.4f", num1, num2, result);
}

void divide(float num1, float num2){
    float result = num1 / num2;
    printf("%.4f / %.4f = %.4f", num1, num2, result);
}

float factorial(float number){
    float result = 1;
    for (int i = 1; i <= number; i++){
        result *= i;
    }
    return result;
}

void special_divisors(int a, int b){
    // print divisors of a which are less than b
    for (int i = 2; i <= sqrt(a); i++){
        if ((a % i == 0) && i < b){
            printf("%d\n", i);
        }
    }
}