// (ex. 4_5_1)

#include <stdio.h>
#define N 3

void multiply_matrix(int matrix_1[N][N], int matrix_2[N][N], int res_matrix[N][N]);
void print_matrix(int matrix[N][N]);

int main(){

    int a[N][N] = {{1,2,3},
                   {2,3,4},
                   {5,3,2}};

    int b[N][N] = {{2,3,1},
                   {5,3,1},
                   {2,0,1}};

    int res[N][N];

    multiply_matrix(a, b, res);

    print_matrix(res);
    
    return 0;
}

void multiply_matrix(int matrix_1[N][N], int matrix_2[N][N], int res_matrix[N][N]){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            res_matrix[i][j] = 0;
            for (int k = 0; k < N; k++){
                res_matrix[i][j] += matrix_1[i][k] * matrix_2[k][j];
            }
        }
    }
}

void print_matrix(int matrix[N][N]){
    for (int row = 0; row < N; row++){
        for (int col = 0; col < N; col++){
            printf("%4d ", matrix[row][col]);
        }
        printf("\n");
    }
}