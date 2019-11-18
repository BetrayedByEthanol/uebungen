//Programm zur Addition von 3 Zahlen
#include <stdio.h>

int main()
{
    int a, b, c, o;
    printf("Bitte geben Sie die drei Zahlen ein getrennt durch ein Komma\n");
    scanf("%d,%d,%d", &a, &b, &c);
    int o = a+b+c;
    printf("Die Summe der Zahlen beträgt: %d\n", o);
    return 0;
}