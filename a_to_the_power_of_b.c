#include <stdio.h>

int main(){

    // very simple program to compute a^b

    int a,b;
    int result = 1;

    printf("Enter two integer numbers a and +b to compute (a^b): ");
    scanf("%d %d", &a, &b);

    printf("%d^%d = ", a, b);

    for(int i = 0; i < b; i++){
        result *= a;
    }

    printf("a^b = %d\n", result);

    result = 1;
    a = 0;
    b = 0;

    printf("\n");
    printf("Now let's do the same, but with some changes under the hood...\n");
    printf("Enter two integer numbers a and +b to compute (a^b): ");
    scanf("%d %d", &a, &b);

    printf("%d^%d = ", a, b);

    while(b > 0){
        b--;
        result *= a;
    }

    printf("a^b = %d", result);

    return 0;
}