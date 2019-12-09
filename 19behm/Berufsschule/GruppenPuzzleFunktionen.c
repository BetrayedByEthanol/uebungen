/*  1.) Die Deklaration (int bla();) setzt lediglich eine Speicheradresse für eine Funktion frei bei der Definition wird der Inhalt der Funktion beschrieben
        ähnlich dem Wert einer Variable.
    2.) int secondssince();
        int um den Rückgabewert Funktion auf einen Typen festzulegen. secondssince als Namen für die Funktion. 
        Die Klammern geben an, dass es sich um eine Funktion handelt und keine Variable ist. Das Semikolon um den Befehl abzuschließen. */
//  3.)
/*        #include <stdio.h>
        #include <time.h>

        time_t seconds;

        int secondssince()
        {    
        seconds = time(NULL); 
        return seconds; 
        } 

        int main()
        {
            secondssince();
            printf("Sekunden seit dem 1 Januar 1970 = %ld\n", seconds);
            return 0;
        }*/

/*  4.) Eine globale Variable kann von jeder dem Programm zugehörigen Funktion genutzt und verändert werden.
        Eine lokale Variable kann nur innerhalb der betreffenden Funktion genutzt werden. Andere Funktionen können darauf nicht zugreifen.
    5.) Die neu erzeugte Variable überschreibt die Globale Variable innerhalb der Funktion
    6.)
*/
/*
#include <stdio.h>
#include <stdlib.h>

int setze(int a)
{
    printf("%d\n", a);
}

int main()
{
    int x = 0;
    setze(0);
    setze(x);
}

*/
// Der Unterschied beschreibt, dass ich zum einen eine Funktion mit einem Festen Wert aufrufen kann
// aber auch über eine Variable, welche zuvor irgendwo berechnet wurde.
//  7.)
/*

#include <stdio.h>
#include <stdlib.h>

int main( int argv, char *argch[] )

{
    int a,b,c;
    a = atoi(argch[1]);
    b = atoi(argch[2]);
    c=a+b;
    
    printf("%d", c);
}
*/

//  8.) Funktionen sorgen unter anderem dafür, dass die Main()-Funktion "sauber" bleibt 
//  und man kann eine Funktion unter verschiedensten Umständen mit verschiedenen Variablen fürttern. Ohne die Funktion
// jedes mal neu ausschreiben zu müssen.

        

        