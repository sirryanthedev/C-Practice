#include <stdio.h>
#include <string.h>

void sentence_info(char sentence[]);

int main(){

    // (ex. 4.4.5) program which displays the words of a sentence along with their respective - and total - word count
    
    char sentence[] = "Hello there, how are you?";  // example sentence
    
    sentence_info(sentence);

    return 0;
}

void sentence_info(char sentence[]){

    char sentence_cpy[strlen(sentence)];    
    
    // make copy of original string to prevent original string from being modified by strtok function

    strcpy(sentence_cpy, sentence);

    int word_count = 0; // variable to keep track of the #words
    char* token = strtok(sentence_cpy, " ,;?.!");   // start tokenizing (at sentence[0] - first word)

    while (token != NULL){
        printf("Word %d: %s\n", word_count + 1, token);
        word_count++;
        token = strtok(NULL, " ,;?.!"); // NULL - tokenize from where it left of 
    }

    printf("\nNumber of words: %d", word_count);
}