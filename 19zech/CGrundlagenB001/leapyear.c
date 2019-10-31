#include <stdio.h>

int year;

int main()
{
    printf("Please input a year; \n");
    scanf("%d", &year);

    if (year % 4 ==0)
    {
        printf("%d is a leap year.", year);
    }
    else if (year % 4 ==1)
    {
        printf("%d is not a leap year.", year);
    }
    else if (year % 4 ==2)
    {
        printf("%d is not a leap year.", year);
    }
    else if (year % 4 ==3)
    {
        printf("%d is not a leap year.", year);
    }
    return 0;
}