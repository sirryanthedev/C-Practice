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

int main(){

    struct node_dll* head = NULL;
    struct node_dll name_3 = {"Joe", NULL, NULL};
    struct node_dll name_2 = {"Zayn", NULL, NULL};
    struct node_dll name_1 = {"Adam", NULL, NULL};

    struct node_dll* array[] = {&name_1, &name_2, &name_3};
    int number_of_elements = sizeof(array)/sizeof(array[0]);

    // extract info from parameters and create a dll
    function_1(array, number_of_elements, &head);

    // output contents of dll using head
    print_dll(head);

    puts("\n");
    
    // test dll functionality
    printf("%s\n", head->next->next->prev->string); // joe

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