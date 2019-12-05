#include<stdio.h>


void main(void)
{
    int i, primnumb, num = 1, primcount, prim, primbool = 0;

    printf("Wie viele Primzahlen moechten Sie ausgegeben haben?\n");
    scanf("%d", &primnumb);
    primnumb++;

    for(primcount = 0; primcount < primnumb; primcount++)
    {

        printf("%d\n", num);
        if(num == 1)
        {
            num++;
        }
        if(primbool == 1)
        {
            num++;
        }
        
        for(i = 2; i <= num; i++)
        {
            prim = num / i;
            primbool = 1;
            if(i * prim == num && i != num)
            {
                primbool = 0;
                num = num + 1;
                i = 2;
            }
        }
    }
}
