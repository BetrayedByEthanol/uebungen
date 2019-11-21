#include <stdio.h>
#include <string.h>

int main() {
    char eingabe[11];
    printf("Geben Sie einen Wochentag(Grossgeschrieben) an: \n");
    scanf("%s", eingabe);
    if (strncmp(eingabe, "Sonntag", 11) == 0) {
        printf("1");
    } else if (strncmp(eingabe, "Montag", 11) == 0) {
        printf("2");
    } else if (strncmp(eingabe, "Dienstag", 11) == 0) {
        printf("3");
    } else if (strncmp(eingabe, "Mittwoch", 11) == 0) {
        printf("4");
    } else if (strncmp(eingabe, "Donnerstag", 11) == 0) {
        printf("5");
    } else if (strncmp(eingabe, "Freitag", 11) == 0) {
        printf("6");
    } else if (strncmp(eingabe, "Samstag", 11) == 0) {
        printf("7");
    } else {
        printf("Fehler"); 
    }
    return 0;
}