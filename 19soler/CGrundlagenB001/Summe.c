#include<stdio.h>

int main()
{
    //here we define four variables
    int num1=0;
    int num2=0;
    int num3=0;
    int sum=0;

    //now we ask the users to input his 3 numbers he wants to add
    printf("Schreiben Sie drei Ganzzahlen im x,y,z Format um die Summe zu ermitteln\n");
    scanf("%d,%d,%d", &num1, &num2, &num3);
    //we repeat his numbers so he can double check
    printf("Ihre Eingabe: %d,%d,%d", num1, num2, num3);
    //now wwe add the three numbers and put it in the variable 'sum'
    sum = num1 + num2 + num3;
    //now we tell them the calculation and the sum
    printf("\nRechnung: %d+%d+%d=%d", num1, num2, num3, sum);
    printf("\nDie Summe Ihrer Eingaben betraegt: %d", sum);

    return 0;
}