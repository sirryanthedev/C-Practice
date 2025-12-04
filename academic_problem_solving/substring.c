#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void substring(char str1[], char str2[]);

int main() {

    // (ex. 4.4.6) program which uses strstr function to search for substrings in (sub)strings

    char str1[] = "oefeningen c"; // source string
    char str2[] = "en"; // string to search for in (source) string

    substring(str1, str2);

    return 0;
}

void substring(char str1[], char str2[]){

    char* ptr = str1;
    
    while ((ptr = strstr(ptr, str2)) != NULL){
        printf("%s\n", ptr);
        ptr++;
    }
}