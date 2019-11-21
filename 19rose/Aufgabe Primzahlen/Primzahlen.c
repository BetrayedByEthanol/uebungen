#include <stdio.h>

int primtrue(int zahl, int zahl2);

int main() {
    printf("Dieses Programmm berechnet die ersten 100 Primzahlen!");
    int primzahler = 100, primgezaehltes = 0;
    int primmenge[100], n = 0;
    for(int i = 2; primgezaehltes < primzahler; i++) {
        if(primtrue(i, i -1) == 1) {
            primmenge[n] = i;
            primgezaehltes++;
            n++;
        }
    }
    for(int i = 0; i < 100; i++) {
        printf("Primzahl Nr. %d: %d", i + 1, primmenge[i]);
        if(((i + 1) % 5) == 0) {
            printf("\n");
        }
    }
}

int primtrue(int zahl, int zahl2) {
    if(zahl == 1) return 0;
    else if(zahl2 == 1) return 1;
    else if((zahl % zahl2) == 0) return 0;
    else return primtrue(zahl, zahl2 - 1);
}