
#include<stdio.h>

int main()
{
    int zahl1;
    int zahl2;
    int zahl3;
    int ergebnis;

    printf("Geben Sie drei Zahlen, getrennt durch ein Komma, ein: ");
    scanf("%d, %d, %d", &zahl1, &zahl2, &zahl3);
    ergebnis= zahl1+zahl2+zahl3;
    printf("Die Summe Ihrer Zahlen ist %d", ergebnis);
    return 0;
}