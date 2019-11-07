#include <stdio.h>

int main(void)
{
    float pi = 3.14; //Pi is a constant value needed for the equation, it is also a decimal number
    int radius;
    int radiussquared;
    float area;

    printf("Please input the radius of the circle: \n"); //This is an input field where the user can define the radius of the circle
    scanf("%d", &radius); //This function reads the input from the user and sets it as the Radius


    radiussquared= radius * radius; //The radius is squared here for the equation and set as a new variable
    area = pi * radiussquared; //This is the basic equation for the area of a circle, Pi times the Radius²

    printf("%f", area); //The answer is printed here, using %f for a float value

    return 0;
}