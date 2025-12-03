#include <stdio.h>

int main(){

    // (ex. 4.1.1) intro to pointers

    int i, *j;
    j = NULL;
    i = 0;
    j = &i; // j holds address of i (definition pointer)

    printf("Content of i: %d\n", i);
    printf("Content of j: %d\n\n", *j); // dereference operator to get value instead of address

    printf("Address of i: %p\n", &i);   // %p format for addresses
    printf("The address to which j points: %p\n\n", j); // j holds address already so no preceding '*'
    printf("Address of j: %p\n", &j); // pointer j holds an address (that of i) with a corresponding value (in this case 0), but j itself has an address: &j

    return 0;
}