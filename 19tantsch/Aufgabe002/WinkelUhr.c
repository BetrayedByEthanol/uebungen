#include<stdio.h>

int stunden;
int minuten;
int berechnung(int a, int b);
int ergebnis;
int main(){

    scanf("%d:%d", &stunden, &minuten);                        //Abfrage Uhrzeit 
    
    if(stunden > 24 && minuten > 60){                           // Wenn Uhrzeit nicht Korrekt
        printf("Keine gültige Uhrzeit");
        return -1;
    }
    else if (stunden <= 24 && minuten <= 60){                       //Wenn Uhrzeit korrekt(exisiert)
        
        
        ergebnis = berechnung(stunden, minuten);                        //Ergebnis wird in einer Funktion berechnet und hier in eine variable geschrieben.

        printf("%d", ergebnis);                                         //Ergebnis wird ausgegeben

        return 0;
    }
}

int berechnung(int a, int b){                                           //Funktion für den Mathematischen Teil
int loesung;

    
    loesung = a * 30 - b * 6 - b / 2 - 360;                                 //Lösungsweg.


    
    return loesung;                                                              // Die funktion gibt einen int wert aus, den der var. "loesung"
  
}