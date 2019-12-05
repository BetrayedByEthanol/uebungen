#include<stdio.h>

void nl(void)
{
    printf("\n");
}

void firstarray(void)
{
    int intarray[8], i = 0;
    for(i = 0; i < 8; i++)
    {
        intarray[i] = 0;
        printf("intarray[%d] : %d\n", i, intarray[i]);
    }
}

void secondarray(void)
{
    int intarray2[8], i = 0;
    for(i = 0; i < 8; i++)
    {
        intarray2[i] = i;
        printf("intarray2[%d] : %d\n", i, intarray2[i]);
    }
} 

void thirdarray()
{
    int f = 8, s = 4, twodimension[f][s], i, i2;
    for(i = 0; i < 8; i++)
    {
        for(i2 = 0; i2 < 4; i2++)
        {
            twodimension[i][i2] = 0;
            printf("twodimension[%d][%d] : %d\n", i, i2, twodimension[i][i2]);
        }
    }
    printf("Speichergroesse des Arrays in Bits/Bytes: %d/%d\n", (sizeof(twodimension) * 8), sizeof(twodimension));
    printf("Speichergroesse der einzelnen Elemente in Bits/Bytes: %d/%d\n", (sizeof(twodimension) / (f * s) * 8), sizeof(twodimension) / (f * s));
    printf("Anzahl der Elemente: %d * %d = %d\n", f, s, (f*s));

}

void vornamen(void)
{
    char vornamen[15][9] = { {'S', 'E', 'B', 'A', 'S', 'T', 'I', 'A', 'N'},
                            {'T', 'I', 'M', ' ', ' ', ' ', ' ', ' ', ' '},
                            {'N', 'I', 'L', 'S', ' ', ' ', ' ', ' ', ' '},
                            {'S', 'E', 'B', 'A', 'S', 'T', 'I', 'A', 'N'},
                            {'V', 'E', 'R', 'A', ' ', ' ', ' ', ' ', ' '},
                            {'M', 'A', 'R', 'C', 'E', 'L', ' ', ' ', ' '},
                            {'D', 'E', 'N', 'N', 'I', 'S', ' ', ' ', ' '},
                            {"MORITZ  "},
                            {"LAURA   "},
                            {"BENJAMIN"},
                            {"CODY    "},
                            {"JULIUS  "},
                            {"NIKLAS  "},
                            {"FELIX   "},
                            {"PABLO   "} };
    int i, i2, i3 = 0;
    for(i = 0; i < 15; i++)
    {
        for(i2 = 0; i2 < 9; i2++)
        {
            printf("vornamen[%d][%d] : %c\n", i, i2, vornamen[i][i2]);
        }  
    }
    char name[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    int  check = 0, found, spacecount = 0, j;
    printf("Name:\n");
    scanf("%8s", &name);
    //printf("%s\n", name);
    //printf("name[5]: %d name[6]: %d\n", name[5], name[6]);
    for(j = 0; j < 9; j++)
    {
        if(name[j] == ' ')
        {
            //printf("j %d\n", j);
            spacecount++;
            //printf("spacecount %d\n", spacecount);
        }
        else if(name[j] == 0)
        {                                                                             //Auskommentiertes zur Kontrolle
            spacecount++;
        }
    }
    //printf("spacecount %d\n", spacecount);
    for(i = 0; i < 15; i++)
    {
        for(i2 = 0; i2 < 9; i2++)
        {
            //printf("i2 %d i %d\n", i, i2);
            if(name[i2] == vornamen[i][i2])
            {
                check++;
                //printf("check %d\n", check);
            }
            else if(name[i2] != vornamen[i][i2])
            {
                check = 0;
                i2 = 9;
            }
            if(check == (9 - spacecount))
            {
                found = i;
                //found2 = i2;
                i = 15;
                i2 = 9;
            }        
        }
    }
    //printf("Gefunden: %s\n", vornamen[found]);
    for(i2 = 0; i2 < 9; i2++)
        {
            printf("vornamen[%d][%d] : %c\n", found, i2, vornamen[found][i2]);
        }                     
}

/*void findname(void)
{
    char name[9];
    int i, i2;
    printf("Name:\n");
    scanf("%8s", &name);
    for(i = 0; i < 15; i++)
    {
        for(i2 = 0; i2 < 9, i2++;)
        {
            if(name[i2] == vornamen[i][i2])        
        }
    }
}*/

void main(void)
{
    firstarray();
    nl();
    secondarray();
    nl();
    thirdarray();
    nl();
    vornamen();
}
