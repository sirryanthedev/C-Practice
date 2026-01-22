#include <stdio.h>
#include <stdlib.h>

#include "calendar.h"
#include "io.h"

int main(void){
    // create calendar
    calendar* cal = create_calendar();
    if (!cal){
        fprintf(stderr, "Failed to create calendar.\n");
        return 1;
    }

    // run I/O loop
    run(cal);

    // cleanup
    destroy_calendar(cal);

    return 0;
}