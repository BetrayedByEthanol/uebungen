#include<stdio.h>

int sonnenvariable;
int helligkeit;
int i;
int boottime;
void sensor(int sonnenvariable);
void tagNacht(int i);
int main(){ //mainfunktion
    printf("Geben Sie bitte nun die Stundenzahl an (0-23)");//Interaktion mit dem User
    scanf("%d", &boottime);         //Interaktion: Zu welcher Zeit wird die Anlage hochgefahren
    tagNacht(boottime);             //der Funktion wird die Eingabe als Parameter übergeben
}


void sensor(int sonnenvariable){  //Die Funktion überprüft ob der Wert als "hell" oder "dunkel" engestuft wird
    if(sonnenvariable <= 50){    // Wenn der Wert unter oder gleich 50 ist, wird er als dunkel eingestuft. Folglich ist die Jalousie zu
        printf("Nicht zu hell, Jalousie ist offen\n\n");
    
    }
    else if(sonnenvariable > 50 && sonnenvariable <= 100){ //Wenn der Wert höher als 50 ist, wird er als hell eingestuft. Folglich ist die Jalousie offen
        printf("Zu hell, Jalousie ist zu\n\n");
}
}

void tagNacht(int i){     //Funktion, die ab der Uhrzeit eine stündliche Statusmeldung der Jalousie gibt
int x;                      //interne Variable der Funktion
    x = i;                  //Zuweisung der internen Variable
        do{
        if(x >= 0 && x <= 8 || x >= 20 && x <= 24 ){        //wenn Wert der Abfrage unter Nacht eingestuft wird
            printf("Es ist Nacht um %d Uhr, Jalousie zu.\n", x);  //gibt Nacht aus
            x = x + 1;      //Ist nötig um stündliche Ausgabe zu realisieren        
        }
        else if(x >= 9 && x <= 19){
            printf("Es ist Tag um %d Uhr\nWert fuer Helligkeit eingeben(1-100)\n",x);   //Wenn der Wert der Abfrage als Tag eingestuft wird
            scanf("%d", &helligkeit);    //Helligkeit wird abgefragt
            sensor(helligkeit);  // sensor Funktion mit input als Parameter
            x = x + 1;    //Ist nötig um stündliche Ausgabe zu realisieren
        }
        }while(x <= 24);   //Wiederholt immer bis 24 Uhr, stündlich
        printf("Simulation Ende"); //Mitteilung, die Simulation hat geendet
    }


