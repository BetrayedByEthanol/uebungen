#include <stdio.h>

char weekdays[][32+1] = {"sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday"};

int main() {
    printf("Enter Weekday: ");

    char input[32+1];
    scanf("%32s" , input) ;

    printf("\n");
    printf("Entered: %s\n", input);

    int dayIndex = -1;
    for(int i = 0; i < sizeof(weekdays) / sizeof(char[32+1]); i++)
    {
        if(strcicmp(input, weekdays[i]) == 0) {
            dayIndex = i;
            break;
        }
    }

    if(dayIndex < 0) {
        printf("cannot find weekday: %s\n", input);
        return 1;
    } else {
        printf("Weekday: %d\n", dayIndex + 1);
    }
    return 0;
}

/**
 * Cas insensitive string compare
 */
int strcicmp(char const *a, char const *b)
{
    for (;; a++, b++) {
        int d = tolower((unsigned char)*a) - tolower((unsigned char)*b);
        if (d != 0 || !*a)
            return d;
    }
}