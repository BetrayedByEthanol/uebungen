/*simple c programm to print numbers for every week day*/
#include <stdio.h>
#include <string.h>

int main()
{

    /*define the constan*/
    const char WEEKDAYS[][16] = {"Sonntag", "Montag", "Dienstag", "Mittwoch", "Donnerstag", "Freitag", "Samstag"};

    char input[10];
    int resultindex = -1;

    do
    {
        /* input the of weekdays from users */
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
            printf("Invalid input, please try again!\n");
        }
    } while (resultindex < 0);

    return 0;
}