#include <stdio.h>
#include <stdlib.h>

#include "tree.h"
#include "appointment.h" // for the compare function

node* create_node(node_type type, void* data){
    // reserve memory on the heap for the new node
    node* new_node = malloc(sizeof(node));

    // failure
    if (!new_node) return NULL;

    // insert input
    new_node->type = type;
    new_node->data = data;

    // initialise pointers
    new_node->first_child = NULL;
    new_node->siblings = NULL;

    return new_node;
}

node* add_child_sorted(node* parent, node* child){
    // invalid input
    if (!parent || !child){
        return NULL;
    }

    // no children yet
    if (parent->first_child == NULL){
        parent->first_child = child; // first child
        child->siblings = NULL; // avoid dangling pointers
        return child;
    }

    // children aren't appointment nodes
    if (parent->type < DAY){ 
    node* p = parent->first_child;
    node *q = NULL;

    // child's value less than first_child's value
    if ((*(int*)child->data) < (*(int*)parent->first_child->data)){ // void* -> int* typecase, then dereference for int comparison
        child->siblings = parent->first_child; // connect child to sibling
        parent->first_child = child; // update first_child
        return child;
    }

    // hover over linked list to find insertion point (middle or end)
    while (p != NULL && (*(int*)p->data) < (*(int*)child->data)){ // same typecasting as above - sort ascending (<)
        q = p;
        p = p->siblings;
    }

    // end reached
    if (p == NULL){
        q->siblings = child;
        child->siblings = NULL;
        return child;
    }

    // insert in the middle
    q->siblings = child;
    child->siblings = p;
    return child;
    }

    // children are appointment nodes
    if (parent->type == DAY){
        node* curr_app = parent->first_child;
        node* prev_app = NULL;

        // first child: if child < first_child insert before first_child
        if (compare_appointments(&(child->data), &(curr_app->data)) < 0){
            child->siblings = parent->first_child;
            parent->first_child = child;
            return child;
        }

        // loop through children to find insertion point
        while (curr_app != NULL && compare_appointments(&(child->data), &(curr_app->data)) > 0){
            prev_app = curr_app;
            curr_app = curr_app->siblings;
        }

        // last child (insert at the end)
        if (curr_app == NULL){
            prev_app->siblings = child;
            child->siblings = NULL; // avoid dangling pointer
            return child;
        }

        // middle child (insert at the middle)
        prev_app->siblings = child;
        child->siblings = curr_app;
        return child;
    }

    // appointment type == NULL
    return NULL;
}