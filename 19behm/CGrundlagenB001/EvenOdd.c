//Programm zum Ermitteln ob Zahl Gerade/Ungerade
#include <stdio.h>

int main ()
{
    int Zahl;
    printf("Bitte geben Sie die zu ermittelnde Zahl ein.\n");
    scanf("%d", &Zahl);
    if(Zahl % 2 == 0)
        printf("Die Zahl %d ist gerade.", Zahl);
    else
    printf("Die Zahl %d ist ungerade", Zahl);
    return 0;
}