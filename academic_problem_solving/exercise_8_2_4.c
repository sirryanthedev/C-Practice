// (ex. 8_2_4)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** tok_str_to_arr(char* sentence, int* num_tokens);

int main(){

    char* sentence = "hello there how are you, my friend?"; // variable [] instead of fixed * to avoid segmentation errors
    int num_tokens = 0;

    char** new_arr = tok_str_to_arr(sentence, &num_tokens); // function returns an array of strings (**) this is captured in new_arr

    // print the 5 strings in the new_arr and free all dynamically allocated strings
    for (size_t i = 0; i < num_tokens; i++){ // here num_tokens is modified by the function
        printf("%s\n", new_arr[i]);
        free(new_arr[i]);
    }

    // free the array itself
    free(new_arr);

    return 0;
}

char** tok_str_to_arr(char* sentence, int* num_tokens){
    // create a copy of sentence
    char sentence_cpy1[strlen(sentence) + 1]; // leave room for null terminator
    strcpy(sentence_cpy1, sentence);

    char* token = strtok(sentence_cpy1, ",./?!;: "); // tokenise for the first time

    // if first tok didn't return NULL -> enter loop and print the result, then tokenise again and repeat conditionally
    while (token != NULL){
        *num_tokens += 1;
        token = strtok(NULL, ",./?!;: ");
    }

    char** s_arr = malloc(*num_tokens*sizeof(char*)); // create array on heap (for return) with enough space for the number of strings in the sentence

    strcpy(sentence_cpy1, sentence); // before tokenising again, make sure sentence_cpy1 is reverted to initial state after the modifications done by earlier tokenising

    token = strtok(sentence_cpy1, ",./?!;: "); // tokenise for the first time

    int idx = 0; // keep track of index

    // if first tok didn't return NULL -> enter loop and print the result, then tokenise again and repeat conditionally
    while (token != NULL){
        s_arr[idx] = calloc(1, strlen(token) + 1);
        strcpy(s_arr[idx], token);
        token = strtok(NULL, ",./?!;: ");
        idx++;
    }

    return s_arr;
}