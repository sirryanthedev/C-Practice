#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// doubly linked list architecture
struct node_dll{
    char* string;
    struct node_dll* prev;
    struct node_dll* next;
};

int compare_s(const void* a, const void* b); // compare each element of an array of struct node_dll* by their string property
void function_1(struct node_dll** array, int size, struct node_dll** head); // link nodes by string property alphabetically
void print_dll(struct node_dll* head); // output the dll
void unique_nodes(struct node_dll** head);

int main(){

    // create a dll ("Aaron" - "Aaron" - "Joe" - "Zayn" - "Zayn")
    struct node_dll* head = NULL;

    struct node_dll name_1;
    name_1.string = "Aaron";

    struct node_dll name_2;
    name_2.string = "Aaron";

    struct node_dll name_3;
    name_3.string = "Joe";

    struct node_dll name_4;
    name_4.string = "Zayn";

    struct node_dll name_5;
    name_5.string = "Zayn";

    name_5.next = head;
    name_5.prev = &name_4;

    name_4.next = &name_5;
    name_4.prev = &name_3;

    name_3.next = &name_4;
    name_3.prev = &name_2;

    name_2.next = &name_3;
    name_2.prev = &name_1;

    name_1.next = &name_2;
    name_1.prev = NULL;

    head = &name_1;

    // delete repeating names
    unique_nodes(&head);

    // print the unique names
    print_dll(head);

    return 0;
}

int compare_s(const void* a, const void* b){
    const struct node_dll* x = *(const struct node_dll**)a;
    const struct node_dll* y = *(const struct node_dll**)b;
    return strcmp(x->string, y->string);
}

void function_1(struct node_dll** array, int size, struct node_dll** head){ // array of struct node_dll, #elements in array, pointer to the head of the dll
    // sort local copy of array
    qsort(array, size, sizeof(struct node_dll*), compare_s);

    // link nodes together
    for (int i = size - 1; i >= 0; i--){
        array[i]->next = *head;

        if (i > 0){
            array[i]->prev = array[i - 1];
        }
        else{
            array[i]->prev = NULL;
        }

        *head = array[i];
    }

}

void print_dll(struct node_dll* head){
    struct node_dll* p = head;

    while (p != NULL){
        printf("%s\n", p->string);
        p = p->next;
    }
}

void unique_nodes(struct node_dll** head){ // assume that the dll is sorted alphabetically
    char* name;
    struct node_dll* current = *head;
    struct node_dll* previous = NULL;

    while (current != NULL){
        // repeating name
        if (strcmp(current->string, name) == 0){ // strcmp instead of "==" to compare strings
            previous->next = current->next; // unlink current node by linking previous node to next node
            if (current->next){ // next node is not null and hence has a prev property
                current->next->prev = previous; // link next's prev to previous node which we connected to next node
            }
            current = current->next; // update current
        }

        // non-repeating name
        else{
            name = current->string; // assign whatever is in current's string to name
            previous = current; // previous points current node
            current = current->next; // update current to next node
        }
    }
}