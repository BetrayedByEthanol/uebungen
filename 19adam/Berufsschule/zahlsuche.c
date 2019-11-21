#include<stdio.h>

int main(void)
{
    int suche, check;
    check = 0;

    printf("Bitte geben Sie eine Zahl zwischen 0 und 50 ein, nach der gesucht werden soll.\n");
    scanf("%d", &suche);

    while(suche > check)
    {
        printf("%d\n", check);
        check = check + 1;
    }

    printf("Gefunden! Gesuchte Zahl: %d", suche);

    return 0;

} 
