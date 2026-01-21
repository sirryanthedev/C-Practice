#include <stdio.h>
#include <string.h>
#include <ctype.h>

int count_equal_chars(const char* str_1, const char* str_2);
const char* find_lrs(const char* main_str, size_t* lrs_count);

int main(){
    
    size_t i;
    printf("%s\n", find_lrs("banana", &i));

    return 0;
}

int count_equal_chars(const char* str_1, const char* str_2){
    int i = 0; // starting index at 0
    while (tolower(str_1[i]) == tolower(str_2[i])){ // characters are equal -> stay in loop, increment i -> next loop
        i += 1;
    }
    return i; // number of equal characters
}

const char* find_lrs(const char* main_str, size_t* lrs_count){
    const char* lrs = NULL; // longest repeated substring
    *lrs_count = 0; // number of characters in lrs
    size_t str_len = strlen(main_str); // number of characters in input string (main_str)

    // loop through all characters, compare the first one with every next one and search for equal characters
    for (size_t i = 0; i < str_len; i++){
        for (size_t j = i + 1; j < str_len; j++){ // j is always ahead of i
            int number_equal_chars = count_equal_chars(main_str + i, main_str + j);
            if (number_equal_chars > *lrs_count){ // update lrs and lrs_count
                *lrs_count = number_equal_chars;
                lrs = main_str + j;
            }
        }
    }
    // longest repeated substring
    return lrs; 
}