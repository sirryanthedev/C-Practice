#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    // (ex. 4.3.6) program which finds 10 unique combinations of 3 numbers out of an array of 5

    int nums[5];    // 5 numbers in array

    srand(time(NULL));  // set seed dependent on time

    // put random numbers (1-100) in nums array and print them to terminal
    for (int i = 0; i < 5; i++) {
        nums[i] = rand() % 100 + 1;
        printf("%d ", nums[i]);
    }
    printf("\n\n");

    int *p, *q, *r; // initialize 3 pointers (3 positions)
    int counter = 0; // initialize counter    

    for (p = nums; p < nums + 3; p++) {     // p = &nums[0]; leave room for other 2 pointers (5 - 2 = 3)
        for (q = p + 1; q < nums + 4; q++) {    // q is always 1 greater than p; leave room for 1 pointer (5 - 1 = 4)
            for (r = q + 1; r < nums + 5; r++) {    // r is always 1 greater than q; leave room for 0 pointers (5 - 0 = 5)
                counter += 1;
                printf("combination %d: %d %d %d\n", counter, *p, *q, *r);
            }
        }
    }

    return 0;
}