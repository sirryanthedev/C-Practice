#include <stdio.h>
#include <string.h>

#include <stdlib.h> // for dynamic malloc, free etc.
#include "appointment.h" // corresponding header file

appointment* create_appointment(int date, int time_b, int time_e, char* title, char* optional_description, char* location){
    // number of appointments
    static int counter = 0;  

    // negative hours or hours >= 24 - invalid
    if (time_b >= 2400 || time_e >= 2400){
        puts("The hours can't exceed 24...");
        return NULL;
    }
    if (time_b < 0 || time_e < 0){
        puts("Hours can't be negative...");
        return NULL;
    }

    // negative minutes already checked in conditions above

    // minutes >= 60 - invalid
    if ((time_b % 100) >= 60 || (time_e % 100) >= 60){
        puts("Minutes must be less than 60...");
        return NULL;
    }

    // invalid times
    if (time_b >= time_e){
        puts("The start time must be less than the end time");
        return NULL;
    }

    // allocate memory on the heap for the new appointment
    appointment* new_appointment = malloc(sizeof(appointment));

    // failure
    if (!new_appointment) return NULL;

    // initialise pointers to NULL
    new_appointment->title = NULL;
    new_appointment->optional_description = NULL;
    new_appointment->location = NULL;

    // insert user-data
    new_appointment->date = date;
    new_appointment->time_b = time_b;
    new_appointment->time_e = time_e;

    // failure
    if (!title){
        destroy_appointment(new_appointment);
        return NULL;
    }

    // title
    char* tmp = malloc(strlen(title) + 1); // reserve extra space for the '\0'
    if (!tmp) {
        destroy_appointment(new_appointment);
        return NULL; // failure
    }
    new_appointment->title = tmp; // succes
    strcpy(new_appointment->title, title); // place string in appointment

    // optional description
    if (optional_description){
        tmp = malloc(strlen(optional_description) + 1); // reserve extra space for the '\0'
        if (!tmp){
            destroy_appointment(new_appointment);
            return NULL; // failure
        }
        new_appointment->optional_description = tmp; // succes
        strcpy(new_appointment->optional_description, optional_description); // place string in appointment
    }

    // location
    if (location){
        tmp = malloc(strlen(location) + 1); // reserve extra space for the '\0'
        if (!tmp){
            destroy_appointment(new_appointment);
            return NULL; // failure
        }
        new_appointment->location = tmp; // succes
        strcpy(new_appointment->location, location); // place string in appointment
    }

    // ID
    new_appointment->ID = ++counter; // only at success increment counter

    return new_appointment;
}

void destroy_appointment(appointment* appointment_p){
    // base case: nothing to do
    if (appointment_p == NULL) return;

    // the node's properties
    if (appointment_p->title){
        free(appointment_p->title);
    }   
    
    if (appointment_p->optional_description){
        free(appointment_p->optional_description);
    }

    if (appointment_p->location){
        free(appointment_p->location);
    }
    
    // the node itself
    free(appointment_p);
}

void print_date(int date, int time_b, int time_e){
    // extract info
    int year = date/10000; // last 4 digits
    int month = (date/100) % 100; // remove last 2 digits, then get the last 2 digits of the number without the removed digits
    int day = date % 100; // last 2 digits

    int hours_b = (time_b / 100); // first 2 digits
    int min_b = (time_b % 100); // last 2 digits

    int hours_e = (time_e / 100); // first 2 digits
    int min_e = (time_e % 100); // last 2 digits

    // output format yyyy/mm/dd hh:mm hh:mm with leading 0's
    printf("%d-%02d-%02d %02d:%02d %02d:%02d\n", year, month, day, hours_b, min_b, hours_e, min_e);
} 

void print_appointment(appointment* appointment_p){
    // failure
    if (!appointment_p) return;

    // ID
    printf("ID: %d\n", appointment_p->ID);

    // Date including start and end time
    printf("When: ");
    print_date(appointment_p->date, appointment_p->time_b, appointment_p->time_e);

    // title
    if (appointment_p->title){
        printf("Title: %s\n", appointment_p->title);
    }

    // optional description
    if (appointment_p->optional_description){
        printf("Description: %s\n", appointment_p->optional_description);
    }

    // description of the location
    if (appointment_p->location){
        printf("Location: %s\n", appointment_p->location);
    }
}

int compare_appointments(const void* a, const void* b){
    const appointment* app_1 = *(const appointment**)a;
    const appointment* app_2 = *(const appointment**)b;

    // First: compare date
    if (app_1->date != app_2->date){
        return (app_1->date - app_2->date);
    }

    // Date is equal -> compare start time
    if (app_1->time_b != app_2->time_b){
        return (app_1->time_b - app_2->time_b);
    }

    // Date and start time equal -> compare ID
    return (app_1->ID - app_2->ID);
}