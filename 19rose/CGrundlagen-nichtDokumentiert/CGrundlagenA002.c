#include <stdio.h>

int main () {
    int Stunde, Minute, Winkel, lock = 1;
    do {
        printf("Geben Sie die gewuenschte Zeitstunde an: ");
        scanf("%d", &Stunde);
        printf("Geben Sie nun die gewuenschte Minute an: ");
        scanf("%d", &Minute);
        if ((Stunde > 24) | (Minute > 60)) {
            printf("Bitte gueltige Uhrzeit angeben!");
        } else {
            lock = 0;
        }
    } while (lock != 0);
    Winkel = (30 * Stunde) - (6 * Minute) + (Minute / 2) % 360;
    printf("%d Grad", Winkel);
}