#include <stdio.h>
//deklarieren der benötigten Variablen
int option;
float celsius;
float fahrenheit;
float celend;
float fahrend;

int main()
{
    //abfrage an den User welchen einheit er berechnen will
    printf("waehlen sie bitte eine option: celsius in fahrenheit [1] oder fahrenheit in celsius [2]\n");
    scanf("%d", &option);
    //falls option 1 gewählt wurde rechne celsius in fahrenheit
    if (option == 1)
    {
        printf("Wie viel grad celsius?\n");
        scanf("%f", &celsius);
        //rechnung: celsius in fahrenheit
        fahrend = (celsius * 9 / 5) + 32;
        printf("%.2f grad celsius sind %.2f grad fahrenheit", celsius, fahrend);
    }
    //falls option 2 gewählt wurde rechne fahrenheit in celsius
    if (option == 2)
    {
        printf("Wie viel grad fahrenheit?\n");
        scanf("%f", &fahrenheit);
        //rechnung fahrenheit  in celsius
        celend = (fahrenheit - 32) * 0.555556;
        printf("%.2f grad Fahrenheit sind %.2f grad Celcius", fahrenheit, celend);
    }
    return 0;

}
