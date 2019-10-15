
#include <stdio.h>

int parse(char c);

int main()
{
    char string[50]; //Eingabe String
    int run =1; // int Wert fuer den Fall, dass man eine Abbruchbedingung definieren moechte 
    int zeit=0; //der Wert des Stundenzeigers in Minuten
    int minuten=0; // der Wert des Minutenzeigers
    int stundenwinkel; //Winkel des Stundenzeigers
    int minutenwinkel; //Winkel des Minutenzeigers

    puts("Bitte Uhrzeit in hh:mm eingeben: ");
    gets(string);
    while(run==1)
    {
            // Check if die Eingabe korrekt ist
            if( parse(string[0])<2 && parse(string[1])<10 && string[2] == ':' && parse(string[3])<6 && parse(string[4])<10 && string[5] == '\0' &&string[2] == ':' ||
                parse(string[0])== '2' && parse(string[1])<5  && string[2] == ':'  && parse(string[3])<6 && parse(string[4])<10 && string[5] == '\0' )
            {
                //Wandle die Zeichen von der Eingaben, die die Minuten darstellen in einen Integer um
                minuten = (10* parse(string[3]));
                minuten = minuten + parse(string[4]);
                
                //Wandle die Zeichen von der Eingabe, die die Stunden darstellen in Minuten addiere die Minuten(damit der Stunden Zeiger zwischen Werten stehen kann)
                zeit= (parse(string[0]) * 10);
                zeit= zeit + parse(string[1]);
                zeit= zeit *60;
                zeit = zeit + minuten;
                
                // Wenn der Stundenzeiger 12 Uhr Mittags ueberschreitet zeihe 720 ab, da eine volle Rotation der Uhr statt gefunden hat
                if(zeit>=720) zeit = zeit - 720;
                
                //Errechne die Winkel der Zeiger zur Relation vom 12 Uhr Punkt
                stundenwinkel = zeit/2;
                minutenwinkel = minuten*6;

                //Errechne den Winken zwischen den Zeigern und gebe ihn aus
                if(stundenwinkel==minutenwinkel)puts("0 Grad");
                else
                {
                    if(stundenwinkel>minutenwinkel)
                    {
                        stundenwinkel = stundenwinkel - minutenwinkel;
                        // if(stundenwinkel>180) stundenwinkel = 360 - stundenwinkel; //Fuer den Spitzenwinkel
                        printf("%d Grad \n", stundenwinkel);
                    }
                    else
                    {
                        minutenwinkel = minutenwinkel - stundenwinkel;
                        //if(minutenwinkel>180) minutenwinkel = 360 - minutenwinkel; //Fuer den Spitzenwinkel
                        printf("%d Grad \n", minutenwinkel);
                    }
                }
            }
            //Ausgabe bei einer flaschen Eingabe
            else puts("Falsche Eingabe");
    // Naechste Uhrzeit
    gets(string);
    }
}

//Funktion zum Umwandeln von Ziffern Charactern zu Integer Zahlen, fall das nicht moeglich ist gibt 10 zurueck
int parse(char c)
{
    if(c=='0') return 0;
    if(c=='1') return 1;
    if(c=='2') return 2;
    if(c=='3') return 3;
    if(c=='4') return 4;
    if(c=='5') return 5;
    if(c=='6') return 6;
    if(c=='7') return 7;
    if(c=='8') return 8;
    if(c=='9') return 9; 
    else return 10;
}