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
void unique_nodes(struct node_dll** head); // remove repeating nodes (nodes with the same string property)
struct node_dll* merge_lists(struct node_dll* list_1, struct node_dll* list_2); // create a merged dll out of 2 seperate dll's

int main(){

    // info for first dll
    struct node_dll* head_1 = NULL;
    struct node_dll name_3 = {"Joe", NULL, NULL};
    struct node_dll name_2 = {"Zayn", NULL, NULL};
    struct node_dll name_1 = {"Adam", NULL, NULL};
    struct node_dll* array_1[] = {&name_1, &name_2, &name_3};
    int number_of_elements_1 = sizeof(array_1)/sizeof(array_1[0]);

    // info for second dll
    struct node_dll* head_2 = NULL;
    struct node_dll name_3_2 = {"Solomon", NULL, NULL};
    struct node_dll name_2_2 = {"Zecheria", NULL, NULL};
    struct node_dll name_1_2 = {"Eve", NULL, NULL};
    struct node_dll* array_2[] = {&name_1_2, &name_2_2, &name_3_2};
    int number_of_elements_2 = sizeof(array_2)/sizeof(array_2[0]);

    // create 2 seperate dll's
    function_1(array_2, number_of_elements_2, &head_2);
    function_1(array_1, number_of_elements_1, &head_1);

    // create a merged dll
    struct node_dll* new_head = merge_lists(head_1, head_2);

    // print the merged_dll
    print_dll(new_head);

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

struct node_dll* merge_lists(struct node_dll* list_1, struct node_dll* list_2){
    struct node_dll* new_head = NULL;
    int count = 0; // keep track of total number of nodes
    struct node_dll* p; // pointer variable to cycle through dll's

    // extract number of nodes in first list
    p = list_1;
    while (p != NULL){
        count ++;
        p = p->next;
    }

    // extract number of nodes in second list
    p = list_2;
    while(p != NULL){
        count ++;
        p = p->next;
    }

    struct node_dll* elements[count]; // array where the individual nodes are stored

    int idx_count = 0; // keep track of the index
    struct node_dll* next = NULL; // keep track of the next node

    p = list_1; // use p to cycle through the first list and add its nodes to elements (array)
    while (p != NULL){
        next = p->next; // save next node
        elements[idx_count] = p; // add the address of the node to elements
        idx_count++; // increment idx_count
        p->prev = NULL; // unlink node from previous node
        p->next = NULL; // unlink node from next node
        p = next; // advance p
    }

    p = list_2; // change p to second head and add its nodes to elements (array)
    while (p != NULL){
        next = p->next; // save next node
        elements[idx_count] = p; // add the address of the node to elements
        idx_count++; // increment idx_count
        p->prev = NULL; // unlink node from previous node
        p->next = NULL; // unlink node from next node
        p = next; // advance p
    }

    // merged list of elements and make the head new_head
    function_1(elements, count, &new_head);

    // head pointing to the merged list
    return new_head;
}