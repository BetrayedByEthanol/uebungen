#include<stdio.h>

int input;


int main()
{
    printf("Bitte geben Sie eine Zahl ein:\n");
    scanf("%d", &input);

    if (input % 2 == 0)
    {
        printf("%d ist eine gerade Zahl\n", input);
    }
    if (input % 2 == 1)
    {
        printf("%d ist eine ungerade Zahl\n", input);
    }
}