#include <stdio.h>

void druck(int zuhl, int zuhle, int spuhlte, int zuffer);
int fdruck(int zuhl, int zuhle, int spuhlte, int zuffer);
int charToInt(char cc);
int speicher[10][7][5] = { 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1 , 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1,1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1 , 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0};

int main() {
    char eingabe[50] = "";
    int i = 0, i2 = 0, i3 = 0, i4 = 0, i5 = 0, orderZ = 0, order[20], lock = 1, check = 0;
    printf("Geben Sie Zahlen ein, die die Ziffern 0-9 enthalten koennen!(Bitte mit ! Eingabe beenden)\n");
    scanf("%s", &eingabe);                   
    while(lock < 4) {
        printf("Start  (%d)\n", charToInt(eingabe[i]));
        if(charToInt(eingabe[i]) >= 0) {
            printf("Zahl erkannt\n");
            order[orderZ] = charToInt(eingabe[i]);
            orderZ ++;
            check = 0;
        } else if(charToInt(eingabe[i]) == -1) {
            printf("Zahl wird berechnet\n");
            for(i2 = 0; i2 < 7; i2++) {
                printf("Zeile:");
                i3 = 0;
                for(i4 = 0; i4 < orderZ; i4++) {
                    printf(" zahl");
                    for(i5 = 0; i5 < 5; i5++) {
                        printf(":");
                        druck(order[i4], i2 + 1, i5 + 1, order[i3 % (orderZ + 1)]);
                        if(fdruck(order[i4], i2 + 1, i5 + 1, order[i3 % (orderZ + 1)]) == 1) {
                            i3 ++;
                        }
                    }
                }
                printf("\n");
            }
            if (check = 1) {
                
            }
            check = 1;
        }
        printf("Ende\n");
        lock = lock + 1;
        i ++;
    }
}

int charToInt(char cc) {
    if(cc == 48) return 0;
    else if(cc == 49) return 1;
    else if(cc == 50) return 2;
    else if(cc == 51) return 3;
    else if(cc == 52) return 4;
    else if(cc == 53) return 5;
    else if(cc == 54) return 6;
    else if(cc == 55) return 7;
    else if(cc == 56) return 8;
    else if(cc == 57) return 9;
    else return -1;
    
}

void druck(int zuhl, int zuhle, int spuhlte, int zuffer) {
    if(speicher[zuhl][zuhle][spuhlte] == 1) {
        printf("%d", zuffer);
    }
    if(speicher[zuhl][zuhle][spuhlte] == 0) {
        printf(" ");
    }
}

int fdruck(int zuhl, int zuhle, int spuhlte, int zuffer) {
    if(speicher[zuhl][zuhle][spuhlte] == 1) {
        return 1;
    }
    if(speicher[zuhl][zuhle][spuhlte] == 0) {
        return 0;
    }
}