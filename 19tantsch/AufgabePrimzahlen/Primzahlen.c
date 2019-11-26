#include<stdio.h>



int rahmen = 0;
int zahl = 0;
int variable;
int check;

int main(){
    printf("Maximale Groesse der Primzahlen Eingeben: ");       //User wird auf Eingabe vorbereitet.  
    scanf("%d", &rahmen);       //User gibt an den Höchsten wert der Primzahl an.(Maximalwert)

    for(zahl = 2; zahl < rahmen; zahl++){       //For-Schleife fängt bei 2 an, erste primzahl, zählt hoch bis zum Maximalwert (Usereingabe).
     check = 0;                                 //Diese Variable ist entscheidend für die Ausgabe einer Primzahl, wird hier "resetet", zurück auf Null.
        for(variable = 2; variable < rahmen; variable++){      //Zweite For-Schleife, fängt bei zwei an und Zählt hoch bis zum Maximalwert (Usereingabe).
            if(zahl % variable != 0){     //Teilt erste Zählvaribale solange durch die zweite Zählvariable bis entweder 0 oder ein Rest kommt.Bei Rest ist die Bedingung erfüllt.   
               check = 1;       //Setzt check auf eins, zahl wird weiter unten ausgegeben.
            }
            
            else if(zahl != variable){  //Bedinung für nicht-primzahlen.
                check = 0;      //setzt check auf 0                 
                break;          //beendet die zweite for-Schleife
            }
        }
        if(check == 1){         //wenn check auf 1 ist die Bedinung erfüllt 
            printf("%d ", zahl);     //zahl wird ausgegeben
        }
    }
    return 0;
}