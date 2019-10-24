#include <stdio.h>

int var1;
int var2;
int var3;
int sum;

int main()
{
    printf("Input 3 varibales in the form of x,y,z; \n");
    scanf("%d,%d,%d", &var1, &var2, &var3);
    printf("Input: %d,%d,%d", var1, var2, var3);
    sum= var1+var2+var3;
    printf("\nEquation: %d+%d+%d=%d", var1, var2, var3, sum);
    printf("\nThe sum of the numbers %d, %d and %d is: %d.", var1, var2, var3, sum);

    //printf("%d", sum);
    
    return 0;
}