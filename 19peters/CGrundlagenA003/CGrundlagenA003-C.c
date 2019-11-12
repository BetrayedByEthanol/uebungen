#include <stdio.h>
#include <math.h>

int main() {
    int num, num_length, num_calc;
    while (1) {
        printf("Gebe eine dreistellige Zahl ein: ");//Eingabe der Zahl
        scanf("%i", &num);
        num_calc = num;
        num_length = 1;
        while (num_calc / 10 >= 1) {//Bestimmung der Zahllänge
            num_length++;
            num_calc /= 10;
        }
        int num_array[num_length];
        for (int i=0; i<num_length; i++) {//Ziffern der Zahl zerlegen und in einem Array zusammenfassen
            int pot = pow(10, num_length-i);
            num_array[i+1] = (num % pot)/(pot/10);
        }
        for (int i=0; i<7; i++) {//ASCII Zeile 1-7
            switch (i) {
                case 0://1. Zeile
                for (int i=1; i<=num_length; i++) {
                    switch (num_array[i]) {
                        case 0: printf(" ###  "); break;
                        case 1: printf("  #   "); break;
                        case 2: printf(" ###  "); break;
                        case 3: printf(" ###  "); break;
                        case 4: printf("   #  "); break;
                        case 5: printf("##### "); break;
                        case 6: printf(" ###  "); break;
                        case 7: printf("##### "); break;
                        case 8: printf(" ###  "); break;
                        case 9: printf(" ###  "); break;
                    }
                }
                printf("\n");
                break;
                case 1://2.Zeile
                for (int p=1; p<=num_length; p++) {
                    switch (num_array[p]) {
                        case 0: printf("#   # "); break;
                        case 1: printf(" ##   "); break;
                        case 2: printf("#   # "); break;
                        case 3: printf("#   # "); break;
                        case 4: printf("  ##  "); break;
                        case 5: printf("#     "); break;
                        case 6: printf("#   # "); break;
                        case 7: printf("    # "); break;
                        case 8: printf("#   # "); break;
                        case 9: printf("#   # "); break;
                    }
                }
                printf("\n");
                break;
                case 2://3. Zeile
                for (int p=1; p<=num_length; p++) {
                    switch (num_array[p]) {
                        case 0: printf("#   # "); break;
                        case 1: printf("  #   "); break;
                        case 2: printf("#   # "); break;
                        case 3: printf("    # "); break;
                        case 4: printf(" # #  "); break;
                        case 5: printf("#     "); break;
                        case 6: printf("#     "); break;
                        case 7: printf("    # "); break;
                        case 8: printf("#   # "); break;
                        case 9: printf("#   # "); break;
                    }
                }
                printf("\n");
                break;
                case 3://4.Zeile
                for (int p=1; p<=num_length; p++) {
                    switch (num_array[p]) {
                        case 0: printf("#   # "); break;
                        case 1: printf("  #   "); break;
                        case 2: printf("   #  "); break;
                        case 3: printf(" ###  "); break;
                        case 4: printf("#  #  "); break;
                        case 5: printf("####  "); break;
                        case 6: printf("####  "); break;
                        case 7: printf("   #  "); break;
                        case 8: printf(" ###  "); break;
                        case 9: printf(" #### "); break;
                    }
                }
                printf("\n");
                break;
                case 4://5.Zeile
                for (int p=1; p<=num_length; p++) {
                    switch (num_array[p]) {
                        case 0: printf("#   # "); break;
                        case 1: printf("  #   "); break;
                        case 2: printf("  #   "); break;
                        case 3: printf("    # "); break;
                        case 4: printf("##### "); break;
                        case 5: printf("    # "); break;
                        case 6: printf("#   # "); break;
                        case 7: printf("  #   "); break;
                        case 8: printf("#   # "); break;
                        case 9: printf("    # "); break;
                    }
                }
                printf("\n");
                break;
                case 5://6.Zeile
                for (int p=1; p<=num_length; p++) {
                    switch (num_array[p]) {
                        case 0: printf("#   # "); break;
                        case 1: printf("  #   "); break;
                        case 2: printf(" #    "); break;
                        case 3: printf("#   # "); break;
                        case 4: printf("   #  "); break;
                        case 5: printf("#   # "); break;
                        case 6: printf("#   # "); break;
                        case 7: printf(" #    "); break;
                        case 8: printf("#   # "); break;
                        case 9: printf("#   # "); break;
                    }
                }
                printf("\n");
                break;
                case 6://7.Zeile
                for (int p=1; p<=num_length; p++) {
                    switch (num_array[p]) {
                        case 0: printf(" ###  "); break;
                        case 1: printf(" ###  "); break;
                        case 2: printf("##### "); break;
                        case 3: printf(" ###  "); break;
                        case 4: printf("   #  "); break;
                        case 5: printf(" ###  "); break;
                        case 6: printf(" ###  "); break;
                        case 7: printf("#     "); break;
                        case 8: printf(" ###  "); break;
                        case 9: printf(" ###  "); break;
                    }
                }
                printf("\n");
                break;
            }
        }
    }
    return 0;
}