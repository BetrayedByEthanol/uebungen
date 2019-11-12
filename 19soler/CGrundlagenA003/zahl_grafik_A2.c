#include<stdio.h>
#include <string.h>

char number[11];


void graphicOutput(char graphic);
//funktion zu drucken der ziffern in #
void graphicOutput(char graphic)
{
    char stuff = graphic;
    
    switch (stuff)
    {
    //beim falle von 0 druckt diese funktion eine null in #
    case '0': printf("\n ### \n#   #\n#   #\n#   #\n#   #\n#   #\n ###\n");
    //eine break um aus der klammer zu kommen weil der fall erfüllt wurde
    break;
    //beim falle von 1 druckt diese funktion eine eins in #
    case '1': printf("\n  #  \n ##  \n  #  \n  #  \n  #  \n  #  \n ### \n");
    break;
    //beim falle von 2 druckt diese funktion eine zwei in #
    case '2': printf("\n ### \n#   #\n#   #\n   # \n  #  \n #   \n#####\n");
    break;
    //beim falle von 3 druckt diese funktion eine drei in #
    case '3': printf("\n ### \n#   #\n    #\n ### \n    #\n#   #\n ### \n");
    break;
    //beim falle von 4 druckt diese funktion eine vier in #
    case '4': printf("\n   # \n  ## \n # # \n#  # \n#####\n   # \n   # \n");
    break;
    //beim falle von 5 druckt diese funktion eine fuenf in #
    case '5': printf("\n#####\n#    \n#    \n#### \n    #\n#   #\n ### \n");
    break;
    //beim falle von 6 druckt diese funktion eine sechs in #
    case '6': printf("\n ### \n#   #\n#    \n#### \n#   #\n#   #\n ### \n");
    break;
    //beim falle von 7 druckt diese funktion eine sieben in #
    case '7': printf("\n#####\n    #\n    #\n   # \n  #  \n #   \n#    \n");
    break;
    //beim falle von 8 druckt diese funktion eine acht in #
    case '8': printf("\n ### \n#   #\n#   #\n ### \n#   #\n#   #\n ### \n");
    break;
    //beim falle von 9 druckt diese funktion eine neun in #
    case '9': printf("\n ### \n#   #\n#   #\n ####\n    #\n#   #\n ### \n");
    break;
    //default wert gib an was passiert falls kein der oben genannten Faelle zutrifft
    default: printf("Bitte geben sie ein gueltige Zahl an!\n");
    }
}

int main()
{
    //while(1) damit das programm permanent an bleibt
    while(1)
    {
    //memset um den speicher des arrays zu loeschen damit ich wieder kleine zahlen aufrufen kann
    memset(number, 0, sizeof(number));
    //anfrage an user welche ziffern gedruckt werden sollen
    printf("Geben Sie eine Zahl (max 11 stellig) ein:\n");
    scanf("%s", &number);
    //setze die tmp variablen auf die array stellen nach den sie bennant wurden 
    
    //deklaration der count variable
    int count = 0;

    //while-schleife zum aufrufen der Funktion
    while (number[count] != '\0')
    {
        graphicOutput(number[count]);
        count++;
    } 
    }
//return wert 0
return 0;
}