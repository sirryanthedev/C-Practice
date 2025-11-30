#include <stdio.h>

int main(){

    // (ex. 1.6.3) program which counts from 1 to 12 and prints each number with its inverse

    printf(" n | 1/n\n");
    printf("------------\n");
    for (int i = 1; i <= 12; i++){
        float inverse = 1.0f/i;
        printf("%2d | %.5f\n", i, inverse);
    }

    return 0;
}