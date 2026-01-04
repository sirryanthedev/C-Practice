// (ex. 8.2.3 - option 1)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char** argv){
    
    if (argc <= 1) return 1;

    int total_size = 1; // 1 for the null terminator

    for (size_t i = 1; i < argc; i++){
        total_size += strlen(argv[i]);
        // add room for spaces to seperate arguments only done conditionally to prevent excess space at the end
        if (i < argc - 1) total_size += 1;
    }

    // reserve enough space for all the argument strings
    char *concat = calloc(1, total_size); // use of calloc for null initialisation to prevent garbage values at the start (strcat does the cat when it first encounters a nullterminator)
    if (!concat) return 1; // check memory allocation succes

    for (size_t i = 1; i < argc; i++){
        // append or concatenate all arguments to concat
        strcat(concat, argv[i]);
        // add spaces to seperate arguments only done conditionally to prevent excess space at the end
        if (i < argc - 1) strcat(concat, " ");
    }

    printf("%s\n", concat);

    free(concat); // free dam
    return 0;
}