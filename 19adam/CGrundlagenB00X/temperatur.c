#include<stdio.h>

int main(void)
{
    int celsius, fahrenheit, f2;
    char choice;

    printf("Bitte tippen Sie fuer eine Umwandlung von Celsius in Fahrenheit ein 'C' ein, fuer eine Umwandlung von Fahrenheit in Celsius ein 'F'.");
    choice = getchar();

    if(choice == 'C')
    {
        printf("\nBitte geben Sie die Temperatur, deren Umrechnung in Fahrenheit Sie wuenschen, in Celsius an.\n");
        scanf("%d", &celsius);

        f2 = celsius * 180;
        fahrenheit = f2 / 100 + 32;

        //printf("%d\n%d\n%d\n%d\n", celsius, c2, fahrenheit, f2); testing

        printf("%d Grad Celsius entsprechen %d Grad Fahrenheit.\n", celsius, fahrenheit);
    }

    if(choice == 'F')
    {
        printf("\nBitte geben Sie die Temperatur, deren Umrechnung in Celsius Sie wuenschen, in Fahrenheit an.\n");
        scanf("%d", &fahrenheit);

        f2 = (fahrenheit - 32) * 100;
        celsius = f2 / 180;

        printf("%d Grad Fahrenheit entsprechen %d Grad Celsius.\n", fahrenheit, celsius);
    }

    return 0;

}
