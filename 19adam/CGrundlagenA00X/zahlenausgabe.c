#include<stdio.h>


void printout(char firstline[6], char scndline[6], char thrdline[6], char frthline[6], char ffthline[6], char sixtline[6], char svthline[6])
{
    int l = 0;
    printf("\n");
    while(l < 6)
    {
        printf("%c", firstline[l]);
        l++;
    }
    printf("\n");
    l = 0;
    while(l < 6 )
    {
        printf("%c", scndline[l]);
        l++;
    }
    printf("\n");
    l = 0;
    while(l < 6)
    {
        printf("%c", thrdline[l]);
        l++;
    }
    printf("\n");
    l = 0;
    while(l < 6)
    {
        printf("%c", frthline[l]);
        l++;
    }
    printf("\n");
    l = 0;
    while(l < 6)
    {
        printf("%c", ffthline[l]);
        l++;
    }
    printf("\n");
    l = 0;
    while(l < 6)
    {
        printf("%c", sixtline[l]);
        l++;
    }
    printf("\n");
    l = 0;
    while(l < 6)
    {
        printf("%c", svthline[l]);
        l++;
    }

}

int parseint(char a)
{
    int b;
    switch(a)
    {
        case '0':
            b = 0;
            break;
        case '1':
            b = 1;
            break;
        case '2':
            b = 2;
            break;
        case '3':
            b = 3;
            break;
        case '4':
            b = 4;
            break;
        case '5':
            b = 5;
            break;
        case '6':
            b = 6;
            break;
        case '7':
            b = 7;
            break;
        case '8':
            b = 8;
            break;
        case '9':
            b = 9;
            break;
    }  
    return(b); 
}

void null(int l, char liste[l])
{
    while(l >= 0)
    {
        liste[l] = ' ';
        l--;
    }
}

void firstline(char ziffereins, char zifferzwei, char zifferdrei)
{
    int count = 3, count2 = 0;
    char flzero[6], flone[6], current;
    //flzero[0] = flzero[4] = flzero[5] = flone[0] = flone[1] = flone[3] = flone[4] = flone[5] = ' ';
    null(6, flzero);
    null(6, flone);
    flzero[1] = flzero[2] = flzero[3] = flone[2] = '#';
    while(count > 0)
    {
        if(count == 3)
        {
            current = ziffereins;
        }
        else if(count == 2)
        {
            current = zifferzwei;
        }
        else if(count == 1)
        {
            current = zifferdrei;
        }
        switch(current)
        {
            case '0':
                while(count2 < 6)
                {
                    printf("%c", flzero[count2]);
                    count2++;
                }
                break;
            case '1':
                while(count2 < 6)
                {
                    printf("%c", flone[count2]);
                    count2++;
                }
                break;
        }
        count2 = 0;
        count--;
    }
    printf("\n");
}

void secondline(char ziffereins, char zifferzwei, char zifferdrei)
{
    int count = 3, count2 = 0;
    char slzero[6], slone[6], current;
    null(6, slzero);
    null(6, slone);
    slzero[0] = slzero[4] = slone[1] = slone[2] = '#';
    while(count > 0)
    {
        if(count == 3)
        {
            current = ziffereins;
        }
        else if(count == 2)
        {
            current = zifferzwei;
        }
        else if(count == 1)
        {
            current = zifferdrei;
        }
        switch(current)
        {
            case '0':
                while(count2 < 6)
                {
                    printf("%c", slzero[count2]);
                    count2++;
                }
                break;
            case '1':
                while(count2 < 6)
                {
                    printf("%c", slone[count2]);
                    count2++;
                }
                break;
        }
        count2 = 0;
        count--;
    }
    printf("\n");
}

void thirdline(char ziffereins, char zifferzwei, char zifferdrei)
{
    int count = 3, count2 = 0;
    char tlzero[6], tlone[6], current;
    null(6, tlzero);
    null(6, tlone);
    tlzero[0] = tlzero[4] = tlone[2] = '#';
    while(count > 0)
    {
        if(count == 3)
        {
            current = ziffereins;
        }
        else if(count == 2)
        {
            current = zifferzwei;
        }
        else if(count == 1)
        {
            current = zifferdrei;
        }
        switch(current)
        {
            case '0':
                while(count2 < 6)
                {
                    printf("%c", tlzero[count2]);
                    count2++;
                }
                break;
            case '1':
                while(count2 < 6)
                {
                    printf("%c", tlone[count2]);
                    count2++;
                }
                break;
        }
        count2 = 0;
        count--;
    }
    printf("\n");
}

void fourthline(char ziffereins, char zifferzwei, char zifferdrei)
{
    int count = 3, count2 = 0;
    char ftlzero[6], ftlone[6], current;
    null(6, ftlzero);
    null(6, ftlone);
    ftlzero[0] = ftlzero[4] = ftlone[2] = '#';
    while(count > 0)
    {
        if(count == 3)
        {
            current = ziffereins;
        }
        else if(count == 2)
        {
            current = zifferzwei;
        }
        else if(count == 1)
        {
            current = zifferdrei;
        }
        switch(current)
        {
            case '0':
                while(count2 < 6)
                {
                    printf("%c", ftlzero[count2]);
                    count2++;
                }
                break;
            case '1':
                while(count2 < 6)
                {
                    printf("%c", ftlone[count2]);
                    count2++;
                }
                break;
        }
        count2 = 0;
        count--;
    }
    printf("\n");
}

