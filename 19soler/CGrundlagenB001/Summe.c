#include<stdio.h>

int main()
{
    int num1=0;
    int num2=0;
    int num3=0;
    int sum=0;

    printf("Schreiben Sie drei Ganzzahlen im x,y,z Format um die Summe zu ermitteln\n");
    scanf("%d,%d,%d", &num1, &num2, &num3);
    printf("Ihre Eingabe: %d,%d,%d", num1, num2, num3);
    sum = num1 + num2 + num3;
    printf("\nRechnung: %d+%d+%d=%d", num1, num2, num3, sum);
    printf("\nDie Summe Ihrer Eingaben betraegt: %d", sum);

    return 0;
}