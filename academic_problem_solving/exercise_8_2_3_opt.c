// (ex. 8_2_3 - option 2)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv){

    if (argc <= 1) return 1;

    int total_size = 1;
    char* concat = calloc(1, total_size);
    if (!concat) return 1;

    for (size_t i = 1; i < argc; i++){
        total_size += strlen(argv[i]); // add bytes of memory corresponding to length of argument
        if (i < argc - 1) total_size += 1; // conditionally add room for space
        concat = realloc(concat, total_size); // reallocate concat (expand memory per argument)
        strcat(concat, argv[i]); // add argument to concat
        if (i < argc - 1) strcat(concat, " "); // conditionally add space to concat
    }

    printf("%s\n", concat);

    free(concat); // free dam
    return 0;
}