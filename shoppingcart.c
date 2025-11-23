#include <stdio.h>
#include <string.h>

int main(){

    // shopping cart program
    
    char currency = '$';
    char item[50] = "";
    float price = 0.0f;
    int amount = 0;

    printf("What would you like to buy: ");
    fgets(item, sizeof(item), stdin);

    item[strlen(item) - 1] = '\0';

    printf("What is its price: ");
    scanf("%f", &price);

    printf("How many would you like: ");
    scanf("%d", &amount);

    float total = price * amount;

    printf("You have bought %d %s/s\n", amount, item);
    printf("The total is %c%.2f", currency, total);

    return 0;
}