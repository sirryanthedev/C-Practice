#include <stdio.h>
#include <stdbool.h>

bool check_parentheses(char parentheses[], int size);   // function prototype for parentheses checker

int main(){

    // (ex. 3.1.4) program which checks whether parentheses were closed correctly

    char parentheses[] = {'(', ')', ')', '('};  // example
    int size = sizeof(parentheses) / sizeof(parentheses[0]);

    printf("%d\n", check_parentheses(parentheses, size)); // 1 if closed correctly, else 0

    return 0;
}

bool check_parentheses(char parentheses[], int size){

    int balance = 0;

    if (parentheses[0] != '('){
        return false;
        }

    for (int i = 0; i < size; i++){

        if (balance >= 0){ 
            if (parentheses[i] == '('){
                balance++;
            }
            else if (parentheses[i] == ')'){
                balance--;
            }
        }

        else{
            return false;
        }
    }

    if (balance == 0){
        return true;
    }
    else{
        return false;
    }
}