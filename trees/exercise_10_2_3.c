#include <stdio.h>
#include <stdlib.h>

// architecture for integer trees
typedef struct node_t{
    int data; // value of the node
    struct node_t** children; // dynamically allocated array of pointers to children
    int child_count;
}node_t;

node_t* create_node(int data); // create a new node
node_t* add_child(node_t* node, int value); // add child to an existing node
void print_tree(node_t* tree); // output a tree using dfs

int main(){
    // create nodes for tree (Figuur 10.2)
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

node_t* create_node(int data){
    // reserve memory on the heap for the new node
    node_t* new_node = malloc(sizeof(struct node_t));

    // memory allocation failure
    if (!new_node){
        return NULL;
    }

    // insert data and initialise children and child_count
    new_node->data = data;
    new_node->children = NULL;
    new_node->child_count = 0;

    return new_node;
}

node_t* add_child(node_t* node, int value){
    // node doesn't exist
    if (node == NULL) return NULL;

    // otherwise: preserve room for the new node (child)
    node_t** tmp = realloc(node->children, sizeof(node_t*) * (node->child_count + 1));

    // reallocation failed
    if (!tmp){
        return NULL;
    }

    // reallocation success
    node->children = tmp;

    // increment child count
    node->child_count += 1; 

    // insert new node
    node_t* new_child = create_node(value);

    // new_child creation failed
    if (!new_child){
        node->child_count--;
        return NULL;
    }
    
    // succes
    node->children[(node->child_count) - 1] = new_child;
    return (node->children[(node->child_count) - 1]);
}

void print_tree(node_t* tree){
    // base case: nothing to search
    if (tree == NULL) return;

    // output the data associated with each node
    printf("%d ", tree->data);

    // visit all children
    for (size_t i = 0; i < (tree->child_count); i++){
        print_tree(tree->children[i]);
    }
}