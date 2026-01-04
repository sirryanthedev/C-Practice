// (ex. 8.1.4)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 5

int main(){

    struct student{
        char name[25];
        int number;
    };

    // students is an array of N elements where each element is a pointer to struct student (initialise pointers at null)
    struct student* students[N] = {NULL};

    // create a pointer to struct student, student 1 and dynamically alocate memory for it
    struct student* student1 = (struct student*)malloc(sizeof(struct student));
    if (!student1){
        puts("Memory allocation went wrong...");
        return 1;
    }
    strcpy(student1->name, "Joe");
    student1->number = 120;

    // fill students array at the first occurence of null with student 1
    for (size_t i = 0; i < N; i++){
        if (students[i] == NULL){
            students[i] = student1;
            break;
        }
    }

    // create a pointer to struct student, student 2 and dynamically alocate memory for it
    struct student* student2 = (struct student*)malloc(sizeof(struct student));
    if (!student2){
        puts("Memory allocation went wrong...");
        return 1;
    }
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
            free(students[i]); // free dam for instance of student struct
        }
    }

    free(students); // free dam for students array

    return 0;
}