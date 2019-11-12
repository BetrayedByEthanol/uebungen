#include<stdio.h>

int graphicnumber1;
int graphic;
void graphicOutput(int graphic);
//start des programmes 
int main ()
{
    //while(1) bewirkt dass das programm permanent laeuft
    while (1)
    {
        //der Benutzer wird nach einem input wert gefragt welcher ausgedruckt werden soll
        printf("please input a number:\n");
        scanf("%d", &graphicnumber1);
        //aufruf der Funktion zum drucken der Zahlen
        graphicOutput(graphicnumber1);
    }
    return 0;
}
//Funktion zum Druck der Zahlen
void graphicOutput(int graphic)
{
    int tmp = graphic;
    //switch (Kontrollstruktur) statt vielen ifs
    switch (tmp)
    {
        //im falle von 0 wird die null in # ausgedruckt
        case 0: printf("\n ### \n#   #\n#   #\n#   #\n#   #\n#   #\n ###\n");
        //der break befehl um aus der Klammer zu kommen da dieser Fall erfuellt wurde
        break;
        //im falle von 1 wird die eins in # ausgedruckt
        case 1: printf("\n  #  \n ##  \n  #  \n  #  \n  #  \n  #  \n ### \n");
        break;
        //im falle von 2 wird die zwei in # ausgedruckt
        case 2: printf("\n ### \n#   #\n#   #\n   # \n  #  \n #   \n#####\n");
        break;
        //im falle von 3 wird die drei in # ausgedruckt
        case 3: printf("\n ### \n#   #\n    #\n ### \n    #\n#   #\n ### \n");
        break;
        //im falle von 4 wird die vier in # ausgedruckt
        case 4: printf("\n   # \n  ## \n # # \n#  # \n#####\n   # \n   # \n");
        break;
        //im falle von 5 wird die fuenf in # ausgedruckt
        case 5: printf("\n#####\n#    \n#    \n#### \n    #\n#   #\n ### \n");
        break;
        //im falle von 6 wird die sechs in # ausgedruckt
        case 6: printf("\n ### \n#   #\n#    \n#### \n#   #\n#   #\n ### \n");
        break;
        //im falle von 7 wird die sieben in # ausgedruckt
        case 7: printf("\n#####\n    #\n    #\n   # \n  #  \n #   \n#    \n");
        break;
        //im falle von 8 wird die acht in # ausgedruckt
        case 8: printf("\n ### \n#   #\n#   #\n ### \n#   #\n#   #\n ### \n");
        break;
        //im falle von 9 wird die neun in # ausgedruckt
        case 9: printf("\n ### \n#   #\n#   #\n ####\n    #\n#   #\n ### \n");
        break;
        //der default wert (falls keiner der oberen Faelle zutrifft) druck du sollst es nochmal versuchen
        default:  printf("Please input a number between 0-9");
    }
}