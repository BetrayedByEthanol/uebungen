
#include <stdio.h>

int main()
{
    int array[10], n = 10, c, d, swap;

    printf("Geben Sie bitte %d Zahlen ein.\n", n);

    for(c=0;c<n;c++)
        scanf("%d", &array[c]);
    
    for(c=0;c<n-1;c++)
    {
        for(d=0;d<n-c-1;d++)
        {
            if(array[d]>array[d+1])
            {
                swap = array[d];
                array[d]=array[d+1];
                array[d+1]=swap;
            }
        }
    }
    printf("Die sortierte Reihenfolge ist:\n");
    for(c=0;c<n;c++)
        printf("%d ", array[c]);
        
    return 0;

}