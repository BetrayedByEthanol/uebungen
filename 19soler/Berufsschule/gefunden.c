#include <stdio.h>

int var1;
//dekleration eines Arrays zum zeigen aller 50 Zahlen
int set[51];
//start des Programmes (Hauptfunktion)
int main()
{
    //Ausgabe und Abfrage des Users nach beliebiger Zahl (0 bis 50)
    printf("Bitte geben sie eine Zahl von 0 bis 50 an: \n");
    scanf("%d", &var1);
    //Schleife fuer die Zuweisung von i
    for(int i =0; i<51; i++)
    {
        set[i]=i;
    }
    //eine Schleife fuer das finden der gesuchten Zahl
    for(int i =0; i<51; i++)
    {
        //falls die zahl gleich ist wie eine Zahl im Array, schreibe gefungen hinter diese Zahl
        if(set[i]==var1)
        {
            printf("%d gefunden \n", set[i]);
        }
        //sonst schreib den Array weiter
        else
        {
            printf("%d \n", set[i]);
        }

    }
    return 0;
}