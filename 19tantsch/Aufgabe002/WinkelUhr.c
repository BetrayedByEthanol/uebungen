#include<stdio.h>

int stunden;
int minuten;
int berechnung(int a, int b);
void vergleiche(int c, int d);
int indikator;
int ergebnis;
int main(){

    printf("Dieses Programm ermittelt den Winkel zwischen Minuten- und Stundenzeiger.\nGeben Sie eine Uhrzeit an.\n(zb: 13:30):");

    scanf("%d:%d", &stunden, &minuten);                        //Abfrage Uhrzeit 
    
    if(stunden > 24 && minuten > 60 || stunden == 24 && minuten > 0){                           // Wenn Uhrzeit nicht Korrekt
        printf("Keine gueltige Uhrzeit");
        return -1;
    }
    else if (stunden <= 12 && minuten <= 60 && minuten > 0){                       //Wenn Uhrzeit korrekt(exisiert)   
        ergebnis = berechnung(stunden, minuten);                        //Ergebnis wird in einer Funktion berechnet und hier in eine variable geschrieben.
        printf("%d Grad", ergebnis);                                         //Ergebnis wird ausgegeben
        return 0;
    }
    else if(stunden > 12 && minuten != 00){
        stunden = stunden - 12;
        ergebnis = berechnung(stunden, minuten);
        printf("%d Grad", ergebnis);
        return 0;
    }
    else if(stunden == 24 && minuten == 0 || stunden == 12 && minuten == 0){         //gibt 0 Grad als Lösung aus. Falls es 24:00 Uhr oder 12:00 uhr ist.
        printf("0 Grad");
    }

}

int berechnung(int a, int b){                                           //Funktion für den Mathematischen Teil
int loesung;
vergleiche(stunden, minuten); //siehe unten, Funktion vergleicht Winkelgrößen

    if(indikator == 1){
        loesung = (a * 30 - b * 6 );          //wenn der Winkel des Stundenzeiger größer als der vom Minutenzeiger, wird der kleinere vom größeren Winkel abgezogen.
        if(loesung < 0){
            loesung * -1;
            return loesung;
        }
            else{
                return loesung;
            }
    }   
    if(indikator == 2){                         //wenn der Winkel des Minutenzeiger größer als der vom Stundenzeiger, wird der kleinere vom größeren Winkel abgezogen.
        loesung = (b * 6 - a * 30); 
        if(loesung < 0){
            loesung * -1;
            return loesung;
        }
            else{
                return loesung;
            }      
    }                                                                                   //Lösungsweg.
                                                              // Die funktion gibt einen int wert aus, den der var. "loesung"  
}

void vergleiche(int c, int d){       //überprüft welcher Winkel der größere ist und gibt einen Wert für die Berechnung aus.
    int winkelstunde;
    int winkelminute;

    winkelstunde = c * 30;
    winkelminute = d * 6;
   
    if(winkelstunde > winkelminute){
        indikator = 1;
        
    }     
    else if(winkelstunde < winkelminute){
    indikator = 2;
   
        
        
    }


}