#include<stdio.h> 

int main(void)
{
    int data, jahr;

    printf("Bitte geben Sie die zu testende Jahreszahl ein:\n");
    scanf("%d", &data);

    jahr = data;

    while(data > 0)
    {
        data = data - 4;
    }

    if(data == 0)
    {
        if(jahr > 2019)
        {
            printf("%d wird ein Schaltjahr.\n", jahr);
        }
        else if(jahr < 2019)
        {
            printf("%d war ein Schaltjahr.\n", jahr);
        }
    }
    else if(data < 0)
    {
        if(jahr > 2019)
        {
            printf("%d wird ein stinknormales Scheißjahr.\n", jahr);
        }
        else if(jahr < 2019)
        {
            printf("%d war ein stinknormales Scheißjahr.\n", jahr);
        }
        else if(jahr == 2019)
        {
            printf("%d ist ein stinknormales Scheißjahr, herzlichen Glueckwunsch.\n", jahr);
        }
    }

    return 0;
}
