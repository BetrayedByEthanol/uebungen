#include<stdio.h>

void checkprime();

int main()
{
    checkprime();
}
void checkprime()
{
    int input, i, prime = 0;
    printf("Geben Sie eine positive Ganzzahl ein:\n");
    scanf("%d", &input);
    for(i = 2; i <= input/2; i++)
    {
        if(input % 1 == 0)
        {
            prime = 1;
            break;
        }
    }
    if(input == 1)
    {
    printf("1 ist keine Primzahl aber netter Versuch!");
    }
    else
    {
        if (prime == 0)
        printf("%d ist eine Primzahl", input);
        else
        printf("%d ist keine Primzahl", input);
    }
}

/*void menu()
{
    printf("Moechten Sie:\n");
}*/