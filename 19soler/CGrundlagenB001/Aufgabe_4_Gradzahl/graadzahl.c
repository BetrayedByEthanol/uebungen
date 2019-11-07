#include <stdio.h>

int option = 0;
float celsius = 0;
float fahrenheit = 0;
float celend = 0;
float fahrend = 0;

int main()
{

    printf("waehlen sie bitte eine option: celsius in fahrenheit [1] oder fahrenheit in celsius [2]\n");
    scanf("%d", &option);
    fflush(stdin);
    if (option == 1)
    {
        printf("Wie viel grad celsius?\n");
        fflush(stdin);
        scanf("%f", &celsius);

        fahrend = (celsius * 9 / 5) + 32;
        printf("%.2f grad celsius sind %.2f grad fahrenheit", celsius, fahrend);
    }
    if (option == 2)
    {
        printf("Wie viel grad fahrenheit?\n");
        fflush(stdin);
        scanf("%f", &fahrenheit);

        celend = (fahrenheit - 32) * (5 / 9);
        printf("%.2f grad fahrenheit sind %.2f grad celcius\n", fahrenheit, celend);
    }

    return 0;
}
