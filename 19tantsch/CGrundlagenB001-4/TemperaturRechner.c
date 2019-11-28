#include <stdio.h>

int fahrenheit, celsius;
int main(){
    printf("Geben Sie eine Temperatur in Fahrenheit ein.\n"); //Interaktion (Abfrage) von einer Fahrenheit Gradzahl.
    scanf("%d", &fahrenheit);       //Eingabeabfrage    

    celsius = (fahrenheit - 32) * 5 / 9;         //Formel berechnet mit Eingabewert die Gradzahl in Celsius.

    printf("%d Grad Fahrenheit sind %d Grad Celsius", fahrenheit, celsius); //Übersichtliche Ausgabe von Beiden Grad Werten.

}