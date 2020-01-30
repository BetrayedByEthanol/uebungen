#include<stdio.h>

float rest(float num)
{
    float rest;

    while(num > 1)
    {
        num--;
    }
    rest = num;
    return(rest);
}

void main(void)
{
    float i = 1, j, num = 1, primcount, prim, primbool = 0;
    printf("%d\n", 19/5);

    for(primcount = 0; primcount < 101; primcount++)
    {
        /*if(primbool == 1)
        {
            printf("%lf\n", num);
            num++;
        }
        if(primbool == 0)
        {
            primcount--;
            num++;
        }*/

        printf("%lf", num);
        if(primbool == 1)
        {
            num++;
        }
        
        for(i = 1; i <= num; i++)
        {
            prim = num / i;
            primbool = 1;
            if(i != num && i != 1 && rest(prim) == 0)
            {
                primbool = 0;
                num = num + 1;
                i = 1;
            }
        }
    }
}