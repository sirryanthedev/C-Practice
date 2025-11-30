#include <stdio.h>

#define ABS(a) ((a) < 0 ? -(a) : (a))   // macro to get absolute value of a number
#define MIN(a,b) ((a) < (b) ? a : b)    // macro to get the minimum of 2 numbers

int main(){

    // (ex. 2.3.3 - MACRO)

    int result = 3 + 2*MIN(9,4);
    printf("result: %d\n", result);

    int number = -10;
    printf("The absolute value of %d is %d\n", number, ABS(number));

    return 0;
}