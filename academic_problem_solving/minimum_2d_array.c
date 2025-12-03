#include <stdio.h>
#include <stdbool.h>

#define SIZE1D 3    // size of the first dimension of the array
#define SIZE2D 4    // size of the second dimension of the array

int main(){

    // program which outputs the minimum of a 2d array

    int min;
    int numbers[SIZE1D][SIZE2D] = {{3,4,5,11},{1,7,6,8},{18,2,9,12}};
    bool first = true;

    for (int i = 0; i < SIZE1D; i++){
        for (int j = 0; j < SIZE2D; j++){
            if (first){
                min = numbers[0][0];
                first = false;
            }
            if (numbers[i][j] < min){
                min = numbers[i][j];
            }
        }
    }

    printf("The minimum equals %d\n", min);

    return 0;
}