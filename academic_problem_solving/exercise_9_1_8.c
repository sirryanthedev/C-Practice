#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// node architecture
struct node{
    int i; // data to hold (an int)
    struct node* next; // pointer to the next node
};

struct node* add_front(struct node* list, int i); // add a new head to the list
bool del_node(struct node** list, int i); // delete a node with int i (2nd arg)
void print_nodes(const struct node* head); // output the linked list
struct node* add_sorted(struct node* head, int number); // add number at the correct position of a sorted list of numbers
void remove_once(struct node **list, int i); // remove first instance of a node with int i

int main(){

    // edge case, linked list is empty
    struct node* head = NULL;

    // create linked-list (4-1-2-3-4) and not (4-2-3-1-4) because of add_sorted
    head = add_front(head, 4);
    head = add_sorted(head, 1);
    head = add_sorted(head, 3);
    head = add_sorted(head, 2);
    head = add_front(head, 4);

    remove_once(&head, 4); // in linked-list (4-1-2-3-4) remove the first occurence of 4 -> 1-2-3-4

    print_nodes(head); // output the linked list (1-2-3-4)

    // free memory on heap used for the linked list
    while (head){
        struct node* temp = head;
        head = head -> next;
        free(temp);
    }

    return 0;
}

struct node* add_front(struct node* list, int i){
    // create a new head, head, and reserve memory for it on the heap
    struct node* head = malloc(sizeof(struct node));
    if (!head) return NULL; // error-handling (return NULL instead of e.g. 1 because return type is of * and type of NULL is void* while that of 1 is int)

    head->i = i; // assign input i to head->i
    head->next = list; // point head->next to list (existing node)

    // return new head
    return head;
}

bool del_node(struct node** list, int i){
    struct node* p = *list;
    struct node* q = NULL;

    while ((p != NULL) && (p->i) != i){
        q = p;
        p = p->next;
    }

    // c not found
    if (p == NULL) return false;

    // c found
    if (q == NULL) *list = (*list) -> next; // first element to be deleted - update head
    else q->next = p->next; // link previous node to the next node

    free(p); // free memory on heap associated with deleted node
    return true;
}

void print_nodes(const struct node* head){
    // initialise pointer to head
    const struct node* p = head;

    // use p to hover over the list until p == NULL, i.e. end of the list is reached
    while (p != NULL){
        printf("%d\n", p->i);
        p = p->next;
    }
}

struct node* add_sorted(struct node* head, int number){
    struct node* p = head;// pointer to traverse linked list

    // add a new head with number (2nd arg)
    if (p == NULL || number < p->i){ // empty list or number is less than that of first node
        struct node* new_head = malloc(sizeof(struct node));
        if (!new_head) return NULL;

        new_head->i = number;
        new_head->next = p;
        return new_head;
    }
    
    while (true){
        if (p->next == NULL){
            struct node* new_node = malloc(sizeof(struct node));
            if (!new_node) return NULL;

            new_node->i = number;
            new_node->next = p->next;

            p->next = new_node;

            return head;
        }

        if (number < p->next->i){
            struct node* new_node = malloc(sizeof(struct node));
            if (!new_node) return NULL;

            new_node->i = number;
            new_node->next = p->next;
            p->next = new_node;

            return head;
        }
        else
            p = p->next;
    }

    return head;
}

void remove_once(struct node **list, int i){
    
    // nothing to remove
    if (list == NULL || *list == NULL) return; // pointer to pointer is NULL or node points to nothing

    // remove first node
    if ((*list)->i == i){ // ->i of first node equals int i (2nd arg)
        struct node* first = *list;
        *list = (*list)->next; // update head to 2nd node
        free(first);
    }

    // remove node in the middle or at the end
    else { // first node is not NULL, but first node->i != (2nd arg)
        struct node* p = *list;
        struct node* q = NULL; // initialise q with NULL for safety
        while ((p != NULL) && (p->i != i)){
            q = p;
            p = p -> next;
        }
        if (p != NULL) { // p->i == i
            q->next = p->next; // link previous node to next node
            free(p); // free memory on the heap for the node inbetween
        }
    }
}