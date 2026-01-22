#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "io.h"
#include "calendar.h"
#include "appointment.h"

void run(calendar* cal){
    // invalid arg
    if (!cal) return;

    char command[32];

    // read commands until EOF or QUIT
    while (scanf("%31s", command) == 1){

        // ADD command
        if (strcmp(command, "ADD") == 0){
            int date, start, duration;
            char title[128];

            // parse fixed fields
            if (scanf("%d %d %d", &date, &start, &duration) != 3) continue;

            getchar(); // consume space/newline
            if (!fgets(title, sizeof(title), stdin)) continue;
            title[strcspn(title, "\n")] = '\0';

            // compute end time from duration
            int end_h = start / 100;
            int end_m = start % 100;
            end_m += duration;
            end_h += end_m / 60;
            end_m %= 60;
            int end = end_h * 100 + end_m;

            // create appointment
            appointment* app = create_appointment(date, start, end, title, NULL, NULL);
            if (!app) continue;

            if (!add_appointment(cal, app)){
                destroy_appointment(app); // leak prevention
            }
        }

        // REMOVE appointment by date and ID
        else if (strcmp(command, "REMOVE") == 0){
            int date, ID;
            if (scanf("%d %d", &date, &ID) != 2) continue;

            appointment* app = find_appointment(cal, date, ID);
            if (app){
                remove_appointments_in_range(cal, date, date); // only this day
                printf("Appointment removed.\n");
            }
        }

        // CLEAR calendar
        else if (strcmp(command, "CLEAR") == 0){
            clear_calendar(cal);
            printf("Calendar cleared.\n");
        }

        // PRINT_DAY
        else if (strcmp(command, "PRINT_DAY") == 0){
            int date;
            if (scanf("%d", &date) != 1) continue;
            print_appointments_on_day(cal, date);
        }

        // PRINT_RANGE
        else if (strcmp(command, "PRINT_RANGE") == 0){
            int start, end;
            if (scanf("%d %d", &start, &end) != 2) continue;
            print_appointments_in_range(cal, start, end);
        }

        // SEARCH by title substring
        else if (strcmp(command, "SEARCH") == 0){
            char str[128];
            getchar(); // consume space
            if (!fgets(str, sizeof(str), stdin)) continue;
            str[strcspn(str, "\n")] = '\0';
            search_appointments_by_title(cal, str);
        }

        // FIND date ID
        else if (strcmp(command, "FIND") == 0){
            int date, ID;
            if (scanf("%d %d", &date, &ID) != 2) continue;
            appointment* app = find_appointment(cal, date, ID);
            if (app){
                print_appointment(app);
                printf("\n");
            }
        }

        // PRINT_ALL
        else if (strcmp(command, "PRINT_ALL") == 0){
            print_calendar(cal);
        }

        // IMPORT file
        else if (strcmp(command, "IMPORT") == 0){
            char path[256];
            getchar(); // consume space
            if (!fgets(path, sizeof(path), stdin)) continue;
            path[strcspn(path, "\n")] = '\0';
            if (import_calendar(cal, path)){
                printf("Calendar imported.\n");
            } else {
                printf("Failed to import.\n");
            }
        }

        // EXPORT file
        else if (strcmp(command, "EXPORT") == 0){
            char path[256];
            getchar();
            if (!fgets(path, sizeof(path), stdin)) continue;
            path[strcspn(path, "\n")] = '\0';
            if (export_calendar(cal, path)){
                printf("Calendar exported.\n");
            } else {
                printf("Failed to export.\n");
            }
        }

        // HELP
        else if (strcmp(command, "HELP") == 0){
            printf("Calendar commands:\n");
            printf("  ADD <date> <start> <duration> <title>      - Add appointment\n");
            printf("  REMOVE <date> <ID>                         - Remove appointment by date and ID\n");
            printf("  CLEAR                                      - Remove all appointments\n");
            printf("  PRINT_DAY <date>                           - Print all appointments on a specific day\n");
            printf("  PRINT_RANGE <start_date> <end_date>        - Print appointments in date range\n");
            printf("  SEARCH <string>                            - Search appointments by title string\n");
            printf("  FIND <date> <ID>                           - Find appointment by date and ID\n");
            printf("  PRINT_ALL                                  - Print all appointments in chronological order\n");
            printf("  IMPORT <filepath>                          - Import calendar from file\n");
            printf("  EXPORT <filepath>                          - Export calendar to file\n");
            printf("  QUIT                                       - Exit the program\n");
            printf("  HELP                                       - Show this help page\n");
            printf("\nNotes:\n");
            printf("  - Time format: hhmm without leading zeroes (e.g., 930 for 09:30)\n");
            printf("  - Date format: YYYYMMDD (e.g., 20260118)\n");
            printf("  - Title may contain spaces\n");
        }

        // QUIT
        else if (strcmp(command, "QUIT") == 0){
            return;
        }

        // unknown command
        else {
            printf("Unknown command. Type HELP for available commands.\n");
        }
    }
}
