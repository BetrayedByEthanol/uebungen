
#include <stdlib>
#include <stdio.h>
#include <string.h>

//Alle Artikel, aktueller Bestand, Stkpreis,AnzahlVerkäufe,Umsätze(täglich)
//Struktogramm
//Funktionen Tabelle Initialisieren,Bestandauffüllen(parameter art-nr,stückzahl),verkaufen(art-nr,stkzahl),Tabelle ausgeben,Gesamtumsatz...
//sicherheitesabfrage nicht negativ...
//tabellen: table_header, table,article

String table_header[5];
double table[5][5];
String article[5];
int input;

void inittable() 
{
    table_header = {"Artikel","Bestand","Preis","Verkauft","Umsatz"}
    for(int i = 0; i<5;i++)
        table[0][i] = i;
    table[] = 0;
    article = {"Radiergummi","Schreibblock","Aktenordner","Taschenrechner","Bleistift"};
}

void restock(int artnr, int stkzahl)
{
    table[0][artnr] += stkzahl;
}

void sell(int artnr,int stkzahl)
{
    
}

void output();

void outputall();

int main() 
{
    inittable();
    
    while(1)
    {
        printf("Bitte Option waehlen. \n [1] Verkaufen \n [2] Bestand auffuellen \n [3] Tabelle ausgeben \n [4] Gesamtumsatz");
        scanf(" %d",&input);
        
        if(input == 1)
            sell();
        else if(input == 2)
            restock();
        else if(input == 3)
            output();
        else if(input == 4)
            outputall();
        else printf("Falsche Eingabe");
    }

}