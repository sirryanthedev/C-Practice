#include <stdio.h>
#include <string.h>

typedef enum month {JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC} month;
int days_in_month(month m);
int string_to_month(const char* s, month* m);

int main(int argc, char* argv[]){

    for (int i = 1; i < argc; i++){
        month m;
        if (string_to_month(argv[i], &m)) printf("%s: %d\n", argv[i], days_in_month(m));
        else printf("invalid month: %s\n", argv[i]);
    }

    return 0;
}

int days_in_month(month m){
    switch (m)
    {

    case JAN:
        return 31;
    
    case FEB:
        return 28;
    
    case MAR:
        return 31;
    
    case APR:
        return 30;
    
    case MAY:
        return 31;

    case JUN:
        return 30;
    
    case JUL:
        return 31;

    case AUG:
        return 31;

    case SEP:
        return 30;

    case OCT:
        return 31;

    case NOV:
        return 30;

    case DEC:
        return 31;
    
    default:
        return -1;
    }
}

int string_to_month(const char* s, month* m){   // s is a string (pointer to char) in practice it's argv[i], m is &m where the month will be placed in converted, enum format
    if (strcmp(s, "JAN") == 0) *m = JAN;

    else if (strcmp(s, "FEB") == 0) *m = FEB;

    else if (strcmp(s, "MAR") == 0) *m = MAR;

    else if (strcmp(s, "APR") == 0) *m = APR;

    else if (strcmp(s, "MAY") == 0) *m = MAY;

    else if (strcmp(s,"JUN") == 0) *m = JUN;

    else if (strcmp(s, "JUL") == 0) *m = JUL;

    else if (strcmp(s, "AUG") == 0) *m = AUG;

    else if (strcmp(s, "SEP") == 0) *m = SEP;

    else if (strcmp(s, "OCT") == 0) *m = OCT;
    
    else if (strcmp(s, "NOV") == 0) *m = NOV;

    else if (strcmp(s, "DEC") == 0) *m = DEC;

    else return 0;  // when condition above not met, return 0 (for false) 

    return 1;   // if 0 wasn't returned, return 1 to confirm true
}