#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STR_LEN 100

int scompare(char str1[], char str2[]); // function prototype - function which compares 2 strings and returns #different characters

int main(){

    // (ex. 3.2.4) program which outputs the number of different characters between 2 given strings

    char str1[MAX_STR_LEN];
    char str2[MAX_STR_LEN];

    printf("Enter 2 strings...\n\n");
    printf("Let's start with the first one: ");
    gets_s(str1, sizeof(str1));
    
    for (int i = 0; i < strlen(str1); i++){
        str1[i] = toupper(str1[i]); // ignore uppercase vs lowercase (=)
    }

    printf("Now enter the second string: ");
    gets_s(str2, sizeof(str2));
    
    for (int i = 0; i < strlen(str2); i++){
        str2[i] = toupper(str2[i]);
    }

    printf("\n");
    printf("Amount of different characters: %d", scompare(str1, str2));

    return 0;

}

int scompare(char str1[], char str2[]){
    
    int max;
    int min;
    int different = 0;

    max = (strlen(str1) > strlen(str2)) ? strlen(str1) : strlen(str2);
    min = (strlen(str1) < strlen(str2)) ? strlen(str1) : strlen(str2);

    int difference = (max - min);
    different += difference;

    for (int i = 0; i < min; i++){
        if (str1[i] != str2[i]){
            different += 1;
        }
    }

    return different;
}