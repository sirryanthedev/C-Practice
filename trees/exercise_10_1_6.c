#include <stdio.h>
#include <stdlib.h>

typedef struct node_bt{
    int data; // data to store
    struct node_bt* left; // left child
    struct node_bt* right; // right child
}node_bt;

void print_bt_dfs(node_bt* top); // output binary tree using dfs
node_bt* create_node(int data); // create a node with left and right child initialised (NULL)
node_bt* get_node(node_bt* top, int value); // return pointer to the node with int value (2nd arg)

int main(){

    // creating nodes
    node_bt* level_1 = create_node(50);
    node_bt* level_2_l = create_node(25);
    node_bt* level_2_r = create_node(75);
    node_bt* level_3_l = create_node(10);
    node_bt* level_3_r = create_node(42);
    node_bt* level_4_l = create_node(99);

    // connecting nodes
    level_1->left = level_2_l;
    level_1->right = level_2_r;
    level_2_l->left = level_3_l;
    level_2_l->right = level_3_r;
    level_3_l->left = level_4_l;
    
    printf("%p\n", get_node(level_1, 10)); // returns pointer which holds 10 in its data property

    return 0;
}

void print_bt_dfs(node_bt* top){
    if (top == NULL) return; // base case: nothing to do
    printf("%d ", top->data); // process current node
    print_bt_dfs(top->left); // call function on left child - visit left subtree
    print_bt_dfs(top->right); // call function on right child - visit right subtree
}

node_bt* create_node(int data){
    node_bt* new_node = malloc(sizeof(node_bt)); // allocate memory on the heap for the node
    new_node->data = data; // put input (int data) at data property (->data)
    new_node->left = NULL; // initialise left child to NULL
    new_node->right = NULL; // initialise right child to NULL
    return new_node;
}

node_bt* get_node(node_bt* top, int value){
    if (top == NULL) return NULL; // base case: nothing to search

    if (top->data == value) return top; // found

    node_bt* left_result = get_node(top->left, value); // search left subtree
    if (left_result != NULL) return left_result; // if found, return it

    return get_node(top->right, value); // otherwise, search right subtree
}