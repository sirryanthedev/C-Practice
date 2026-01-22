#ifndef APPOINTMENT_H // include guard 1/2
#define APPOINTMENT_H

// architecture for appointment
typedef struct appointment{
    int ID; // unique identifier
    int date; // yyyy/mm/dd e.g. 20260118 (Jan 18 of 2026)
    int time_b; // start of appointment hh:mm 24h-format e.g.  NO LEADING ZEROES 930 INSTEAD OF 0930
    int time_e; // end of apppointment format analog to that of time_b

    // no newlines in these fields
    char* title; // name of the appointment max. 100 characters
    char* optional_description; // max. 300 characters
    char* location; // description of the location - max. 100 characters
} appointment;

// function prototypes
appointment* create_appointment(int date, int time_b, int time_e, char* title, char* optional_description, char* location);
void destroy_appointment(appointment* appointment_p);
int compare_appointments(const void* a, const void* b); // compatible with qsort
void print_appointment(appointment* appointment_p);

#endif // include guard 2/2