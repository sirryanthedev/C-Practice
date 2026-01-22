#include <stdio.h>
#include <stdlib.h> // malloc!

#include "calendar.h"
#include "tree.h"
#include "appointment.h"

// helpers (static - visibility limited to this file)
static int get_year(int date){ // extract year from yyyymmdd
    return (date / 10000);
}

static int get_month(int date){ // extract month from yyyymmdd
    return ((date / 100) % 100);
}


static int get_day(int date){ // extract day from yyyymmdd
    return (date % 100);
}

static node* find_child(node* parent, int value){ // find a child with a certain value (2nd arg)
    if (!parent) return NULL;

    node* curr = parent->first_child;
    while (curr){
        if (*(int*)curr->data == value){
            return curr;
        }
        curr = curr->siblings;
    }
    return NULL;
}

static void destroy_tree(node* n){ // destroy tree recursively
    if (!n) return;

    // children & siblings first
    destroy_tree(n->first_child);
    destroy_tree(n->siblings);

    // free node data
    if (n->type == APPOINTMENT){
        destroy_appointment((appointment*)n->data);
    }
    else if (n->data){
        free(n->data); // integers: year/month/day
    }

    free(n);
}

void destroy_calendar(calendar* cal){
    // invalid argument
    if (!cal) return;

    // delete tree recursively
    destroy_tree(cal->root);

    // free memory on the heap reserved for the tree
    free(cal);
}

// calendar
calendar* create_calendar(void){
    // reserve memory on the heap for the calendar
    calendar* cal = malloc(sizeof(calendar));
    // failure
    if (!cal) return NULL;

    // create root node
    cal->root = create_node(ROOT, NULL);
    // failure
    if (!cal->root){
        free(cal);
        return NULL;
    }

    return cal;
}

appointment* find_appointment(calendar* cal, int date, int ID){
    // failure
    if (!cal) return NULL;

    int year  = get_year(date);
    int month = get_month(date);
    int day   = get_day(date);

    node* year_node = find_child(cal->root, year);
    if (!year_node) return NULL;

    node* month_node = find_child(year_node, month);
    if (!month_node) return NULL;

    node* day_node = find_child(month_node, day);
    if (!day_node) return NULL;

    node* curr = day_node->first_child;
    while (curr){
        appointment* app = (appointment*)curr->data;
        if (app->ID == ID){
            return app;
        }
        curr = curr->siblings;
    }

    return NULL;
}

// add appointment
int add_appointment(calendar* cal, appointment* app){
    // failure
    if (!cal || !app) return 0;

    // extract year, month, and day from date (yyyymmdd)
    int year = get_year(app->date);
    int month = get_month(app->date);
    int day = get_day(app->date);

    // year
    node* year_node = find_child(cal->root, year);
    if (!year_node){
        int* y = malloc(sizeof(int));
        if (!y) return 0;
        *y = year;

        year_node = create_node(YEAR, y);
        if (!year_node){
            free(y); // prevent memory leak
            return 0;
        }

        add_child_sorted(cal->root, year_node);
    }

    // month
    node* month_node = find_child(year_node, month);
    if (!month_node){
        int* m = malloc(sizeof(int));
        if (!m) return 0;
        *m = month;

        month_node = create_node(MONTH, m);
        if (!month_node){
            free(m); // prevent memory leak
            return 0;
        }

        add_child_sorted(year_node, month_node);
    }

    // day
    node* day_node = find_child(month_node, day);
    if (!day_node){
        int* d = malloc(sizeof(int));
        if (!d) return 0;
        *d = day;

        day_node = create_node(DAY, d);
        if (!day_node){
            free(d); // prevent memory leak
            return 0;
        }

        add_child_sorted(month_node, day_node);
    }

    // appointment
    node* app_node = create_node(APPOINTMENT, app);
    if (!app_node) return 0;

    add_child_sorted(day_node, app_node);

    return 1;
}

// helper
static void print_tree(node* n){
    // invalid input (arg)
    if (!n) return;

    if (n->type == APPOINTMENT){
        print_appointment((appointment*)n->data);
        printf("\n");
    }

    print_tree(n->first_child);
    print_tree(n->siblings);
}

void print_calendar(calendar* cal){
    // invalid input (arg)
    if (!cal) return;

    print_tree(cal->root);
}

void print_appointments_on_day(calendar* cal, int date){
    // failure
    if (!cal) return;

    int year  = get_year(date);
    int month = get_month(date);
    int day   = get_day(date);

    node* year_node = find_child(cal->root, year);
    if (!year_node) return;

    node* month_node = find_child(year_node, month);
    if (!month_node) return;

    node* day_node = find_child(month_node, day);
    if (!day_node) return;

    node* curr = day_node->first_child;
    while (curr){
        print_appointment((appointment*)curr->data);
        printf("\n");
        curr = curr->siblings;
    }
}