void fifthline(char ziffereins, char zifferzwei, char zifferdrei)
{
    int count = 3, count2 = 0;
    char fflzero[6], fflone[6], current;
    null(6, fflzero);
    null(6, fflone);
    fflzero[0] = fflzero[4] = fflone[2] = '#';
    while(count > 0)
    {
        if(count == 3)
        {
            current = ziffereins;
        }
        else if(count == 2)
        {
            current = zifferzwei;
        }
        else if(count == 1)
        {
            current = zifferdrei;
        }
        switch(current)
        {
            case '0':
                while(count2 < 6)
                {
                    printf("%c", fflzero[count2]);
                    count2++;
                }
                break;
            case '1':
                while(count2 < 6)
                {
                    printf("%c", fflone[count2]);
                    count2++;
                }
                break;
        }
        count2 = 0;
        count--;
    }
    printf("\n");
}

void sixthline(char ziffereins, char zifferzwei, char zifferdrei)
{
    int count = 3, count2 = 0;
    char sxlzero[6], sxlone[6], current;
    null(6, sxlzero);
    null(6, sxlone);
    sxlzero[0] = sxlzero[4] = sxlone[2] = '#';
    while(count > 0)
    {
        if(count == 3)
        {
            current = ziffereins;
        }
        else if(count == 2)
        {
            current = zifferzwei;
        }
        else if(count == 1)
        {
            current = zifferdrei;
        }
        switch(current)
        {
            case '0':
                while(count2 < 6)
                {
                    printf("%c", sxlzero[count2]);
                    count2++;
                }
                break;
            case '1':
                while(count2 < 6)
                {
                    printf("%c", sxlone[count2]);
                    count2++;
                }
                break;
        }
        count2 = 0;
        count--;
    }
    printf("\n");
}

void seventhline(char ziffereins, char zifferzwei, char zifferdrei)
{
    int count = 3, count2 = 0;
    char svlzero[6], svlone[6], current;
    null(6, svlzero);
    null(6, svlzero);
    svlzero[1] = svlzero[2] = svlzero[3] = svlone[1] = svlone[2] = svlone[3] = '#';
    while(count > 0)
    {
        if(count == 3)
        {
            current = ziffereins;
        }
        else if(count == 2)
        {
            current = zifferzwei;
        }
        else if(count == 1)
        {
            current = zifferdrei;
        }
        switch(current)
        {
            case '0':
                while(count2 < 6)
                {
                    printf("%c", svlzero[count2]);
                    count2++;
                }
                break;
            case '1':
                while(count2 < 6)
                {
                    printf("%c", svlone[count2]);
                    count2++;
                }
                break;
        }
        count2 = 0;
        count--;
    }
    printf("\n");
}

void dreistellig(char ziffereins, char zifferzwei, char zifferdrei)
{
    firstline(ziffereins, zifferzwei, zifferdrei);
    secondline(ziffereins, zifferzwei, zifferdrei);
    thirdline(ziffereins, zifferzwei, zifferdrei);
    fourthline(ziffereins, zifferzwei, zifferdrei);
    fifthline(ziffereins, zifferzwei, zifferdrei);
    sixthline(ziffereins, zifferzwei, zifferdrei);
    seventhline(ziffereins, zifferzwei, zifferdrei);
}

void eingeben(int eingabe)
{
    //0
    char flzero[6], slzero[6], tlzero[6], ftlzero[6], fflzero[6], sxlzero[6], svlzero[6];

    flzero[5] = slzero[5] = tlzero[5] = ftlzero[5] = fflzero[5] = sxlzero[5] = svlzero[5] = ' ';
    flzero[1] = flzero[2] = flzero[3] = svlzero[1] = svlzero[2] = svlzero[3] = '#';
    flzero[0] = flzero[4] = svlzero[0] = svlzero[4] = ' ';
    slzero[0] = slzero[4] = tlzero[0] = tlzero[4] = ftlzero[0] = ftlzero[4] = fflzero[0] = fflzero[4] = sxlzero[0] = sxlzero[4] = '#';
    slzero[1] = slzero[2] = slzero[3] = tlzero[1] = tlzero[2] = tlzero[3] = ftlzero[1] = ftlzero[2] = ftlzero[3] = fflzero[1] = fflzero[2] = fflzero[3] = sxlzero[1] = sxlzero[2] = sxlzero[3] = ' ';

    //1
    char flone[6], slone[6], tlone[6], ftlone[6], fflone[6], sxlone[6], svlone[6];

    flone[5] = slone[5] = tlone[5] = ftlone[5] = fflone[5] = sxlone[5] = svlone[5] = ' ';
    flone[2] = slone[2] = tlone[2] = ftlone[2] = fflone[2] = sxlone[2] = svlone[2] = slone[1] = svlone[1] = svlone[3] = '#';
    flone[0] = flone[1] = flone[3] = flone[4] = slone[0] = slone[3] = slone[4] = tlone[0] = tlone[1] = tlone[3] = tlone[4] = ftlone[0] = ftlone[1] = ftlone[3] = ftlone[4] = fflone[0] = fflone[1] = fflone[3] = fflone[4] = sxlone[0] = sxlone[1] = sxlone[3] = sxlone[4] = svlone[0] = svlone[4] = ' ';

    if(eingabe == 0)
    {
        printout(flzero, slzero, tlzero, ftlzero, fflzero, sxlzero, svlzero);
    }
    else if (eingabe == 1)
    {
        printout(flone, slone, tlone, ftlone, fflone, sxlone, svlone);
    }
    else if(eingabe != 0 && eingabe != 1)
    {
        printf("\nGibs noch nisch\n");
    }

}



