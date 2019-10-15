
#include <stdio.h>
#include <string.h>

int main()
{
    char antwort[20];

    printf("Welchen Wochentag soll ich Übersetzen?\n\n\n");              // Fordert den Nutzer zur Eingabe des Wochentages
    scanf("%19s", antwort);
    if (strcmp(antwort, "Sonntag") == 0)                                // Wenn Sonntag dann sag Sonntag
    {
        printf("1");
    }
    else if (strcmp(antwort, "Montag") == 0)
    {
        printf("2");
    }
    else if (strcmp(antwort, "Dienstag") == 0)
    {
        printf("3");
    }
    else if (strcmp(antwort, "Mittwoch") == 0)
    {
        printf("4");
    }
    else if (strcmp(antwort, "Donnerstag") == 0)
    {
        printf("5");
    }
    else if (strcmp(antwort, "Freitag") == 0)
    {
        printf("6");
    }
    else if (strcmp(antwort, "Samstag") == 0)
    {
        printf("7");
    }
    else
    {
        printf("Bitte Tag schreiben");
    }
    
    return 0;
};