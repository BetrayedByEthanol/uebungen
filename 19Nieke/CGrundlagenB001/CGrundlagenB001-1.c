/*
Dennis Nieke
14.11.2019
CGrundlagenB001-1
*/

#include <stdio.h>


int main()
{
    char input[1024];
    char reading[1024];
    int number1;
    int number2;
    int number3;

    puts("Bitte drei Zahlen eingeben: ");
    scanf("%d,%d,%d",&number1,&number2,&number3);

    printf("Die Summe der Zahlen %d, %d, %d beträgt: %d", number1, number2, number3, (number1 + number2 + number3));
    return 1;
}