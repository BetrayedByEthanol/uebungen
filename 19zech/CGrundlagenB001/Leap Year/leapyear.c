//Here is where we include the standard input/output library
#include <stdio.h>

//Here we define the variables needed for the program
int year;

//Here we start the program
int main()
{
    //This loop will make sure the program repeats until it is closed
    while (1)
    {
        //First we print a message asking the user to input a year and set it as the variable
        printf("Please input a year; \n");
        scanf("%d", &year);

        //If the year is divisible by 4, it leaves a remainder of 0 and the program branches off here
        if (year % 4 == 0)
        {
            //Then we print a message telling the user that the year is a leap year
            printf("%d is a leap year.", year);
        }
        //If the year is not divisible by 4, the program branches off here
        else if (year % 4 == 1)
        {
            //Then we print a message telling the user that the year is not a leap year
            printf("%d is not a leap year.", year);
        }
        //If the year is not divisible by 4, the program branches off here
        else if (year % 4 == 2)
        {
            //Then we print a message telling the user that the year is not a leap year
            printf("%d is not a leap year.", year);
        }
        //If the year is not divisible by 4, the program branches off here
        else if (year % 4 == 3)
        {
            //Then we print a message telling the user that the year is not a leap year
            printf("%d is not a leap year.", year);
        }
    }
    return 0;
}