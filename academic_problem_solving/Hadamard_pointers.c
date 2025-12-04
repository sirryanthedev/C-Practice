#include <stdio.h>

#define N 3 // amount of parameters per vector

void vector_product(float *vector1, float *vector2, float *vector12);

int main(){

    // (ex. 4.3.3) program which does Hadamard product of vectors using pointers

    float vector1[N] = {2,4,3}; // first vector
    float vector2[N] = {1,3,1}; // second vector
    float vector12[N] = {0};    // result vector

    vector_product(vector1, vector2, vector12);

    printf("%s", "vector product: ");

    // printing vector product values
    for (int i = 0; i < N; i++){
        printf("%.2f ", *(vector12 + i));
    }
    // newline at the end
    printf("\n");

    return 0;
}

void vector_product(float *vector1, float *vector2, float *vector12){
    for (int i = 0; i < N; i++){
            *(vector12 + i) = (*(vector1 + i)) * (*(vector2 + i));  // pointer arithmetic
        }
}