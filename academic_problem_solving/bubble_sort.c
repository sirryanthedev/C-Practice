#include <stdio.h>

void sort(int numbers[], int size); // function prototype for sorting

int main(){

    // (ex. 3.1.3 alternative 1) bubble sort - program which sorts elements of an array from low to high

    int numbers[] = {7,5,1,3,8,2,4,6,0};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    sort(numbers, size);

    for (int i = 0; i < size; i++){
        printf("%d ", numbers[i]);
    }

    return 0;
}

// sort function
void sort(int numbers[], int size){

int swapped;

do{
    swapped = 0;
    for (int i = 0; i < size - 1; i++){
        if (numbers[i] > numbers[i + 1]){
            int temp = numbers[i];
            numbers[i] = numbers[i + 1];
            numbers[i + 1] = temp;
            swapped = 1;
        }
    }
    size--;
    }while (swapped);
}