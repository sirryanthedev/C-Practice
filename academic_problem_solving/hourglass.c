#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool is_hourglass(const char** words, size_t num_words);
void lower_string(char* string); // convert string to lowercase - helper function

int main(){
    // example of an hourglass
    const char* words[] = {"I", "is", "piS", "pris", "frpis"};

    if (is_hourglass(words, 5)){
        puts("this is an hourglass");
    }
    else{
        puts("this isn't an hourglass");
    }

    return 0;
}

void lower_string(char* string){
    for (size_t i = 0; string[i] != '\0'; i++){
        string[i] = tolower(string[i]);
    }
}

bool is_hourglass(const char** words, size_t num_words){
    // loop through words
    for (size_t i = 0; i < num_words; i++){
        // next word exists
        if ((i + 1) < num_words){
            // create a copy of the next word in lowercase
            char next_word_lower[strlen(words[i + 1]) + 1];
            strcpy(next_word_lower, words[i + 1]);
            lower_string(next_word_lower);
            size_t len = strlen(words[i]);
            // check presence of all current chars in next word
            for (size_t j = 0; j < len; j++){
                if (!strchr(next_word_lower, tolower(words[i][j]))){
                    return false;
                }
            }
        }
        // make sure the length of words increases by one every index, starting with length 1 at idx 0
        if (strlen(words[i]) != (i + 1)) return false;
    }
    // it is an hourglass
    return true;
}