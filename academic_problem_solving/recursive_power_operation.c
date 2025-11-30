#include <stdio.h>
#include <math.h>

double power(double x, int n);  // fuction prototype for recursive operation

int main(){

    // (ex. 2.2.1) program which computes x^n recursively

    double x = 2.0;
    int n = 4;

    printf("%.2f^%d = %.2f\n", x, n, power(x, n));

    return 0;
}

double power(double x, int n){
    if (n == 0){
        return 1;   // base case
    }
    return x * power(x, n-1);   // recursive step
}