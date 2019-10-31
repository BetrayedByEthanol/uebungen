#include <stdio.h>

float celsius;
float fahrenheit;
int option;
float ctof;
float ftoc;

int main()
{
    printf("Do you want Celsius to Fahrenheit? [1] \nDo you want Fahrenheit to Celsius? [2]\n");
    scanf("%d", &option);
    
    if (option == 1)
    {
        printf("Please input a temperature in Celsius: \n");
        scanf("%f", &celsius);
        ctof = (celsius * 9/5) + 32;
        printf("The temperature in Celsius (%.2f°C) in Fahrenheit is: %.2f°F", celsius, ctof);
    }
    if (option ==2)
    {
        printf("Please input a temperature in Fahrenheit: \n");
        scanf("%f", &fahrenheit);
        ftoc = (fahrenheit - 32) * (5/9);
        printf("The temperature in Fahrenheit (%.2f°F) in Celsius is: %.2f°C", fahrenheit, ftoc);
    }

}