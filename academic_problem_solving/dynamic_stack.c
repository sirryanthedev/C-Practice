#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    int number;
    char name[20];
}data;

typedef struct{
    int size;
    int capacity;
    data* elements;
}Stack;

void init_stack(Stack* stack);
void push_stack(Stack* stack, data input_data);
void pop_stack(Stack* stack);
void free_stack(Stack* stack);
void print_stack(Stack* stack);

int main(){

    Stack* stack = malloc(sizeof(Stack));
    if (!stack){
        puts("Error allocating memory for the stack in the main program!");
        return 1;
    }
    init_stack(stack);

    data James = {.name = "James", .number = 1};
    data Courtney = {.name = "Courtney", .number = 2};
    data Dan = {.name = "Dan", .number = 3};
    data Joe = {.name = "Joe", .number = 4};
    data Sarah = {.name = "Sarah", .number = 5};

    push_stack(stack, James);
    push_stack(stack, Courtney);
    push_stack(stack, Dan);
    push_stack(stack, Joe);
    push_stack(stack, Sarah);

    // output stack
    print_stack(stack);

    // free memory (used by stack) on the heap 
    free_stack(stack);
    
    return 0;
}

void init_stack(Stack* stack){
    // init with room for 5 structs
    void* temp = malloc(5*sizeof(data));
    if (!temp){
        puts("Error allocating memory!");
        return;
    }

    stack->elements = temp;

    // empty at initialisation (no elements pushed)
    stack->size = 0;

    // current space reserved
    stack->capacity = 5;
}

void push_stack(Stack* stack, data input_data){
    // overflow
    if (stack->size >= 50){
        puts("Overflow...");
        puts("Unable to add element...");
        puts("The max. capacity was reached (50)");
        return;
    }

    // not enough space currently - increase capacity by 5
    if (stack->size >= stack->capacity){
        void* tmp = realloc(stack->elements, (stack->capacity + 5) * sizeof(data));
        if (!tmp){
            puts("Error reallocating memory!");
            return;
        }
        stack->elements = tmp;
        stack->capacity += 5;
        puts("Note: the capacity was increased!");
    }

    // add data at stack->size index of elements in stack
    stack->elements[stack->size] = input_data;

    // one element pushed - increment size by one
    stack->size += 1;
}

void pop_stack(Stack* stack){
    // index of the element to pop
    int index_element_to_pop = stack->size - 1;

    if (index_element_to_pop < 0){
        puts("There is no element to pop...");
        return;
    }

    // print info of element to pop
    printf("name: %s\nnumber: %d\n", stack->elements[index_element_to_pop].name, stack->elements[index_element_to_pop].number);
    
    // "delete" the element
    stack->size -= 1; // reducing size is enough - in the next block memory may get free'd
    puts("The element was popped.");

    // conditionally: shrink memory on the heap (-5)
    if (stack->size + 5 < stack->capacity){
        stack->capacity -= 5;
        void* temp_1 = realloc(stack->elements, ((stack->capacity) * sizeof(data)));
        if (!temp_1){
            puts("Error shrinking memory on the heap!");
            return;
        }
        stack->elements = temp_1;
    }
}

void free_stack(Stack* stack){
    // free memory on the heap for elements
    free(stack->elements);

    // reset stack properties
    stack->capacity = 0;
    stack->size = 0;
    stack->elements = NULL;

    // free stack itself
    free(stack);
}

void print_stack(Stack* stack){
    int size = stack->size;

    // empty stack
    if (size == 0){
        puts("The stack is empty...");
        return;
    }

    printf("Number of items on stack: %d\n", size);

    // output the data-related info
    for (size_t i = 0; i < size; i++){
        printf("Item %zu:\nname: %s - number: %d\n",
            i,
            stack->elements[i].name, 
            stack->elements[i].number);
    }
}
