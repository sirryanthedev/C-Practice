#include <stdio.h>
#include <stdbool.h>

int main(){

    // (ex. 3.1.3) program to find minimum in an array of numbers (1 dimensional)

    int min;
    int numbers[] = {10,9,5,7,8};   // example array
    int size = sizeof(numbers) / sizeof(numbers[0]);
    bool first = true;

    for (int i = 0; i < size; i++){
        if (first){
            min = numbers[0];
            first = false;
        }
        if (numbers[i] < min){
            min = numbers[i];
        }
    }

    printf("minimum: %d\n", min);

    return 0;
}