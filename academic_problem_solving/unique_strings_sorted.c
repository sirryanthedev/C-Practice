#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define N 8 // constant: max. amount (of strings in 2d array)
#define LEN 20 // constant: max length (of strings in 2d array)

void sort_string_array(char strings[N][LEN]);   // function prototypes
void show_uniques(char strings[N][LEN]);

int main(){

    // (ex. 3.2.5) program which prints unique strings of an array, sorted alphabetically
    
    char foods[N][LEN] = {"banana", "apple", "mango", "apple", "pear", "mango", "banana", "pear"};  // example array

    show_uniques(foods);

    return 0;
}

void sort_string_array(char strings[N][LEN]){
    
    int swapped;
    int size = N;
    do{
        swapped = 0;

        for (int i = 0; i < size - 1; i++){
            char temp[LEN] = {0};
            if (strcmp(strings[i], strings[i + 1]) > 0){
                strcpy(temp, strings[i]);
                strcpy(strings[i], strings[i + 1]);
                strcpy(strings[i + 1], temp);
                swapped = 1;
            }
        }
        size--;
    }while (swapped);
}

void show_uniques(char strings[N][LEN]){

    sort_string_array(strings);

    char uniques[N][LEN] = {0};
    int uniques_count = 0;

    for (int i = 0; i < N; i++){
        bool found = false;
        for (int j = 0; j < uniques_count; j++){
            if (strcmp(strings[i], uniques[j]) == 0){
                found = true;
                break;
            }
        }
        if (!found){
            strcpy(uniques[uniques_count], strings[i]);
            uniques_count++;
        }
    }

    for (int i = 0; i < N; i++){
        printf("%s ", uniques[i]);
    }
}