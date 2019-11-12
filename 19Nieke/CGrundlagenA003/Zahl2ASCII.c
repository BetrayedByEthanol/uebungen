/*
Dennis Nieke
11.11.2019
CGrundlagenA003-C
Programm zur Umwandlung von Ziffern zur ASCII Darstellung nebeneinander
v3.1
*/
#include <stdio.h>
#include <string.h>




//Funktion, die das Ausgabe Array in eine ASCII Darstellung des Parameter umwandelt, bei Zahlen von 0-9
char * toASCII(char c,char asciiZiffer[])
{
    //Pointer, der auf das Ergebnis Zeigt  
    char * result;

    switch (c)
    {
    case '0':
        strcpy(asciiZiffer," ### \n#   #\n#   #\n#   #\n#   #\n#   #\n ### \n");
        break;
    case '1':
        strcpy(asciiZiffer,"  #  \n ##  \n  #  \n  #  \n  #  \n  #  \n ### \n");
        break;
    case '2': 
        strcpy(asciiZiffer," ### \n#   #\n#   #\n   # \n  #  \n #   \n#####\n");
        break;
    case '3':
        strcpy(asciiZiffer," ### \n#   #\n    #\n ### \n    #\n#   #\n ### \n");
        break;
    case '4':
        strcpy(asciiZiffer,"   # \n  ## \n # # \n#  # \n#####\n   # \n   # \n");
        break;
    case '5':
        strcpy(asciiZiffer, "#####\n#    \n#    \n#### \n    #\n#   #\n ### \n");
        break;
    case '6':
        strcpy(asciiZiffer," ### \n#   #\n#    \n#### \n#   #\n#   #\n ### \n");
        break;
    case '7':
        strcpy(asciiZiffer,"#####\n    #\n    #\n   # \n  #  \n #   \n#    \n");
        break;
    case '8':
        strcpy(asciiZiffer," ### \n#   #\n#   #\n ### \n#   #\n#   #\n ### \n");
        break;
    case '9':
        strcpy(asciiZiffer," ### \n#   #\n#   #\n ####\n    #\n#   #\n ### \n");
        break;
    default:
        strcpy(asciiZiffer,"Falsche Zahl");
        break;
    }
    //Setzt den Pointer auf das Ergebnis und gibt ihn zurueck 
    result = asciiZiffer;
    return result;
}


//Fuegt die aktuelle Ziffer dem Ausgabe Array hinzu
char * joinDigits(char currentOutput[], char joiningElement[])
{
    //Temporaerer Speicher des des Ausgabe Arrays
    char temp[1024];
    //Zahlvariablen fuer das Ausgabe, temporaere und aktuelleZahl Array
    int tempIndex = 0;
    int outputIndex = 0;
    int insertIndex = 0;
    //Pointer auf die neue Ausgabe
    char * outputPointer;

    //Pack die bischer gespeicherten Zahlen in einen Zwischenspeicher
    while (currentOutput[tempIndex] != '\0')
    {
        temp[tempIndex] = currentOutput[tempIndex];

        tempIndex++;
    }
    temp[tempIndex] = '\0';

    tempIndex = 0;
    
    //Solange sich Daten im Zwischenspeicher befinden, packe sie in die neue Ausgabe und fuege die neue Zahl hinten dran 
    while(temp[tempIndex] != '\0')
    {   
        //fuegt eine Zeile aus dem Zwischenspeicher der Ausgabe hinzu
        while (temp[tempIndex] != '\n')
        {
            currentOutput[outputIndex] = temp[tempIndex];
            tempIndex++;
            outputIndex++;
        }
        tempIndex++;
        //fuegt eine Zeile der neuen Zahl der Ausgabe hinu
        while(joiningElement[insertIndex] != '\n')
        {
            currentOutput[outputIndex] = joiningElement[insertIndex];
            outputIndex++;
            insertIndex++;
        }
        //geht zur naechsten Zeile
        insertIndex++;
        currentOutput[outputIndex] = ' ';
        outputIndex++;
        currentOutput[outputIndex] = '\n';
        outputIndex++;
    }
    //fuegt die letzte Zeile der neuen Zahl der Ausgabe hinzu
    while(joiningElement[insertIndex] != '\0')
    {
        currentOutput[outputIndex] = joiningElement[insertIndex];
        outputIndex++;
        insertIndex++;
    }
    currentOutput[outputIndex] = '\0';

    //setzt den Pointer auf die neue Augabe und gibt ihn zurueck
    outputPointer = currentOutput;
    return outputPointer;

}

//Main Funktion
int main()
{
    //Deklaration des Ausgabe Arrays
    char ausgabe[1024] = "\n\n\n\n\n\n\n";
    //Deklaration fuer eine Ziffer als Array
    char asciiZiffer[60];
    //Variable zum Speichern der Eingabe 
    char eingabe[50];

    //Variable zum Durchlaufen des Arrays
    int count = 0;

    char * outputPointer = ausgabe;

    char * readingPointer = asciiZiffer;

    //Ausgabe zur Aufforderung zur Eingabe
    puts("Bitte eine Zahl eingeben:");

    //Lies die Eingabe
    gets(eingabe); 

    //While Schleife zum Durchlaufen der Eingabe
    while(eingabe[count] !=  '\0')
    {
        //Ruft die Umwandlungsfunktion auf
        readingPointer = toASCII(eingabe[count],readingPointer);

        //Fuegt die umgewandelte Zahl dem Ausgabe Array hinzu
        outputPointer = joinDigits(outputPointer,asciiZiffer);

        //Gehe zur naechsten Ziffer
        count++; 
    }

    //Ausgabe des Ergebnisses
    puts(outputPointer);

    //Ende des Programm
    return 1;
}