#include <stdio.h>

void sort_num_array(int *ptrs[]); // function prototype

#define N 8 // max. number of elements in array

int main(){

    // (ex. 4.3.1) program which sorts an array of numbers without changing it

    int nums[N] = {5,1,3,4,2,0,7,6};    // example array with N elements (numbers)
    int *ptrs[N] = {0}; // initialized pointer array with length of N

    // assigning each item of the nums array to the pointers
    for (int i = 0; i < N; i++){
        ptrs[i] = &nums[i];
    }

    sort_num_array(ptrs);   // calling function to sort array of numbers (pointer array implementation)

    // print each item of the sorted nums array (ptrs/pointers array)
    for (int i = 0; i < N; i++){
        printf("\n%d\n", *ptrs[i]); 
    }

    return 0;
}

void sort_num_array(int *ptrs[]){
    int temp;
    int swapped;
    int size = N;

    // bubble sort implementation with pointer array
    do{
        swapped = 0;
        for (int i = 0; i < size - 1; i++){
            if (*ptrs[i] > *ptrs[i + 1]){
                temp = *ptrs[i];
                *ptrs[i] = *ptrs[i + 1];
                *ptrs[i + 1] = temp;
                swapped = 1;
            }
        }size--;
    }while (swapped);
}