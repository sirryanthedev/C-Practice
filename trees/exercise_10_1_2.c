#include <stdio.h>
#include <stdlib.h>

typedef struct node_bt{
    int data; // data to store
    struct node_bt* left; // left child
    struct node_bt* right; // right child
}node_bt;

int main(){

    // creating nodes
    node_bt* level_1 = malloc(sizeof(node_bt));
    node_bt* level_2_l = malloc(sizeof(node_bt));
    node_bt* level_2_r = malloc(sizeof(node_bt));
    node_bt* level_3_l = malloc(sizeof(node_bt));
    node_bt* level_3_r = malloc(sizeof(node_bt));
    node_bt* level_4 = malloc(sizeof(node_bt));

    // connecting nodes to their child(ren)
    level_1->left = level_2_l;
    level_1->right = level_2_r;
    level_2_l->left = level_3_l;
    level_2_r->right = level_3_r;
    level_3_l->left = level_4;

    // filling each node with data
    level_1->data = 50;
    level_2_l->data = 25;
    level_2_r->data = 75;
    level_3_l->data = 10;
    level_3_r->data = 42;
    level_4->data = 99;
    
    return 0;
}