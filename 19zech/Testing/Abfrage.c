#include <stdio.h>
#include <string.h>

char stimmung[10];
char fortnite[10];


int main()
{
    printf("Hallo Pablo, wie geht's? \n");
    scanf("%s", &stimmung);

    if(strcmp(stimmung, "good") ==0)
    {
        printf("Why are you lying to me, fucker?");
    }
    else if (strcmp(stimmung, "bad") ==0)
    {
        printf("That's what I thought. \nDo you want to go home and play Fortnite instead?\n ");
        scanf("%s", &fortnite);
    }

    if(strcmp(fortnite, "yes") ==0)
    {
        printf("That's my man.");
    }
    return 0;
}