#include <stdio.h>

int var1;

int main()
{
    printf("Please input a number: \n");
    scanf("%d", &var1);
    
    if (var1 % 2 ==1)
    {
        printf("%d is odd.", var1);
    }
    else if (var1 % 2 ==0)
    {
        printf("%d is even.", var1);
    
    }
    return 0;
}