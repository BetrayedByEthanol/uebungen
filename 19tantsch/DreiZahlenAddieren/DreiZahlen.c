#include<stdio.h>

int eins;
int zwei;
int drei;
int ergebnis;

int main(){

    printf("Dieses Programm rechnet drei Zahlen zusammen.\nGeben Sie drei Zahlen ein Bitte (BSP: 1,2,3)\n");  // Begrüßung

    scanf("%d,%d,%d", &eins, &zwei, &drei);    //Mit komma getrennte %d weisen die richtige Syntax zu. Wie im Beispiel.
    
    ergebnis = eins + zwei + drei;                  //Einfache Errechnung nach Vorgabe.
    
    printf("Das Ergebnis ist: %d", ergebnis);        //Ausgabe.
    return 0;
}