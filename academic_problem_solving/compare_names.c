#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define ARRAY_SIZE 5    // max. amount of names
#define MAX_STR_LEN 10  // max. length of elements (name)

void read_name(char str[], int size);   // function prototype

int main(){

    char name[MAX_STR_LEN];
    char names[ARRAY_SIZE][MAX_STR_LEN] = {"Lena", "Fransesca", "Ryan", "Gustav", "Peter"};
    bool found = false;

    printf("Enter a name: ");
    read_name(name, MAX_STR_LEN);   // could use gets_s as an alternative to fgets

    for (int i = 0; i < ARRAY_SIZE && !found; i++){
        if (strcmp(name, names[i]) == 0){   // if input equals a name from array: found flag is set to true and loop is exited
            found = true;
        } 
    }
    // print special message depending on whether input name was found in array
    if (found){
        printf("You may enter, oh honored one!\n");
    }
    else{
        printf("Guards, remove this person!");
    }
    return 0;
}

void read_name(char str[], int size){

    fgets(str, size, stdin);

    if (str[strlen(str) - 1] == '\n') { // if input buffer ends with newline char: remove it
        str[strlen(str) - 1] = '\0';
    }

    // convert entire name to lowercase, then make first character uppercase
    int len = strlen(str);

    for (int i = 0; i < len; i++){ 
        str[i] = tolower(str[i]);
    }
    
    str[0] = toupper(str[0]);
}