int main(void)
{
    char a, b, c;
    a = '0';
    c = a;
    b = '1';
    dreistellig(a, b, c);

    int x = 1;
    char f;

    //0
    /*char flzero[6], slzero[6], tlzero[6], ftlzero[6], fflzero[6], sxlzero[6], svlzero[6];
    flzero[5] = slzero[5] = tlzero[5] = ftlzero[5] = fflzero[5] = sxlzero[5] = svlzero[5] = ' ';
    flzero[1] = flzero[2] = flzero[3] = svlzero[1] = svlzero[2] = svlzero[3] = '#';
    flzero[0] = flzero[4] = svlzero[0] = svlzero[4] = ' ';
    slzero[0] = slzero[4] = tlzero[0] = tlzero[4] = ftlzero[0] = ftlzero[4] = fflzero[0] = fflzero[4] = sxlzero[0] = sxlzero[4] = '#';
    slzero[1] = slzero[2] = slzero[3] = tlzero[1] = tlzero[2] = tlzero[3] = ftlzero[1] = ftlzero[2] = ftlzero[3] = fflzero[1] = fflzero[2] = fflzero[3] = sxlzero[1] = sxlzero[2] = sxlzero[3] = ' ';
    //1
    char flone[6], slone[6], tlone[6], ftlone[6], fflone[6], sxlone[6], svlone[6];
    flone[5] = slone[5] = tlone[5] = ftlone[5] = fflone[5] = sxlone[5] = svlone[5] = ' ';
    flone[2] = slone[2] = tlone[2] = ftlone[2] = fflone[2] = sxlone[2] = svlone[2] = slone[1] = svlone[1] = svlone[3] = '#';
    flone[0] = flone[1] = flone[3] = flone[4] = slone[0] = slone[3] = slone[4] = tlone[0] = tlone[1] = tlone[3] = tlone[4] = ftlone[0] = ftlone[1] = ftlone[3] = ftlone[4] = fflone[0] = fflone[1] = fflone[3] = fflone[4] = sxlone[0] = sxlone[1] = sxlone[3] = sxlone[4] = svlone[0] = svlone[4] = ' ';*/

    while(x == 1)
    {
        int auswahl, eingabe, laenge, z, i = 0;
        char zahlenfolge[100];

        printf("Einzelne Zahl / mehrere Zahlen / dreistellige Zahl eingeben? (Eingabe 1 / 2 / 3)\n");
        scanf("%d", &auswahl);

        if(auswahl == 1)
        {
            printf("Bitte geben Sie eine Zahl zwischen 0 und 9 ein.\n");
            scanf("%d", &eingabe);
            eingeben(eingabe);
        }
        else if(auswahl == 2)
        {
            printf("Wie viele Zahlen gedenken Sie einzugeben?\n");
            scanf("%d", &laenge);
            printf("Bitte geben Sie ihre Zahlen ein.\n");
            scanf("%99s", &zahlenfolge);
            while(laenge > 0)
            {
                //printf("%c", zahlenfolge[i]);
                z = parseint(zahlenfolge[i]);
                eingeben(z);
                i++;
                laenge--;
            } 
        }
        else if(auswahl == 3)
        {
            printf("Bitte geben Sie ihre bis zu dreistellige Zahl an.\n");
            scanf("%99s", &zahlenfolge);
            dreistellig(zahlenfolge[0], zahlenfolge[1], zahlenfolge[2]);
        }

        
        /*if(eingabe == 0)
        {
            printout(flzero, slzero, tlzero, ftlzero, fflzero, sxlzero, svlzero);
        }
        else if (eingabe == 1)
        {
            printout(flone, slone, tlone, ftlone, fflone, sxlone, svlone);
        }
        else if(eingabe != 0 && eingabe != 0)
        {
            printf("Gibs noch nisch");
        }*/

        printf("\nFortfahren? ('n' fuer Beenden, beliebige andere Taste zum fortfahren.)\n");
        scanf(" %c", &f);
        
        switch(f)
        {
            default:
                break;
            case 'n':
                x++;
        }

    }

    return 0;
}