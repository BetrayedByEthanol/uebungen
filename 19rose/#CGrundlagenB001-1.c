#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main () {
    
    int zahl1 = 0;
    int zahl2 = 0;
    int zahl3 = 0;
    int summe = 0;
    int i = 0, i2 = 0, i3 = 0;
    int t = 0;
    int check = 0;
    char eingabe[55] = "" ;

    printf("Geben Sie Ihre 3 Zahlen(mit Komma getrennt) an:\n");
    scanf("%s", &eingabe);
    for(i = t; check < 1; i++) {
        zahl1 = zahl1 + (((int)eingabe[i] - 48) * pow(10,i));
        if (eingabe[i + 1] == 44) {
            check = 1;
            t = i + 2;
        }    
    }
    check = 0;
    for(i2 = t; check < 1; i2++) {
        zahl2 = zahl2 + (((int)eingabe[i2] - 48) * pow(10,i2 - 1 -i));
        if (eingabe[i2 + 1] == 44) {
            check = 1;
            t = i2 + 2;
        }    
    }
    check = 0;
    for(i3 = t; check < 1; i3++) {
        zahl3 = zahl3 + (((int)eingabe[i3] - 48) * pow(10,i3 - 1 - i2));
        if (eingabe[i3 + 1] == 0) {
            check = 1;
        }    
    }
    summe = zahl1 + zahl2 + zahl3;
    printf("%d + %d + %d = %d", zahl1, zahl2, zahl3, summe);
    return 0;
}