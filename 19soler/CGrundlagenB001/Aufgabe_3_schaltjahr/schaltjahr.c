#include <stdio.h>
int input;
int main()
{
    while (1)
    {
        printf("Bitte geben sie Ihr Wunschjahr ein!\n");
        scanf("%4d", &input);
        if (input % 4 == 0)
        {
            printf("%d ist ein Schaltjahr\n", input);
        }
        else
        {
            printf("%d ist kein Schaltjahr\n", input);
        }
    }
}