#include<stdio.h>

int device;
int sonnenvariable;
int helligkeit;
void sensor(int sonnenvariable);
int main(){
    device = 1;                          //Device = 1 entspricht Jalousie offen, Anlage startet mit Jalousie offen.
    printf("Wert fuer Sonnenintensitaet eingeben(1-100)");            // Helligkeit wird vom Nutzer festgelegt.

   do{     //schleife geht gibt zuerst Status der Jalousie aus, in beiden Fällen
        if (device == 1){ //offen                                           
            printf("Jalousie offen.\n");                       
            scanf("%d", &helligkeit);    //helligkeit wird abgefragt
            sensor(helligkeit);  // sensor Funktion mit input als Parameter
        }
        else if(device == 2){ //zu
            printf("Jalousie zu.\n");
            scanf("%d", &helligkeit);  //helligkeit wird abgefragt
            sensor(helligkeit);        //sensor Funktion mit input als Parameter           
        }
        
    }while(device == 1 || device == 2); //Wiederholbedingung
    
    printf("Ende"); // Ende.
}


void sensor(int sonnenvariable){  //Die Funktion überprüft ob der Wert als "hell" oder "dunkel" engestuft wird
    if(sonnenvariable <= 50){
        device = 1; // sagt der while Schleife die Jalouse soll aufgehen
    
    }
    else if(sonnenvariable > 50 && sonnenvariable <= 100){
        device = 2; //sagt der while Schleife die Jalousie soll zugehen
        
    }
    else if(sonnenvariable > 100){
        device = 3;    // ist eine Option für den User die Anwendung zu beenden, sonst unendliche Eingabeaufforderung
        
    }
}