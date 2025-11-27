#include <stdio.h>

int main(){

                                                        // a program which computes the character that appears longest in sequence (1.5.7)

    int c;
    int current_count = 0;
    char current_char = '\0';
    int best_count = 0;
    char best_char = '\0';

    while ((c = getchar()) != EOF){

        if (c == '\n'){
            goto end;
        }

        if (c == current_char){
            current_count++;
        }
        else{
            current_char = c;
            current_count = 1;
        }

         if (current_count > best_count){
            best_count = current_count;
            best_char = current_char;
        }
    }

    end:
        if (best_count == 0){
            printf("No characters were input...");
        }
        else{
        printf("The character which appears longest in sequence is %c\n", best_char);
        }
        
    return 0;
}