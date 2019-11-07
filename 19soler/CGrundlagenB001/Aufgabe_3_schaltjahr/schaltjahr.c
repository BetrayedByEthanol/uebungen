#include <stdio.h>
//deklarieren die benötigten Variablen
int input;

int main()
{
    //while-schleife damit das programm permanent an bleibt bis der benutzer strg+C drückt
    while (1)
    {
        //abfrage an den User nach seinem wunschjahr
        printf("Bitte geben sie Ihr Wunschjahr ein!\n");
        scanf("%4d", &input);
        //if um zu ermittel ob das wunschjahr wenn es durch 4 geteilt wird ein rest hinterlässt
        if (input % 4 == 0)
        {
            printf("%d ist ein Schaltjahr\n", input);
        }
        //bei einem rest ist es kein schaltjahr
        else
        {
            printf("%d ist kein Schaltjahr\n", input);
        }
    }
}