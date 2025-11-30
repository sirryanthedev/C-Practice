#include <stdio.h>
#include <string.h>

void reverse(char str[]);   // function prototype for reversing strings

int main(){

    // (ex. 2.2.3 non-recursive) program which displays positive integer decimal number in binary

    int number;    // decimal number which will be converted to binary

    printf("Enter a decimal number: "); // user input
    scanf("%d", &number);

    int number_cpy = number;
    int remainder;  // remainder of each division
    char remainder_str[32] = {0}; // 32 spaces for bits (final binary number)
    int i = 0;  // counter

    do{ remainder = number % 2;
        number /= 2;
        sprintf(&remainder_str[i], "%d", remainder);
        i++;
    }while (number != 0);

    remainder_str[i] = '\0';

    reverse(remainder_str); // reverse remainders

    printf("decimal %d is equivalent to binary %s\n", number_cpy, remainder_str);

    return 0;
}

void reverse(char str[]){
    int right = strlen(str) - 1;
    for (int left = 0; left < right; left++, right--){
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;
    }
}