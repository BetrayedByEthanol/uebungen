
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Alle Artikel, aktueller Bestand, Stkpreis,AnzahlVerkäufe,Umsätze(täglich)
//Struktogramm
//Funktionen Tabelle Initialisieren,Bestandauffüllen(parameter art-nr,stückzahl),verkaufen(art-nr,stkzahl),Tabelle ausgeben,Gesamtumsatz...
//sicherheitesabfrage nicht negativ...
//tabellen: table_header, table,article

char table_header[6][16] = {"Art-Nr.\0", "Artikel\0", "Bestand\0", "Preis    \0", "Verkauft\0", "Umsatz\0"};
double table[6][5] = {{1,2,3,4,5},{0,0,0,0,0},{0,0,0,0,0},{1.23,0.99,1.99,4.49,0.49},{0,0,0,0,0},{0,0,0,0,0}};
char article[6][16] = {"Radiergummi", "Schreibblock", "Aktenordner", "Taschenrechner", "Bleistift"};
int input;

/*void inittable()
{

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
            table[i][j] = 0;
    }

    for (int i = 1; i < 6; i++)
        table[0][i] = i;
}*/

void restock()
{
    int artnr, stkzahl;
    do{
    printf("Bitte Artikelnummer eingeben. 0 zum abbrechen\n");
    scanf("%d", &artnr);
    printf("Wie viele %s moechten Sie hinzufuegen?\n", article[artnr-1]);
    scanf(" %d", &stkzahl);
    table[2][artnr-1] += stkzahl;
    } while(artnr != 0);
}

void sell()
{
    
    int artnr, stkzahl;
    double preis;
    do{
    printf("Bitte Artikelnummer eingeben. 0 zum Abbrechen\n");
    scanf(" %d", &artnr);
    printf("Wieviele %s sollen verkauft werden?\n", article[artnr-1]);
    scanf(" %d", &stkzahl);
    if(stkzahl >= table[2][artnr-1])
        printf("Nicht genug %s vorhanden.");
    preis = table[3][artnr-1] * stkzahl;
    printf("Der Preis betraegt: %.2f Euro.\n", preis);
    table[2][artnr-1] = table[2][artnr-1] - stkzahl;
    table[4][artnr-1] += stkzahl;
    table[5][artnr-1] = table[3][artnr-1] * stkzahl;
    } while(artnr != 0);
}

void output()
{
    for (int i = 0; i < 6; i++)
        printf("|%s\t\t", table_header[i]);
    printf("\n");
    for (int i = 0; i < 5; i++)
        printf("|\t%.0f\t\t|\t%s\t|\t%.0f\t\t|\t%.2f\t\t|\t%.0f\t\t|\t%.2f\t\t\n", table[0][i], article[i], table[2][i], table[3][i], table[4][i], table[5][i]);
}

void outputall()
{
    double gesamtumsatz = 0;
    for (int i = 0; i < 6; i++)
        gesamtumsatz = gesamtumsatz + table[5][i];
    printf("Der Gesamtumsatz betraegt %.2f Euro.\n");
}

int main()
{
    //inittable();

    while (1)
    {
        printf("Bitte Option waehlen. \n [1] Verkaufen \n [2] Bestand auffuellen \n [3] Tabelle ausgeben \n [4] Gesamtumsatz\n");
        scanf(" %d", &input);

        if (input == 1)
            sell();
        else if (input == 2)
            restock();
        else if (input == 3)
            output();
        else if (input == 4)
            outputall();
        else
            printf("Falsche Eingabe");
    }

}