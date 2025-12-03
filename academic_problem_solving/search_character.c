#include <stdio.h>
#include <string.h>

#define MAX_STR_LEN 50

int main(){

    // program which searches for a character in a sentence

    char sentence[MAX_STR_LEN];

    puts("Enter a string/sentence to be searched for: ");

    gets_s(sentence, sizeof(sentence));

    puts("Enter the character to be searched: ");

    char ch = getchar();

    char *p = strchr(sentence, ch);

    printf("\nString starts at address: %p\n\n", sentence);

    if (p != NULL){
        printf("First occurence of %c is: %p\n",ch, p);
        printf("The index of this character is: %lld\n", p - sentence);
    }
    else{
        printf("The character is not present in the given string...\n");
    }

    return 0;
}