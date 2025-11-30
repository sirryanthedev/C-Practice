#include <stdio.h>
#include <string.h>

void reverse(char str[]);   // function prototype for reversing

int main(){

    // program to reverse string

    char a[50];
    // input
    printf("Enter a string: ");
    gets_s(a, sizeof(a));
    
    reverse(a);
    printf("reversed: %s\n", a);

    return 0;
}

void reverse(char str[]){
    int left = 0;
    int right = strlen(str) - 1;

    while (left < right){
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++;
        right--;
    }
}