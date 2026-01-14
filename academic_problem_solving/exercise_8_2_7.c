// (ex. 8_2_7)

#include <stdio.h>
#include <stdlib.h>
#define N 2

void multiply_matrix(int*** matrix_1, int*** matrix_2, int*** res_matrix);
void print_matrix(int*** matrix);
void deallocate(int*** matrix);
int** allocate();

int main(){

    // allocate memory dynamically for each (square) matrix[N][N]
    int** matrix_1 = allocate();
    int** matrix_2 = allocate();
    int** res_matrix = allocate();

    // fill first 2 matrices with some random values
    matrix_1[0][0] = 1;
    matrix_1[0][1] = 2;
    matrix_1[1][0] = 3;
    matrix_1[1][1] = 4;

    matrix_2[0][0] = 5;
    matrix_2[0][1] = 6;
    matrix_2[1][0] = 7;
    matrix_2[1][1] = 8;

    // output the first 2 matrices using self-created print_matrix function
    puts("matrix 1:");
    print_matrix(&matrix_1);
    puts("\n");

    puts("matrix 2:");
    print_matrix(&matrix_2);
    puts("\n");

    // output result of multiplication of the first 2 matrices using self_created functions
    puts("matrix 1 * matrix 2:");
    multiply_matrix(&matrix_1, &matrix_2, &res_matrix);
    print_matrix(&res_matrix);

    // deallocate all memory which we allocated dynamically on the heap
    deallocate(&matrix_1);
    deallocate(&matrix_2);
    deallocate(&res_matrix);
    
    return 0;
}

void multiply_matrix(int*** matrix_1, int*** matrix_2, int*** res_matrix){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            (*res_matrix)[i][j] = 0;
            for (int k = 0; k < N; k++){
                (*res_matrix)[i][j] += (*matrix_1)[i][k] * (*matrix_2)[k][j];
            }
        }
    }
}

void print_matrix(int*** matrix){
    for (int row = 0; row < N; row++){
        for (int col = 0; col < N; col++){
            printf("%4d ", (*matrix)[row][col]);
        }
        printf("\n");
    }
}

int** allocate(){
    int** matrix = calloc(N, sizeof(int*)); // reserve memory for outer matrix
    for (size_t i = 0; i < N; i++){
        matrix[i] = calloc(N, sizeof(int)); // reserve memory for N columns per row
    }
    return matrix;
}

void deallocate(int*** matrix){ // *** so we can modify the 2d-matrix
    for (size_t i = 0; i < N; i++){
        free((*matrix)[i]); // free each row of the matrix
    }
    free(*matrix); // free the outer matrix itself
    *matrix = NULL; // matrix still points to memory on heap, set it to NULL to avoid dangling pointer
}