//Ermittlung ob Schaltjahr oder nicht
#include <stdio.h>

int main()
{
    int input;
    printf("Bitte geben Sie die gesuchte Jahreszahl ein.\n");
    scanf("%d", &input);
    if(input%4 == 0)
    {
        if(input%100 == 0)
        {
            if(input%400 == 0)
                printf("%d ist ein Schaltjahr.", input);
            else
                printf("%d ist kein Schaltjahr.", input);
        }
        else
            printf("%d ist ein Schaltjahr.", input);
    }
    else
        printf("%d ist kein Schaltjahr.", input);
return 0;    
}