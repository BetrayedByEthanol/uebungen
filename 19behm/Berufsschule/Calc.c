//Einfacher Taschenrechner

#include <stdio.h>

int inp1, inp2, outp;


int division(int x,int y)
{
    outp = inp1/inp2;
    return outp;
}

int mult(int x,int y)
{
    outp = inp1*inp2;
    return outp;
}

int subtr(int x,int y)
{
    outp = inp1 - inp2;
    return outp;
}

int add(int x,int y)
{
    outp = inp1+inp2;
    return outp;
}

int main()
{
char operator;
printf("Dies ist ein einfacher Taschenrechner zum Addieren, Subtrahieren, Multiplizieren und Divivieren von Ganzzahlen\nGueltige Operatoren sind + - * /\n");
scanf("%d%c%d",&inp1,&operator,&inp2);

    while(1)
    {
    if(operator == '+')
        add(inp1,inp2);
    else if(operator == '-')
        subtr(inp1,inp2);
    else if(operator == '*')
        mult(inp1,inp2);
    else if(operator == '/')
        division(inp1,inp2);
    else    
        printf("Ungueltige Eingabe.");

    printf("Ergebnis: %d", outp);
    }


return 0;


}

