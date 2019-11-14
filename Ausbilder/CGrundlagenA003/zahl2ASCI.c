#include <stdio.h>

int zeichen_0[7][5] = {{0, 1, 1, 1, 0}, {1, 0, 0, 0, 1}, {1, 0, 0, 0, 1}, {1, 0, 0, 0, 1}, {1, 0, 0, 0, 1}, {1, 0, 0, 0, 1}, {0, 1, 1, 1, 0}};
int zeichen_1[7][5] = {{0, 0, 1, 0, 0}, {0, 1, 1, 0, 0}, {0, 0, 1, 0, 0}, {0, 0, 1, 0, 0}, {0, 0, 1, 0, 0}, {0, 0, 1, 0, 0}, {0, 1, 1, 1, 0}};
int zeichen_2[7][5] = {{0, 1, 1, 1, 0}, {1, 0, 0, 0, 1}, {1, 0, 0, 0, 1}, {0, 0, 0, 1, 0}, {0, 0, 1, 0, 0}, {0, 1, 0, 0, 0}, {1, 1, 1, 1, 1}};
int zeichen_3[7][5] = {{0, 1, 1, 1, 0}, {1, 0, 0, 0, 1}, {0, 0, 0, 0, 1}, {0, 1, 1, 1, 0}, {0, 0, 0, 0, 1}, {1, 0, 0, 0, 1}, {0, 1, 1, 1, 0}};
int zeichen_4[7][5] = {{0, 0, 0, 1, 0}, {0, 0, 1, 1, 0}, {0, 1, 0, 1, 0}, {1, 0, 0, 1, 0}, {1, 1, 1, 1, 1}, {0, 0, 0, 1, 0}, {0, 0, 0, 1, 0}};
int zeichen_5[7][5] = {{1, 1, 1, 1, 1}, {1, 0, 0, 0, 0}, {1, 0, 0, 0, 0}, {1, 1, 1, 1, 0}, {0, 0, 0, 0, 1}, {1, 0, 0, 0, 1}, {0, 1, 1, 1, 0}};
int zeichen_6[7][5] = {{0, 1, 1, 1, 0}, {1, 0, 0, 0, 0}, {1, 0, 0, 0, 0}, {1, 1, 1, 1, 0}, {1, 0, 0, 0, 1}, {1, 0, 0, 0, 1}, {0, 1, 1, 1, 0}};
int zeichen_7[7][5] = {{1, 1, 1, 1, 1}, {0, 0, 0, 0, 1}, {0, 0, 0, 0, 1}, {0, 0, 0, 1, 0}, {0, 0, 1, 0, 0}, {0, 1, 0, 0, 0}, {1, 0, 0, 0, 0}};
int zeichen_8[7][5] = {{0, 1, 1, 1, 0}, {1, 0, 0, 0, 1}, {1, 0, 0, 0, 1}, {0, 1, 1, 1, 0}, {1, 0, 0, 0, 1}, {1, 0, 0, 0, 1}, {0, 1, 1, 1, 0}};
int zeichen_9[7][5] = {{0, 1, 1, 1, 0}, {1, 0, 0, 0, 1}, {1, 0, 0, 0, 1}, {0, 1, 1, 1, 0}, {0, 0, 0, 0, 1}, {1, 0, 0, 0, 1}, {0, 1, 1, 1, 0}};

void printZeichenAt(char zeichen, int zeile, int spalte)
{
    switch (zeichen)
    {
    case 0:
        zeichen_0[zeile][spalte] ? printf("#") : printf(" ");
        break;
    case 1:
        zeichen_1[zeile][spalte] ? printf("#") : printf(" ");
        break;
    case 2:
        zeichen_2[zeile][spalte] ? printf("#") : printf(" ");
        break;
    case 3:
        zeichen_4[zeile][spalte] ? printf("#") : printf(" ");
        break;
    case 4:
        zeichen_4[zeile][spalte] ? printf("#") : printf(" ");
        break;
    case 5:
        zeichen_5[zeile][spalte] ? printf("#") : printf(" ");
        break;
    case 6:
        zeichen_6[zeile][spalte] ? printf("#") : printf(" ");
        break;
    case 7:
        zeichen_7[zeile][spalte] ? printf("#") : printf(" ");
        break;
    case 8:
        zeichen_8[zeile][spalte] ? printf("#") : printf(" ");
        break;
    case 9:
        zeichen_9[zeile][spalte] ? printf("#") : printf(" ");
        break;
    default: printf("x");
    }
}

int main()
{

    int zahl;

    printf("Geben Sie eine Zahl zwischen 0-9 ein:");
    scanf("%d", &zahl);

    for (int zeile = 0; zeile < 7; zeile++)
    {
        for (int spalte = 0; spalte < 5; spalte++)
        {
            printZeichenAt(zahl, zeile, spalte);
        }
        
        printf("\n");
    }

    return 0;
}
