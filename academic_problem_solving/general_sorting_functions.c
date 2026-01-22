#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// random struct to implement sorting implementation
typedef struct{
    char* name; // string
    int number; // integer
}temp;

int compare_int_ascending(const void* a, const void* b);
int compare_int_descending(const void* a, const void* b);

int compare_str_alphabetically_ascending(const void* a, const void* b);
int compare_str_alphabetically_descending(const void* a, const void* b);
int compare_str_length_ascending(const void* a, const void* b);
int compare_str_length_descending(const void* a, const void* b);

// NOTE: no subtraction in code to prevent undefined behaviour (best practice)
int compare_double_ascending(const void* a, const void* b);
int compare_double_descending(const void* a, const void* b);

int compare_struct_int_ascending(const void* a, const void* b);
int compare_struct_int_descending(const void* a, const void* b);
int compare_struct_string_alpha_ascending(const void* a, const void* b);
int compare_struct_string_alpha_descending(const void* a, const void* b);
int compare_struct_string_length_ascending(const void* a, const void* b);
int compare_struct_string_length_descending(const void* a, const void* b);
int compare_struct_number_then_string(const void* a, const void* b);

int compare_array_structs_by_int_then_string(const void* a, const void* b);

int main(){

    puts("This file contains all sorts of sorting functions!");

    return 0;
}

int compare_int_ascending(const void* a, const void* b){
    const int x = *(const int*)a;
    const int y = *(const int*)b;
    return (x - y);
}

int compare_int_descending(const void* a, const void* b){
    const int x = *(const int*)a;
    const int y = *(const int*)b;
    return (y - x);
}

int compare_str_alphabetically_ascending(const void* a, const void* b){
    const char* x = *(const char**)a;
    const char* y = *(const char**)b;
    return strcmp(x, y);
}

int compare_str_alphabetically_descending(const void* a, const void* b){
    const char* x = *(const char**)a;
    const char* y = *(const char**)b;
    return strcmp(y, x);
}

int compare_str_length_ascending(const void* a, const void* b){
    const char* x = *(const char**)a;
    const char* y = *(const char**)b;
    return (strlen(x) - strlen(y));
}

int compare_str_length_descending(const void* a, const void* b){
    const char* x = *(const char**)a;
    const char* y = *(const char**)b;
    return (strlen(y) - strlen(x));
}

int compare_double_ascending(const void* a, const void* b){
    const double x = *(const double*)a;
    const double y = *(const double*)b;
    if (x > y) return 1;
    if (x < y) return -1;
    return 0;
}

int compare_double_descending(const void* a, const void* b){
    const double x = *(const double*)a;
    const double y = *(const double*)b;
    if (y > x) return 1;
    if (y < x) return -1;
    return 0;
}

int compare_struct_int_ascending(const void* a, const void* b){
    const temp* x = a;
    const temp* y = b;
    return ((x->number) - (y->number));
}

int compare_struct_int_descending(const void* a, const void* b){
    const temp* x = a;
    const temp* y = b;
    return ((y->number) - (x->number));
}

int compare_struct_string_alpha_ascending(const void* a, const void* b){
    const temp* x = a;
    const temp* y = b;
    return strcmp((x->name), (y->name)); 
}

int compare_struct_string_alpha_descending(const void* a, const void* b){
    const temp* x = a;
    const temp* y = b;
    return strcmp((y->name), (x->name));
}

int compare_struct_string_length_ascending(const void* a, const void* b){
    const temp* x = a;
    const temp* y = b;
    return (strlen(x->name) - strlen(y->name));
}
int compare_struct_string_length_descending(const void* a, const void* b){
    const temp* x = a;
    const temp* y = b;
    return (strlen(y->name) - strlen(x->name));
}

int compare_struct_number_then_string(const void* a, const void* b){
    const temp* x = a;
    const temp* y = b;
    // first sort by int
    if (x->number > y->number) return 1;
    if (x->number < y->number) return -1;
    // numbers are equal -> sort by string
    return strcmp(x->name, y->name);
}

int compare_array_structs_by_int_then_string(const void* a, const void* b){
    const temp* x = *(const temp**)a; // dereference-typecast *(..) because we have an array of this type (struct)
    const temp* y = *(const temp**)b;
    // first sort by int
    if (x->number > y->number) return 1;
    if (x->number < y->number) return -1;
    // numbers are equal -> sort by string
    return strcmp(x->name, y->name);
}