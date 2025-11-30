#include <stdio.h>
#include <math.h>

int factorial(int number); // function prototype for factorial

int main(){

    /*  (ex. 2.1.3)
    Computes the Taylor series expansion of e^x:

        e^x ≈ Σ (x^n / n!)  for n = 0 to 10

    The program evaluates this expression for x = 0.1, 0.2, ..., 1.0.
    */
    
    printf("(sum) or y = ∑ ((x^n) / n!) from n = 0 to n = 10; do this for every x ranging from 0.1 to 1.0\n\n");

    for (float i = 1; i <= 10; i++){

        float sum = 0;
        float x = i / 10;

        for (int n = 0; n <= 10; n++){

        sum += (pow(x,n)) / (float)factorial(n);

        }
        printf("For x = %.1f, sum = %f\n\n", x, sum);
    }
    return 0;
}

int factorial(int number){
    int result = 1;
    for (int i = 1; i <= number; i++){
        result *= i;
    }
    return result;
}