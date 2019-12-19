#include <stdio.h>
#include <stdlib.h>

void restock(double table[][5], char article[][16])
{
    int artnr, anzahl;
    do {        
        printf("Bitte die Artikelnummer angeben:\n");
        scanf("%d", &artnr);
        printf("Wie viele %s moechten Sie hinzufuegen?\n", article[artnr-1]);
        scanf(" %d", &anzahl);
        table[2][artnr-1]+=anzahl;
    }while(artnr != 0);
}
void sell(double **table,char **article)
{
    int artnr, anzahl;
    do {
        printf("Bitte die Artikelnummer angeben:\n");
        scanf("%d", &artnr);
        printf("Wie viele %s sollen verkauft werden?\n", article[artnr-1]);
        scanf("%d", &anzahl);
    } while(artnr != 0);
}
void output(char table_header[][16],double table[][5],char article[][16])
{
    for (int i = 0; i < 6; i++)
        printf("|%s\t\t", table_header[i]);
    printf("\n");
    for (int i = 0; i < 5; i++)
        printf("|\t%.0f\t\t|\t%s\t|\t%.0f\t\t|\t%.2f\t\t|\t%.0f\t\t|\t%.2f\t\t\n", table[0][i], article[i], table[1][i], table[2][i], table[3][i], table[4][i]);
}
void outputpadda(){}



int main()
{
    char table_header[6][16] = {"Artikelnr.","Artikel","Preis","Bestand","Verkauft","Umsatz"};
    double table[5][5] = {0};
    char article[6][16] = {"Radiergummi", "Schreibblock", "Aktenordner", "Taschenrechner", "Bleistift"};
    int input;

    printf("Willkommen im Kiosk.\nWas möchten Sie tun.\n");

    while(1)
    {
        printf("[1] Produkttabelle\n[2] Verkauf\n[3] Auffuellen\n[4] Gesamtumsatz\nBitte waehlen:\n");
        scanf("%d",&input);
        if(input == 1)
            output(table_header,table,article);
        else if(input == 2)
            sell();
        else if(input == 3)
            restock();
        else if(input == 4)
            outputpadda;
        else break;
    }
    return 0;
}