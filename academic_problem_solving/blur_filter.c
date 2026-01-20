#include <stdio.h>
#include <stdbool.h>

#define DIM 5

int in_bounds(int i, int j);
int calc_average(int kernel_size, int i, int j, int array[DIM][DIM]);
void blur(int kernel_size, int array[DIM][DIM]);
void print_square_matrix(int matrix[DIM][DIM]);

int main(){
    // user defined square matrix (NxN)
    int matrix[DIM][DIM] = {{10, 10, 10, 10, 10},
                       {10, 10, 10, 10, 10},
                       {10, 10, 10, 10, 10},
                       {10, 10, 10, 10, 10},
                       {10, 10, 10, 10, 10}};  

    int kernel_size = 0;

    // keep asking for input until a valid number (3-5-7) is entered
    while (true){
        printf("Enter a number (3 - 5 - 7): ");

        scanf("%d", &kernel_size);

        if (kernel_size == 3 || kernel_size == 5 || kernel_size == 7){
            break;
        }
    }

    if ((kernel_size % 2 == 0) || kernel_size > DIM){
        puts("The kernel size must be less than the dimension, and it should be odd...");
        return 1;
    }

    blur(kernel_size, matrix);
    print_square_matrix(matrix);

    return 0;
}

int in_bounds(int i, int j){
    return ((0 <= i) && (i < DIM)) && ((0 <= j) && (j < DIM));
}

int calc_average(int kernel_size, int i, int j, int array[DIM][DIM]){
    int n_elements = 0;
    int sum = 0;
    int delta = kernel_size / 2;

    for (int k = -delta; k <= delta; k++){
        for (int l = -delta; l <= delta; l++){
            if (in_bounds(k + i, l + j)){
                sum += array[k + i][l + j];
                n_elements += 1;
            }
        }
    }
    return sum / n_elements;
}

void blur(int kernel_size, int array[DIM][DIM]){
    int temp[DIM][DIM];

    for (int i = 0; i < DIM; i++){
        for (int j = 0; j < DIM; j++){
            temp[i][j] = calc_average(kernel_size, i, j, array);
        }
    }

    for (int i = 0; i < DIM; i++){
        for (int j = 0; j < DIM; j++){
            array[i][j] = temp[i][j];
        }
    }
}

void print_square_matrix(int matrix[DIM][DIM]){
    for (size_t i = 0; i < DIM; i++){
        for (size_t j = 0; j < DIM; j++){
            printf("%d ", matrix[i][j]);
        }
        puts("");
    }
}