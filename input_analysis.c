#include <stdio.h>
#include <ctype.h>

int main(){

    // Program which analyses input

    int c;
    int char_count = 0;
    int word_count = 0;
    int in_word = 0;

    printf("Enter: ");

    while ((c = getchar()) != EOF){
        char_count++;

        c = tolower(c);
        putchar(c);

        if(isspace(c)){
            if(in_word){
                in_word = 0;
            }
        }
        else{
            if(!in_word){
                word_count++;
                in_word = 1;
            }
        }
    }

    printf("Amount of words: %d\n", word_count);
    printf("Amount of characters: %d\n", char_count);

    return 0;
}