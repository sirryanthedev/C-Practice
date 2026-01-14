#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// node architecture
    struct node{
        char c; // data to hold (a character)
        struct node* next; // pointer to the next node
    };

struct node* add_front(struct node* list, char c); // add a new head to the list
bool del_node(struct node** list, char c); // delete a node with char c (2nd arg)
void print_nodes(const struct node* head); // output the linked list

int main(){
    // create an initial node, head, which points to NULL
    struct node* head = NULL; 
    // add nodes to head, backwards, because it gets ordered like a stack (LIFO)
    head = add_front(head, 'D');
    head = add_front(head, 'C');
    head = add_front(head, 'B');
    head = add_front(head, 'A');

    del_node(&head, 'B'); // delete the node in which p->c == 'B'

    print_nodes(head); // output the linked list

    // free memory on heap used for the linked list
    while (head){
        struct node* temp = head;
        head = head -> next;
        free(temp);
    }

    return 0;
}

struct node* add_front(struct node* list, char c){
    // create a new head, head, and reserve memory for it on the heap
    struct node* head = malloc(sizeof(struct node));
    if (!head) return NULL; // error-handling (return NULL instead of e.g. 1 because return type is of * and type of NULL is void* while that of 1 is int)

    head->c = c; // assign input c to head->c
    head->next = list; // point head->next to list (existing node)

    // return new head
    return head;
}

bool del_node(struct node** list, char c){
    struct node* p = *list;
    struct node* q = NULL;

    while ((p != NULL) && (p->c) != c){
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
        printf("%c\n", p->c);
        p = p->next;
    }
}