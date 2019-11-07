#include <stdio.h>

int var1;
int set[51];

int main()
{
    printf("Please input a number between 0 and 50: \n");
    scanf("%d", &var1);

    for(int i =0; i<51; i++)
    {
        set[i]=i;
    }

    for(int i =0; i<51; i++)
    {
        if(set[i]==var1)
        {
            printf("%d gefunden \n", set[i]);
        }
        else
        {
            printf("%d \n", set[i]);
        }

    }
    return 0;
}