#include <stdio.h>

//char ja[1] = "#";
//char nein[1] = " ";
char forderung[50]; // Es können maximal 50 Zahlen auf einmal eingeben und gespeichert werden.
//int forderung2;
//int ende;
int a;             // a überprüft in der nachfolgenden Funktion, welche Zahl gedruckt werden soll(1-9)
int print(char a); //funktion print() mit dem Output der Variable a.
int null();
int eins();
int zwei();
int drei();
int vier();
int fuenf();
int sechs();
int sieben();
int acht();
int neun();

int main()
{

    printf("Geben Sie vier Zahlen(1-9) ein.");
    scanf("%s", &forderung); //&1d scant immer nur eine Zahl. Speichert nacheinander 1-9 ins Array.

    int i;
    for (i = 0; i <= 49; i++)
    { // Schleife um jede einzelne Ziffer nacheinander auszudrücken, wert erhöht sich um 1 bis maximal 49.
        print(forderung[i]);
    }
}

int print(char a)
{ //print() Funktion , überprüft das übergebene zeichen aus der ASCII Tabelle und gibt dann die entpsrechende Grafik aus

    if (a == 48)
    {

        null();
    }

    else if (a == 49)
    { //alle Ziffern besitzen eine eigene Darstellung und werden durch die "zahl()" Funktion repräsentiert.
        eins();
    }

    else if (a == 50)
    {
        zwei();
    }

    else if (a == 51)
    {
        drei();
    }

    else if (a == 52)
    {

        vier();
    }

    else if (a == 53)
    {

        fuenf();
    }

    else if (a == 54)
    {
        sechs();
    }

    else if (a == 55)
    {
        sieben();
    }

    else if (a == 56)
    {
        acht();
    }

    else if (a == 57)
    {
        neun();
    }
}

int null()
{

   printf(" ### \n#   #\n#   #\n#   #\n#   #\n#   #\n ### \n");     //gibt 0 aus.
    return 0;
}

int eins()
{
   printf("  #  \n ##  \n  #  \n  #  \n  #  \n  #  \n ### \n");     //gibt 1 aus.

    return 0;
}

int zwei()
{
   printf(" ### \n#   #\n#   #\n   # \n  #  \n #   \n#####\n");     //gibt 2 aus.
    return 0;
}

int drei()
{
    printf(" ### \n#   #\n    #\n ### \n    #\n#   #\n ### \n");    //gibt 3 aus.

    return 0;
}

int vier()
{
    printf("   # \n  ## \n # # \n#  # \n#####\n   # \n   # \n");    //gibt 4 aus.

    return 0;
}

int fuenf()
{
   printf("#####\n#    \n#    \n#### \n    #\n#   #\n ### \n");     //gibt 5 aus.

    return 0;
}

int sechs()
{
    printf(" ### \n#   #\n#    \n#### \n#   #\n#   #\n ### \n");    //gibt 6 aus.

    return 0;
}

int sieben()
{
    printf("#####\n    #\n    #\n   # \n  #  \n #   \n#    \n");    //gibt 7 aus.
    return 0;
}

int acht()
{
    printf(" ### \n#   #\n#   #\n ### \n#   #\n#   #\n ### \n");    //gibt 8 aus.

    return 0;
}
int neun()
{
    printf(" ### \n#   #\n#   #\n ### \n    #\n#   #\n ### \n");    //gibt 9 aus.

    return 0;
}