#include<stdio.h> 

int main(void)
{
    int zahl, check;

    printf("Bitte geben Sie die zu testende Zahl ein:\n");
    scanf("%d", &zahl);

    check = zahl;

    while(check > 0)
    {
        check = check - 2;
        printf("%d\n", check);
    } 

    if(check == 0)
    {
        printf("%d ist eine Zahl, die für sich einsteht, gerade und ehrenhaft.\n", zahl);
    }
    else if(check < 0)
    {
        printf("%d ist eine feige, heimtückische Zahl mit unterschiedlichsten Gesichtern, sie ist ungerade. :(\n", zahl);
    }

    return 0;
}
