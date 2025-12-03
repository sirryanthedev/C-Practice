#include <stdio.h>
#include <string.h>
#include <ctype.h>

void strip(char str[]); // function prototype for strip function

int main(){

    // (ex 3.2.1) program which removes excess whitespaces at the end of a string

    char str[] = "hello there   ";  // example string with excess whitespaces at the end

    strip(str);

    printf("%s.", str);
   
    return 0;
}

void strip(char str[]){
    int i = strlen(str) - 1;
    while (i >= 0 && isspace(str[i])){
        str[i] = '\0';
        i--;
    }
}