//Here we add the code library for the standard input output commands.
#include <stdio.h>

//Here we define the variables needed for the equations as float values so we can work with decimals
float circlearea;
//Assigning the radius as a float value allows the user to use decimal numbers for the radius
float radius;
//Pi is a constant so we assign it a value, but because it is a decimal number, we assign it as a float value
float pi = 3.14159265359;
//Should the user input a radius using a decimal number, Radius² will end up with decimal places, so we assign it as a float value
float radiussquared;

//Here is the start of the program
int main()
{
    //First we print an input field for the user to input a radius size.
    printf("Input radius: \n");
    //Then we scan the input and assign it to the radius variable
    scanf("%f", &radius);
        //Here we do the maths of the program, first multiplying the radius by itself to get the square
        radiussquared= radius*radius;
        //Then we multiply Radius² by Pi to find the area
        circlearea= radiussquared * pi;
    //Then we print a message with the area rounded to two decimal places
    printf("The area of the circle is %.2lf", circlearea);
    //Here we return a value of 0
    return 0;
}