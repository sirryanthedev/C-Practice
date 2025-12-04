#include <stdio.h> 

#define N 3 // amount of parameters per vector

void vector_product(float vector1[N], float vector2[N], float vector12[N]); // function prototype for Hadamard operation

int main(){ 
    
    // (ex. 4.3.3 - alternative solution) program which does Hadamard product of vectors

    float vector1[N] = {2,4,3}; // first vector
    float vector2[N] = {1,3,1}; // second vector
    float vector12[N] = {0};    // vector product/result
    
    vector_product(vector1, vector2, vector12); 
    
    printf("%s", "vector product: "); 
    
    // printing vector product values 
    for (int i = 0; i < N; i++){
        printf("%.2f ", vector12[i]); 
    } 

    // newline at the end 
    printf("\n"); 
    
    return 0; 
} 
    
void vector_product(float vector1[N], float vector2[N], float vector12[N]){
    for (int i = 0; i < N; i++){
        vector12[i] = vector1[i] * vector2[i];
    } 
}