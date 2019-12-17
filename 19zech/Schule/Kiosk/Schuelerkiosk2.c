#include <stdio.h>
#include <string.h>

struct table_header
{
    char article[10],bestand[10],preis[10],verkauft[10],umsatz[10];
};

struct table_content
{
    int articleNumber,bestand,verkauft;
    double preis,umsatz;
};

struct article
{
    char articleName[50];
};

void initiateTable(struct table_header * tH, struct table_content * tC, struct article * art);
void bestandfuellen(int articleNumber, int amount,struct table_content * table, struct article * art);
void verkaufen(int articleNumber, int amount,struct table_content * table, struct article * art);
void printTable(struct table_header * tH, struct table_content * tC);
void printUmsatz(struct table_content * table);
void printArticle(struct article * art);
int checkBestand(int articleNumber, int amount,struct table_content * table);



int main()
{
    //1 bis das Programm beendet werden soll
    int run = 1;
    //Zum Speichern der Eingaben 
    int choice;
    int articleNumber;
    int amount;    
    

    struct table_header tH;
    struct table_content table[5]; 
    struct article articleList[5];
    
    initiateTable(&tH, table, articleList);  


    while (run)
    {
        puts("Was soll gemacht werden? \n1: Tabellen initilisieren \n2: Bestand auffuellen \n3: Artikel verkaufen \n4: Tabelle ausgeben \n5: Gesamtumsatz ausgeben\n6: Programm beenden");

        scanf("%1d", &choice);
        puts("");
        switch(choice)
        {
        case 1:
            initiateTable(&tH, table, articleList);
            break;
        case 2:
            puts("Die Artikelnummer des auffuellenden Artikel eingeben:");
            printArticle(articleList);
            scanf("%d",&articleNumber);
            puts("Wie viele Artikel werden aufgefuellt:");
            scanf("%d",&amount);
            bestandfuellen(articleNumber, amount, table, articleList);
            break;
        case 3:
            puts("Die Artikelnummer des zu verkaufenden Artikel eingeben:");
            printArticle(articleList);
            scanf("%d",&articleNumber);
            puts("Wie viele Artikel werden verkauft:");
            scanf("%d",&amount);
            if(checkBestand(articleNumber, amount,table))
            {
                verkaufen(articleNumber, amount, table, articleList);
            }
            else
            {
                puts("Nicht genug Artikel im Bestand \n");
            }
            break;
        case 4:
            printTable(&tH, table);
            break;
        case 5:
            printUmsatz(table);
            break;
        case 6:
            run = 0;
            break;
        default:
            puts("Falsche Eingabe\nBitte erneut versuchen...\n");
            break;
        }
    }

    return 1;
}

void initiateTable(struct table_header * header, struct table_content * table, struct article * art)
{
  
    strcpy(header->article,"Artikel");
    strcpy(header->bestand,"Bestand");
    strcpy(header->preis,"Preis");
    strcpy(header->umsatz, "Umsatz");
    strcpy(header->verkauft,"Verkauft");

    

    strcpy(art[0].articleName,"Radiergummi");
    strcpy(art[1].articleName,"Schreibblock");
    strcpy(art[2].articleName, "Aktenordner");
    strcpy(art[3].articleName,"Mini-Taschenrechner");
    strcpy(art[4].articleName,"Kugelschreiber");

    

    table[0].articleNumber = 0;
    table[0].bestand = 23;
    table[0].preis = 1.23;
    table[0].verkauft = 4.0;
    table[0].umsatz = 4.92;
    table[1].articleNumber = 1;
    table[1].bestand = 1;
    table[1].preis = 0.99;
    table[1].verkauft = 12;
    table[1].umsatz = 11.88;
    table[2].articleNumber = 2;
    table[2].bestand = 45;
    table[2].preis = 1.99;
    table[2].verkauft = 6;
    table[2].umsatz = 11.94;
    table[3].articleNumber = 3;
    table[3].bestand = 1;
    table[3].preis = 4.49;
    table[3].verkauft = 0;
    table[3].umsatz = 0;
    table[4].articleNumber = 4;
    table[4].bestand = 2.34;
    table[4].preis = 6;
    table[4].verkauft = 1;
    table[4].umsatz = 6;

}

void bestandfuellen(int articleNumber, int amount,struct table_content * table, struct article * art)
{
    table[articleNumber].bestand += amount;
    printf("Es wurden %d %s aufgefuellt \n",amount,art[articleNumber]);
}

void verkaufen(int articleNumber, int amount, struct table_content * table, struct article * art)
{
    table[articleNumber].bestand -= amount;
    table[articleNumber].verkauft += amount;
    table[articleNumber].umsatz += table[articleNumber].preis * amount;
    printf("Es wurden %d %s verkauft \n",amount,art[articleNumber].articleName);
}

void printTable(struct table_header * table_header, struct table_content * table)
{

    printf("%s\t%s\t%s\t%s\t%s\n",table_header->article ,table_header->bestand, table_header->preis, table_header->verkauft, table_header->umsatz);

    for(int i = 0; i < sizeof(table[0])/sizeof(table)+1 ;i++)
    {
        printf("%d\t%d\t%.2lf\t%d\t\t%.2lf\n",table[i].articleNumber ,table[i].bestand, table[i].preis, table[i].verkauft, table[i].umsatz);
    
    }
    
}

void printUmsatz(struct table_content * table)
{
    double umsatz = 0;
    for(int i = 0; i < sizeof(table[0])/sizeof(table)+1 ; i++)
    {
        umsatz += table[i].umsatz;
    }
    printf("Der Gesamtumsatz ist: %.2lf\n", umsatz);
}

void printArticle(struct article * art)
{
    for(int i = 0; i < sizeof(art[0])/sizeof(art)-1; i++)
    {
        printf("%d: %s \n",i,art[i].articleName);
    }
}

int checkBestand(int articleNumber, int amount, struct table_content * table)
{
    if(table[articleNumber].bestand>=amount)return 1; else return 0;
}
