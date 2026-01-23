#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATE_LEN 11 // yyyy/mm/dd

typedef struct Date{
    char ymd[DATE_LEN];
} Date;

typedef struct Node{
    struct Date* date;
    struct Node* prev;
    struct Node* next;
} Node;

void insert_dates_from_file(char* file_name, Node** head); // first function
void sort_list(Node** head);
void add_node(Node** head, Date* date);
void print_list(Node* head);
void free_memory(Node* head);
int compare_dates(const void* a, const void* b);

int main(int argc, char** argv){

    if (argc != 2){
        puts("Incorrect format");
        return 1;
    }

    Node* head = NULL;

    insert_dates_from_file(argv[1], &head);

    sort_list(&head);

    print_list(head);

    free_memory(head);

    return 0;
}

void add_node(Node** head, Date* date){
    Node* new_node = malloc(sizeof(Node));
    if (!new_node){
        puts("Error allocating memory for new node");
        return;
    }
    new_node->date = date;
    new_node->prev = NULL;
    new_node->next = *head;

    if (*head) (*head)->prev = new_node;
    (*head) = new_node;
}

void print_list(Node* head){
    if (head == NULL){
        puts("The list is empty");
        return;
    }
    Node* p = head;
    while (p){
        printf("%s\n", p->date->ymd);
        p = p->next;
    }
}

void free_memory(Node* head){
    Node* p = head;
    while (p){
        Node* temp = p->next;
        free(p->date);
        free(p);
        p = temp;
    }
}

void insert_dates_from_file(char* file_name, Node** head){
    FILE* fp = fopen(file_name, "r");
    if (!fp){
        puts("Error opening file");
        return;
    }

    char buffer[11];
    char line_buffer[100];
    int year, month, day;

    while (fgets(line_buffer, sizeof(line_buffer), fp)){
        if (sscanf(line_buffer, "%4d/%02d/%02d", &year, &month, &day) == 3){
            sprintf(buffer, "%4d/%02d/%02d", year, month, day);
            Date* date = malloc(sizeof(Date));
            if (!date){
                puts("Error creating date");
                return;
            }
            strcpy(date->ymd, buffer);
            add_node(head, date);
        }
    }
    fclose(fp);
}

int compare_dates(const void* a, const void* b){
    const Node* x = *(const Node**)a;
    const Node* y = *(const Node**)b;
    return strcmp(x->date->ymd, y->date->ymd);
}

void sort_list(Node** head){
    // no sorting
    if (!head || !(*head)) return;

    // count number of nodes
    Node* p = *head;
    int number_elements = 0;
    while (p){
        number_elements += 1;
        p = p->next;
    }

    // create an array of all nodes
    Node* all_nodes[number_elements];
    p = *head;
    int idx = 0;
    while (p){
        all_nodes[idx] = p;
        p = p->next;
        idx++;
    }

    // sort the array by date
    qsort(all_nodes, number_elements, sizeof(Node*), compare_dates);

    // relink the items of the list (sorting)
    *head = all_nodes[0];
    (*head)->prev = NULL;
    for (size_t i = 0; i < number_elements - 1; i++){
        all_nodes[i]->next = all_nodes[i + 1];
        all_nodes[i + 1]->prev = all_nodes[i];
    }
    all_nodes[number_elements - 1]->next = NULL;
}