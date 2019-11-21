#include <stdio.h>

void druck(int zuhl, int zuhle);
int charToInt(char cc);

int main() {
    char eingabe[50] = "";
    int i = 0, i2 = 0, i3 = 0, orderZ = 0, order[20], lock = 1;
    printf("Geben Sie Zahlen ein, die die Ziffern 0-9 enthalten koennen!(Bitte mit ! Eingabe beenden)\n");
    scanf("%s", &eingabe);                    
    for(i = 0; eingabe[i] != 33; i++) {
        if(eingabe[i] == 48 || eingabe[i] == 49 || eingabe[i] == 50 || eingabe[i] == 51 || eingabe[i] == 52 || eingabe[i] == 53 || eingabe[i] == 54 || eingabe[i] == 55 || eingabe[i] == 56 || eingabe[i] == 57) {
            order[orderZ] = charToInt(eingabe[i]);
            orderZ ++;
        } else {
            for(i2 = 0; i2 < 7; i2++) {
                int wow = i2 + 1;
                for(i3 = 0; i3 < orderZ; i3++) {
                    druck(charToInt(order[i3]), wow);
                    printf(" ");
                }
                printf("\n");
            }
            orderZ = 0;
            printf("\n");             
        }
    }
    for(i2 = 0; i2 < 7; i2++) {
        int wow = i2 + 1;
        for(i3 = 0; i3 < orderZ; i3++) {
            druck(charToInt(order[i3]), wow);
            printf(" ");
        }
        printf("\n");
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
    
}

void druck(int zuhl, int zuhle) {
    if(zuhle == 1) {
        if(zuhl == 0)
            printf(" ### ");
        if(zuhl == 1)
            printf("  #  ");
        if(zuhl == 2)
            printf(" ### ");
        if(zuhl == 3)
            printf(" ### ");
        if(zuhl == 4)
            printf("   # ");
        if(zuhl == 5)
            printf("#####");
        if(zuhl == 6)
            printf(" ### ");
        if(zuhl == 7)
            printf("#####");
        if(zuhl == 8)
            printf(" ### ");
        if(zuhl == 9)
            printf(" ### ");
        
    }
    if(zuhle == 2) {
        if(zuhl == 0)
            printf("#   #");
        if(zuhl == 1)
            printf(" ##  ");
        if(zuhl == 2)
            printf("#   #");
        if(zuhl == 3)
            printf("#   #");
        if(zuhl == 4)
            printf("  ## ");
        if(zuhl == 5)
            printf("#    ");
        if(zuhl == 6)
            printf("#   #");
        if(zuhl == 7)
            printf("    #");
        if(zuhl == 8)
            printf("#   #");
        if(zuhl == 9)
            printf("#   #");
        
    }
    if(zuhle == 3) {
        if(zuhl == 0)
            printf("#   #");
        if(zuhl == 1)
            printf("  #  ");
        if(zuhl == 2)
            printf("#   #");
        if(zuhl == 3)
            printf("    #");
        if(zuhl == 4)
            printf(" # # ");
        if(zuhl == 5)
            printf("#    ");
        if(zuhl == 6)
            printf("#    ");
        if(zuhl == 7)
            printf("    #");
        if(zuhl == 8)
            printf("#   #");
        if(zuhl == 9)
            printf("#   #");
        
    }
    if(zuhle == 4) {
        if(zuhl == 0)
            printf("#   #");
        if(zuhl == 1)
            printf("  #  ");
        if(zuhl == 2)
            printf("   # ");
        if(zuhl == 3)
            printf(" ### ");
        if(zuhl == 4)
            printf("#  # ");
        if(zuhl == 5)
            printf("#### ");
        if(zuhl == 6)
            printf("#### ");
        if(zuhl == 7)
            printf("   # ");
        if(zuhl == 8)
            printf(" ### ");
        if(zuhl == 9)
            printf(" ####");
        
    }
    if(zuhle == 5) {
        if(zuhl == 0)
            printf("#   #");
        if(zuhl == 1)
            printf("  #  ");
        if(zuhl == 2)
            printf("  #  ");
        if(zuhl == 3)
            printf("    #");
        if(zuhl == 4)
            printf("#####");
        if(zuhl == 5)
            printf("    #");
        if(zuhl == 6)
            printf("#   #");
        if(zuhl == 7)
            printf("  #  ");
        if(zuhl == 8)
            printf("#   #");
        if(zuhl == 9)
            printf("    #");
        
    }
    if(zuhle == 6) {
        if(zuhl == 0)
            printf("#   #");
        if(zuhl == 1)
            printf("  #  ");
        if(zuhl == 2)
            printf(" #   ");
        if(zuhl == 3)
            printf("#   #");
        if(zuhl == 4)
            printf("   # ");
        if(zuhl == 5)
            printf("#   #");
        if(zuhl == 6)
            printf("#   #");
        if(zuhl == 7)
            printf(" #   ");
        if(zuhl == 8)
            printf("#   #");
        if(zuhl == 9)
            printf("#   #");
        
    }
    if(zuhle == 7) {
        if(zuhl == 0)
            printf(" ### ");
        if(zuhl == 1)
            printf(" ### ");
        if(zuhl == 2)
            printf("#####");
        if(zuhl == 3)
            printf(" ### ");
        if(zuhl == 4)
            printf("   # ");
        if(zuhl == 5)
            printf(" ### ");
        if(zuhl == 6)
            printf(" ### ");
        if(zuhl == 7)
            printf("#    ");
        if(zuhl == 8)
            printf(" ### ");
        if(zuhl == 9)
            printf(" ### ");
        
    }
    
}