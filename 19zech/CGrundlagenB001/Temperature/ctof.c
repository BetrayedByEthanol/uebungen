//Here is where we include the standard input/output library
#include <stdio.h>

//Here we define the variables needed for the program
float celsius;
float fahrenheit;
int option;
float ctof;
float ftoc;

//This is where we start the program
int main()
{
    while (1)
    {
        //First we print a message and ask the user which function they wish to us, and set that input as the option variable
        printf("\nDo you want Celsius to Fahrenheit? [1] \nDo you want Fahrenheit to Celsius? [2]\nDo you want to exit? [3]\n");
        scanf("%d", &option);

        //If the user inputs a 1, to calculate celsius to fahrenheit, the program branches off here
        if (option == 1)
        {
            //Here we print a message and ask the user and set that input as the celsius variable
            printf("Please input a temperature in Celsius: \n");
            scanf("%f", &celsius);
            //Then we perform an operation to convert celsius temperatures to fahrenheit temperatures and set it as the ctof variable
            //Due to this being a decimal number, we need to use a float variable type
            ctof = (celsius * 9 / 5) + 32;
            //Then we print the celsius temperature from the user input, and the fahrenheit temperature we calculated using the operation above
            printf("The temperature in Celsius (%.2f°C) in Fahrenheit is: %.2f°F\n", celsius, ctof);
        }
        //If the user inputs a 2, to calculate Fahrenheit to Celsius, the program branches off here
        if (option == 2)
        {
            //Here we print a message and ask the user and set that input as the fahrenheit variable
            printf("Please input a temperature in Fahrenheit: \n");
            scanf("%f", &fahrenheit);
            //Then we perform an operation to convert fahrenheit temperatures to celsius temperatures and set it as the ftoc variable
            //Due to this being a decimal number, we need to use a float variable type
            ftoc = (fahrenheit - 32) * (5 / 9);
            //Then we print the fahrenheit temperature from the user input, and the celsius temperature we calculated using the operation above
            printf("The temperature in Fahrenheit (%.2f°F) in Celsius is: %.2f°C\n", fahrenheit, ftoc);
        }
        //If the user inputs a 3, the program will branch off here
        if (option == 3)
        //The break command ends the loop and therefor the program
        break;
    }
}