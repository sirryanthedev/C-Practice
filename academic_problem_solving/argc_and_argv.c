#include <stdio.h>

int main(int argc, char* argv[]){   // argc for argument count, argv is an array of strings (arguments)

    // print argument count
    printf("argc: %d\n", argc);

    // loop through argument vector and print its arguments
    for (int i = 0; i < argc; i++){
        printf("argv[%d] = %s\n", i, argv[i]);
    }

    return 0;
}