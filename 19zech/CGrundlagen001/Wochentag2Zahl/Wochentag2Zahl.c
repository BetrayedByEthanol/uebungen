//Here we include the standard input/output library
#include <stdio.h>
//We include the string library to enable the string compare function
#include <string.h>

//Here we start the program
int main()
{
    //Here we define a local variable with useable characters
    char week[4];
    //Then we print a message asking the user to input a string according to certain requirements and set it as the week[4] variable
    printf("Enter Day of the Week (Mon-Sun): ");
    scanf("%3s", week);
    //Here we make an if command with the strcmp function that compares the user input variable and compares it with defined values
    if (strcmp(week, "Sun") == 0)
    {
        printf("1");
    }
    else if (strcmp(week, "Mon") == 0)
    {
        printf("2");
    }
    else if (strcmp(week, "Tue") == 0)
    {
        printf("3");
    }
    else if (strcmp(week, "Wed") == 0)
    {
        printf("4");
    }
    else if (strcmp(week, "Thu") == 0)
    {
        printf("5");
    }
    else if (strcmp(week, "Fri") == 0)
    {
        printf("6");
    }
    else if (strcmp(week, "Sat") == 0)
    {
        printf("7");
    }
    //Otherwise, if the user doesn't an input a valid string, the program ends after printing a message asking the user to input a string using certain requirements
    else
    {
        printf("Day invalid, please enter Sun/Mon/Tue/Wed/Thu/Fri/Sat.");
    }

    return 0;
}