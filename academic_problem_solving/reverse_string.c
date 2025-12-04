#include <stdio.h>
#include <string.h>

void sreverse(char string[]);   // function to reverse string

int main(){

    // (ex. 4.4.3) program which reverses a string

    char word[] = "HelloWorld"; // example string

    sreverse(word); // function call to reverse string

    printf("%s", word); // output reversed string

    return 0;
}

void sreverse(char string[]){
    
    char temp;  // temporary character holder
    int last = strlen(string) - 1;  // last character of original string

    // replace the first and last character with each other
    for (int i = 0; i < (strlen(string) / 2); i++){

        temp = string[i];
        string[i] = string[last];
        string[last] = temp;
        
        last--;
    }
}