
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Alle Artikel, aktueller Bestand, Stkpreis,AnzahlVerkäufe,Umsätze(täglich)
//Struktogramm
//Funktionen Tabelle Initialisieren,Bestandauffüllen(parameter art-nr,stückzahl),verkaufen(art-nr,stkzahl),Tabelle ausgeben,Gesamtumsatz...
//sicherheitesabfrage nicht negativ...
//tabellen: table_header, table,article

char table_header[6][16] = {"Art-Nr.","Artikel", "Bestand", "Preis", "Verkauft", "Umsatz"};
double table[6][5];
char article[6][16] = {"Radiergummi", "Schreibblock", "Aktenordner", "Taschenrechner", "Bleistift"};
int input;

void inittable()
{
    
    for (int i = 0; i < 5; i++){
        for(int j =0;j<5;j++)
            table[j][i] = 0;
    }
            
    for(int i=0; i<5;i++)
        table[0][i] = i;
    
}

void restock()
{
    int artnr, stkzahl;
    printf("Bitte Artikelnummer eingeben\n");
    scanf("%d", &artnr);
    printf("Wie viele %s moechten Sie hinzufügen?\n",table[1][artnr]);
    scanf(" %d", &stkzahl);
    table[1][artnr] += stkzahl;
}

void sell()
{
    int artnr, stkzahl;
    double preis;
    printf("Bitte Artikelnummer eingeben\n");
    scanf(" %d",&artnr);
    printf("Wieviele sollen verkauft werden?\n");
    scanf(" %d",&stkzahl);
    preis = table[3][artnr] * stkzahl;
    printf("Der Preis betraegt: %.2f", preis);
    table[2][artnr] -= stkzahl;
    table[4][artnr] += stkzahl;
    table[5][artnr] = table[3][artnr] * stkzahl;
}

void output();

void outputall();

int main()
{
    inittable();
    

    while (1)
    {
        printf("Bitte Option waehlen. \n [1] Verkaufen \n [2] Bestand auffuellen \n [3] Tabelle ausgeben \n [4] Gesamtumsatz");
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