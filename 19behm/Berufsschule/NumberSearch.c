//Inputabfrage + Suchen und veränderter Ausgabe
#include <stdio.h>

int main()
{
    int array[50], n, search;
    for(n=0; n<=50; n++)
    array[n] = n;
    printf("Bitte geben Sie die gesuchte Zahl zwischen 1 und 50 ein.\n");
    scanf("%d", &search);
    for(n=0; n<=50; n++)
    {
        if(n == search){
        printf("%d gefunden\n", array[n]);
    }  
    else
    {
        printf("%d\n", array[n]);
    }
    }
    
return 0;
}