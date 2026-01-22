#ifndef CALENDAR_H // include guard 1/2
#define CALENDAR_H

#include <string.h>

#include "tree.h"
#include "appointment.h"

typedef struct {
    node* root; // root of the tree
} calendar;

// manipulate calendar
calendar* create_calendar(void);        // create calendar
void destroy_calendar(calendar* cal);   // delete calendar
void clear_calendar(calendar* cal);     // remove all appointments

// manipulate appointments - returns 1 = success, 0 = failure
int add_appointment(calendar* cal, appointment* app);
int remove_appointments_in_range(calendar* cal, int start_date, int end_date);

// search
appointment* find_appointment(calendar* cal, int date, int ID); // date and ID
void search_appointments_by_title(calendar* cal, const char* search_str);

// output/print
void print_appointments_on_day(calendar* cal, int date);           // specific day
void print_appointments_in_range(calendar* cal, int start, int end);// date range
void print_calendar(calendar* cal);                                // all appointments

// import/export
int import_calendar(calendar* cal, const char* filepath);
int export_calendar(calendar* cal, const char* filepath);

#endif // include guard 2/2
