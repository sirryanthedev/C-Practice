#include <stdio.h>
#include <stdlib.h>

typedef struct node_bt{
    int data; // data to store
    struct node_bt* left; // left child
    struct node_bt* right; // right child
}node_bt;

void print_bt_pre_order(node_bt* top); // dfs - pre order output of binary tree (NLR)
node_bt* create_node(int data); // create a node with left and right child initialised (NULL)
node_bt* get_node(node_bt* top, int value); // return pointer to the node with int value (2nd arg)
node_bt* add_node(node_bt* top, int parent_value, int data); // add node with int data under node with parent_value, return is a pointer to the newly added node
void print_bt_post_order(node_bt* top); // dfs - post order output of binary tree (LRN)
void print_bt_in_order(node_bt* top); // dfs - in order output of binary tree (LNR)
struct node_bt** helper(node_bt** tree, int value); // helper function for deleting_node
void delete_node(node_bt** to_delete); // function which should be called by the user to delete a node

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

    delete_node(helper(&level_1, 10)); // delete subtree beginning at 10 (10-99)
    print_bt_pre_order(level_1); // output tree without deleted subtree (50-25-42-75)

    return 0;
}

void print_bt_pre_order(node_bt* top){
    if (top == NULL) return; // base case: nothing to do
    printf("%d ", top->data); // process current node
    print_bt_pre_order(top->left); // call function on left child - visit left subtree
    print_bt_pre_order(top->right); // call function on right child - visit right subtree
}

node_bt* create_node(int data){
    node_bt* new_node = malloc(sizeof(node_bt)); // allocate memory on the heap for the node

    // allocation failure
    if (!new_node){
        return NULL;
    }

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

node_bt* add_node(node_bt* top, int parent_value, int data){

    // parent node is node with parent_value (2nd arg)
    node_bt* parent = get_node(top, parent_value);

    // not found -> return NULL
    if (parent == NULL){
        return NULL;
    }

    // found -> add node
    else{
        // no left child yet, so add node there
        if (parent->left == NULL){
            parent->left = create_node(data);
            return parent->left;
        }
        // no right child yet, so add a node there
        else if(parent->right == NULL){
            parent->right = create_node(data);
            return parent->right;
        }
        // left and right child already exist, return NULL
        else{
            return NULL;
        }
    }
}

void print_bt_post_order(node_bt* top){ // post order - LRN
    if (top == NULL) return; // base case: nothing to do
    print_bt_post_order(top->left); // L - visit left subtree
    print_bt_post_order(top->right); // R - visit right subtree
    printf("%d ", top->data); // N - if no left or right subtrees, print data at node
}

void print_bt_in_order(node_bt* top){ // in order - LNR
    if (top == NULL) return; // base case: nothing to do
    print_bt_in_order(top->left); // L - visit left subtree
    printf("%d ", top->data); // if no left subtrees anymore - process (print data) current node
    print_bt_in_order(top->right); // visit right subtree
}

void delete_node(node_bt** to_delete){ // post order - LRN (** instead of * so we can change the pointer to NULL to avoid dangling pointers, check explanation)

    if (to_delete == NULL || *to_delete == NULL) return; // base case - nothing to do

    delete_node(&((*to_delete)->left)); // L - visit left subtree
    delete_node(&((*to_delete)->right)); // R - visit right subtree

    free(*to_delete); // N - free memory on heap
    *to_delete = NULL; // avoid dangling pointers, explanation: the node to be deleted is a pointer since it holds the address of struct node_bt, after freeing, the variable *to_delete will still point to that memory on the heap which is now non-existent, and if it has parents, then will point to this error as well
}

struct node_bt** helper(node_bt** tree, int value){
    
    // base case: nothing to search
    if (tree == NULL || (*tree) == NULL) return NULL;

    // value found
    if ((*tree)->data == value) return tree;

    // search left subtree
    struct node_bt** left_result = helper(&(*tree)->left, value);
    // value found at the end of search - propagate result upward
    if (left_result != NULL) return left_result;

    // search right subtree
    return helper(&(*tree)->right, value);
}