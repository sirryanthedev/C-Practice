#include <stdio.h>
#define ROWS 5                       // choose a value (<10) for rows - replace 5 with a value (<10)

int main(){

    // (ex. 1.4.5) program which computes growing rows

    for(int i = 1; i <= ROWS; i++){
        
        for(int s = ROWS-i; s > 0; s--){
            printf(" ");
        }

        for(int j = i; j >= 1; j--){
            printf("%d", j);
        }
        printf("\n");
    }

    return 0;
}