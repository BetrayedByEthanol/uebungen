/** author: Marcel Zöllner 
 * C program to print a number for a day in the week
*/

#include <stdio.h>
#include <string.h>

int main()
{

    /*Definierung der Constanten*/
    const char WEEKDAYS[][16] = {"Sonntag", "Montag", "Dienstag", "Mittwoch", "Donnerstag", "Freitag", "Samstag"};

    char input[10];
    int resultindex = -1;

    do
    {
        /* Eingabe des Wochentags, des Users */
        printf("Please enter a day from the week:\n");
        scanf("%9s", &input);

        for (int i = 0; i < 7; i++)
        {
            if (strcmp(WEEKDAYS[i], input) == 0)
            {
                printf("The number of %s is %d\n", WEEKDAYS[i], i + 1);
                resultindex = i;
                break;
            }
        }
        if (resultindex < 0)
        {
            printf("invalid input, please try again!\n");
        }
    } while (resultindex < 0);
    printf("Thanks, good bye!\n");

    return 0;
}