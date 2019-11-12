#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int charToInt (char d);

int main () {
    int zahl = 0;
    int summe = 0;
    int i = 0;
    int check = 0;
    char eingabe[2000] = "", ausgabe[2000] = "";
    printf("Geben Sie Ihre  Zahlen(mit Komma getrennt) an:\n");
    scanf("%s", &eingabe);
    for(i = 0; eingabe[i] != 0; i++) {
        if((eingabe[i] != 0) && (eingabe[i] != 44)) {
            zahl = zahl * 10 + charToInt(eingabe[i]);
        } else {
            summe += zahl;
            if (summe == zahl) {
                sprintf(ausgabe, "%d", zahl);
            } else {
                sprintf(ausgabe, "%s%d", ausgabe, zahl);
            }
            zahl = 0;
            sprintf(ausgabe, "%s + ", ausgabe);
        }
    }
    summe += zahl;
    sprintf(ausgabe, "%s%d", ausgabe, zahl);
    sprintf(ausgabe, "%s = %d", ausgabe, summe);
    printf("%s", ausgabe);   
    return 0;
}

charToInt(char d) {
    if (d == 48) return 0;
    if (d == 49) return 1;
    if (d == 50) return 2;
    if (d == 51) return 3;
    if (d == 52) return 4;
    if (d == 53) return 5;
    if (d == 54) return 6;
    if (d == 55) return 7;
    if (d == 56) return 8;
    if (d == 57) return 9;
    else return 10;
}