// clear the entire calendar
void clear_calendar(calendar* cal){
    // invalid argument
    if (!cal) return;

    // delete all children of root
    node* child = cal->root->first_child;
    destroy_tree(child);

    // reset root pointer
    cal->root->first_child = NULL;
}

int remove_appointments_in_range(calendar* cal, int start_date, int end_date){
    if (!cal) return 0;

    node* year_node = cal->root->first_child;
    while (year_node){
        node* month_node = year_node->first_child;
        while (month_node){
            node* day_node = month_node->first_child;
            node* prev_day_node = NULL;

            while (day_node){
                // check if this day is in range
                // int day_val = *(int*)day_node->data;
                // int full_date = *(int*)day_node->data; // tree stores int YYYYMMDD?
                // NOTE: we’ll get full date from first appointment
                int remove_day = 0;
                node* app_node = day_node->first_child;
                while (app_node){
                    appointment* app = (appointment*)app_node->data;
                    if (app->date >= start_date && app->date <= end_date){
                        remove_day = 1;
                        break;
                    }
                    app_node = app_node->siblings;
                }

                node* next_day = day_node->siblings;

                if (remove_day){
                    destroy_tree(day_node);
                    if (prev_day_node){
                        prev_day_node->siblings = next_day;
                    } else {
                        month_node->first_child = next_day;
                    }
                } else {
                    prev_day_node = day_node;
                }

                day_node = next_day;
            }

            month_node = month_node->siblings;
        }

        year_node = year_node->siblings;
    }

    return 1; // success
}

void print_appointments_in_range(calendar* cal, int start_date, int end_date){
    // failure
    if (!cal) return;

    node* year_node = cal->root->first_child;
    while (year_node){
        node* month_node = year_node->first_child;
        while (month_node){
            node* day_node = month_node->first_child;
            while (day_node){
                node* app_node = day_node->first_child;
                while (app_node){
                    appointment* app = (appointment*)app_node->data;
                    if (app->date >= start_date && app->date <= end_date){
                        print_appointment(app);
                        printf("\n");
                    }
                    app_node = app_node->siblings;
                }
                day_node = day_node->siblings;
            }
            month_node = month_node->siblings;
        }
        year_node = year_node->siblings;
    }
}

void search_appointments_by_title(calendar* cal, const char* search_str){
    // invalid input (args)
    if (!cal || !search_str) return;

    node* year_node = cal->root->first_child;
    while (year_node){
        node* month_node = year_node->first_child;
        while (month_node){
            node* day_node = month_node->first_child;
            while (day_node){
                node* app_node = day_node->first_child;
                while (app_node){
                    appointment* app = (appointment*)app_node->data;
                    if (app->title && strstr(app->title, search_str)){
                        print_appointment(app);
                        printf("\n");
                    }
                    app_node = app_node->siblings;
                }
                day_node = day_node->siblings;
            }
            month_node = month_node->siblings;
        }
        year_node = year_node->siblings;
    }
}

// import calendar from a file
int import_calendar(calendar* cal, const char* filepath){
    // invalid input (args)
    if (!cal || !filepath) return 0;

    // open file in read mode
    FILE* f = fopen(filepath, "r");
    // opening the file failed
    if (!f) return 0; // file not found

    // temporary variables for reading
    int date, start, end;
    char title[128];

    while (fscanf(f, "%d %d %d", &date, &start, &end) == 3){
        // read title
        int c;
        int i = 0;
        while ((c = fgetc(f)) != '\n' && c != EOF && i < 127){
            title[i++] = (char)c;
        }
        title[i] = '\0';

        appointment* app = create_appointment(date, start, end, title, NULL, NULL);
        if (app) add_appointment(cal, app);
    }

    // close the file
    fclose(f);
    return 1;
}

// export calendar to a file
int export_calendar(calendar* cal, const char* filepath){
    // invalid input (args)
    if (!cal || !filepath) return 0;

    // open file in write mode
    FILE* f = fopen(filepath, "w");
    // opening the file failed
    if (!f) return 0;

    node* year_node = cal->root->first_child;
    while (year_node){
        node* month_node = year_node->first_child;
        while (month_node){
            node* day_node = month_node->first_child;
            while (day_node){
                node* app_node = day_node->first_child;
                while (app_node){
                    appointment* app = (appointment*)app_node->data;
                    // write date start end title
                    fprintf(f, "%d %d %d %s\n", app->date, app->time_b, app->time_e, app->title ? app->title : "");
                    app_node = app_node->siblings;
                }
                day_node = day_node->siblings;
            }
            month_node = month_node->siblings;
        }
        year_node = year_node->siblings;
    }

    // close the file
    fclose(f);
    return 1;
}