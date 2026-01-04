// (ex. 8.1.6)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 5

int main(){

    struct student{
        char* name; // pointer to dynamically allocated string
        int number;
    };

    // dynamically allocated array (** because each element of array(*) is a pointer to struct student(*))
    struct student** students = malloc(sizeof(struct student*) * N);

    // initialise each element to NULL
    for (size_t i = 0; i < N; i++){
        students[i] = NULL;
    }

    // create a pointer to struct student, student 1 and dynamically alocate memory for it
    struct student* student1 = malloc(sizeof(struct student));
    if (!student1){
        puts("Memory allocation went wrong...");
        return 1;
    }
    student1->name = malloc(sizeof(char) * 25); // dynamically allocate 25 bytes of memory for char*name
    strcpy(student1->name, "Joe");
    student1->number = 120;

    // fill students array at the first occurence of null with student 1
    for (size_t i = 0; i < N; i++){
        if (students[i] == NULL){
            students[i] = student1;
            break;
        }
    }

    // create a pointer to struct student, student 2 and dynamically allocate memory for it
    struct student* student2 = (struct student*)malloc(sizeof(struct student));
    if (!student2){
        puts("Memory allocation went wrong...");
        return 1;
    }
    student2->name = malloc(sizeof(char) * 25); // dynamically allocate 25 bytes of memory for char*name
    strcpy(student2->name, "Jeff");
    student2->number = 20;
    
    // fill students array at the first occurence of null with student 2
    for (size_t i = 0; i < N; i++){
        if (students[i] == NULL){
            students[i] = student2;
            break;
        }
    }    

    // if students[i] is initialised, i.e. not NULL, free dynamically allocated memory linked to it
    for (size_t i = 0; i < N; i++){
        if (students[i] != NULL){
            free(students[i]->name); // free dam for name
            free(students[i]); // free dam for struct linked to pointer
        }
    }

    free(students); // free dam for array students
    return 0;
}