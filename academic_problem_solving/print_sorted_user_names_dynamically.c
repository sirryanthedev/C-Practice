#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_alpha(const void* a, const void* b); // self-created function to sort strings alphabetically in ascending order

int main(){
    // initialise 2 variables
    char buffer[25]; // storage for names upto 24 characters (25th character is reserved for nullterminator)
    int number_names;

    // ask for the number (int) of names using fgets and do error-handling
    printf("Enter the number of names: ");
    if (!fgets(buffer, sizeof(buffer), stdin)) return 1; // error fgets
    if (strlen(buffer) <= 0) return 1; // error input

    // atoi (ASCII to integer conversion) of buffer in number_names
    number_names = atoi(buffer);
    if (number_names <= 0) return 1; // not numerical value

    // dynamically allocate memory with zero-initialisation for 2d-array names
    char** names = calloc(number_names, sizeof(char*));
    if (!names) return 1; // error-handling

    // get the names and place them in the array
    for (size_t i = 0; i < number_names; i++){
        printf("Enter name number %zu: ", i + 1);

        if (!fgets(buffer, sizeof(buffer), stdin)) return 1; // ask for name, place it in buffer, error-handling

        if (strlen(buffer) > 0 && buffer[strlen(buffer) - 1] == '\n'){ // buffer has size and last char is newline
            buffer[strlen(buffer) - 1] = '\0'; // make last char a nullterminator
        }
        names[i] = calloc(strlen(buffer) + 1, sizeof(char)); // dynamically allocate memory for each name, reserve space for nullterminator
        strcpy(names[i], buffer); // place name (in buffer) in names[i] using strcpy instead of assigning it directly to names[i]
    }

    qsort(names, number_names, sizeof(char*), compare_alpha); // call qsort with self-created compare function on the array of names

    // printing out the names, sorted, seperated by a space
    for (size_t i = 0; i < number_names; i++){
        printf("%s ", names[i]);
    }

    // free dynamically allocated memory on the heap
    for (size_t i = 0; i < number_names; i++){
        free(names[i]); // free reserved memory for each name
    }

    free(names); // free reserved memory for the array of names itself

    return 0;
}

int compare_alpha(const void* a, const void* b){ // 2 generic pointers (const void*) return type of compare function is always int (<0 if less than, 0 if equal, >0 if greater than)
    const char* x = *(const char**)a; // left of "=" is a pointer to one element of the datastructure, typeconversion and dereferencing on the right
    const char* y = *(const char**)b;
    return strcmp(x, y); // alphabetical sorting ascending - dereferencing to get letters instead of memory addresses, strcmp for comparison
};