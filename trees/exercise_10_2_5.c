#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// architecture integer tree - children connected through linked list
typedef struct node_t{
    int data;
    struct node_t* oldest_child; // first child
    struct node_t* sibling; // all other children are connected to this (linked list)
}node_t;

node_t* create_node(int value); // create a node
node_t* add_child(node_t* parent, int value); // add children
void print_tree(node_t* head); // output the tree using dfs

int main(){

    // create a tree (Figuur 10.2)
    node_t* level_1 = create_node(50);
    node_t* level_2 = add_child(level_1, 25);
    node_t* level_2_1 = add_child(level_1, 75);
    node_t* level_2_2 = add_child(level_1, 100);
    node_t* level_3 = add_child(level_2, 10);
    node_t* level_3_1 = add_child(level_2, 42);
    node_t* level_3_2 = add_child(level_2_2, 20);
    node_t* level_4 = add_child(level_3, 5);
    node_t* level_4_1 = add_child(level_3, 7);
    node_t* level_4_2 = add_child(level_3_1, 9);
    node_t* level_4_3 = add_child(level_3_2, 1);
    node_t* level_4_4 = add_child(level_3_2, 2);
    node_t* level_4_5 = add_child(level_3_2, 3);
    node_t* level_4_6 = add_child(level_3_2, 4);

    print_tree(level_1);

    return 0;
}

node_t* create_node(int value){
    // create node
    node_t* new_node = malloc(sizeof(node_t));

    // failure
    if (!new_node) return NULL;

    // initialisation
    new_node->data = value;
    new_node->oldest_child = NULL;
    new_node->sibling = NULL;

    return new_node;
}

node_t* add_child(node_t* parent, int value){
    // parent doesn't exist
    if (parent == NULL) return NULL;

    // no children
    if (parent->oldest_child == NULL){
        // create new child
        node_t* tmp = create_node(value);

        // failure
        if (!tmp) return NULL;

        // succes
        parent->oldest_child = tmp;
        return (parent->oldest_child); // tmp
    }

    // children already present
    node_t* p = parent->oldest_child;

    // cycle through the children
    while (true){
        // no next sibling -> create one
        if (p->sibling == NULL){
            p->sibling = create_node(value);
            return p->sibling;
        }
        p = p->sibling;
    }

    // failure
    return NULL;
}

void print_tree(node_t* head){
    // base case: nothing to do
    if (head == NULL) return;

    // process node
    printf("%d ", head->data);

    // process on first child
    print_tree(head->oldest_child);

    // process on next sibling
    print_tree(head->sibling);
}