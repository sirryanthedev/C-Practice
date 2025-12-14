// (ex. 6.1.4)

#include <stdio.h>

struct student{
    char *name;
    int number;
};

void printstudent(struct student* s1);

void sort_student(struct student students[], int size);

int main(){
    // array of student structs
    struct student students[] = 
    {
     {"bob", 234},
     {"dan", 222}, 
     {"evan", 301}
    };

    // amount of student structs (elements) in array
    int size = sizeof(students) / sizeof(students[0]);

    // print array of structs before sorting
    for (size_t i = 0; i < size; i++){
        printstudent(&students[i]);
    }

    // call function to sort structs
    sort_student(students, size);

    printf("\n------------\n");

    // print array of structs after sorting
    for (size_t i = 0; i < size; i++){
        printstudent(&students[i]);
    }

    return 0;
}

void printstudent(struct student* s1){
    printf("%s %d  ", s1->name, s1->number);
}

void sort_student(struct student students[], int size){
    int swapped = 1;
    struct student temp;
    while (swapped){
        swapped = 0;
        for (size_t i = 0; i < size - 1; i++){
            if (students[i].number > students[i + 1].number){
                temp = students[i];
                students[i] = students[i + 1];
                students[i + 1] = temp;
                swapped = 1;
            }
        }
        size--;
    }
}