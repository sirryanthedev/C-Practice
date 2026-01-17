#include <stdio.h>
#include <stdlib.h>

// architecture integer tree - children connected through linked list
typedef struct node_t{
    int data;
    node_t* oldest_child; // first child
    node_t* sibling; // all other children are connected to this (linked list)
}node_t;

int main(){
    return 0;
}