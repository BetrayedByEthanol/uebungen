//Here is where we include the standard input/output library
#include <stdio.h>

//Here we define the variables needed for the program
int var1;

//Here we start the program
int main()
{
    //This loops forever until the program is closed
    while (1)
    {
        //Then we print a message in ask the user to input a number and set that as var1
        printf("\nPlease input a number: \n");
        scanf("%d", &var1);

        //If the variable leaves a remainder, then the program branches off here
        if (var1 % 2 == 1)
        {
            //Then we print a message telling the user that the number is odd
            printf("%d is odd.\n", var1);
        }
        //Otherwise, if the variable leaves a remainder of 0, the program branches off here
        else if (var1 % 2 == 0)
        {
            //Then we print a message telling the user that the number is even
            printf("%d is even.\n", var1);
        }
    }
    return 0;
}