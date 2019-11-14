//Umrechnung von Celsius nach Fahrenheit und umgekehrt

#include <stdio.h>

int main()
{
    float Celsius, Fahrenheit, Temperatur, Output;
    char Formel;
    int Loop = 1;

    while (Loop == 1)
    {
        printf("Bitte geben Sie die Temperatur ein.\n");
        scanf("%f", &Temperatur);
        getchar();
        printf("Moechten Sie die Temperatur in Celsius oder Fahrenheit umrechnen? c/f \n");
        scanf("%c", &Formel);
        if (Formel == 'c')
        {
            Fahrenheit = Temperatur;
            Celsius = (Fahrenheit - 32) * (5 / 9);
            Output = Celsius;
            Loop = 0;
        }
        else if (Formel == 'f')
        {
            Celsius = Temperatur;
            Fahrenheit = Celsius * 1.8 + 32;
            Output = Fahrenheit;
            Loop = 0;
        }
        else
        {
            printf("Das war keine gueltige Eingabe.\n");
            printf("Bitte versuchen Sie es noch einmal.\n");
        }
    }
    if (Output == Fahrenheit)
        printf("%.2f Grad Celsius entspricht %.2f Grad Fahrenheit.", Temperatur, Fahrenheit);
    else
        printf("%.2f Grad Fahrenheit entspricht %.2f Grad Celsius.", Temperatur, Celsius);

    return 0;
}