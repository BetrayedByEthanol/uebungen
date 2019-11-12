#include <stdio.h>
#include <math.h>

int num, num_length, num_calc, numb;

int up_numb(int numb) {
    if (numb >= num_length) return 1;
    return numb+1;
}

int ascii_1(int numb, int num_array[]) {//ASCII Funktion Muster " ### "
    printf(" %i", num_array[numb]);
    numb = up_numb(numb);
    printf("%i", num_array[numb]);
    numb = up_numb(numb);
    printf("%i  ", num_array[numb]);
    numb = up_numb(numb);
    return numb;
}

int ascii_2(int numb, int num_array[]) {//ASCII Funktion Muster "  #  "
    printf("  %i   ", num_array[numb]);
    numb = up_numb(numb);
    return numb;
}

int ascii_3(int numb, int num_array[]) {//ASCII Funktion Muster "   # "
    printf("   %i  ", num_array[numb]);
    numb = up_numb(numb);
    return numb;
}

int ascii_4(int numb, int num_array[]) {//ASCII Funktion Muster "#####"
    printf("%i", num_array[numb]);
    numb = up_numb(numb);
    printf("%i", num_array[numb]);
    numb = up_numb(numb);
    printf("%i", num_array[numb]);
    numb = up_numb(numb);
    printf("%i", num_array[numb]);
    numb = up_numb(numb);
    printf("%i ", num_array[numb]);
    numb = up_numb(numb);
    return numb;
}

int ascii_5(int numb, int num_array[]) {//ASCII Funktion Muster "#   #"
    printf("%i   ", num_array[numb]);
    numb = up_numb(numb);
    printf("%i ", num_array[numb]);
    numb = up_numb(numb);
    return numb;
}

int ascii_6(int numb, int num_array[]) {//ASCII Funktion Muster " ##  "
    printf(" %i", num_array[numb]);
    numb = up_numb(numb);
    printf("%i   ", num_array[numb]);
    numb = up_numb(numb);
    return numb;
}

int ascii_7(int numb, int num_array[]) {//ASCII Funktion Muster "  ## "
    printf("  %i", num_array[numb]);
    numb = up_numb(numb);
    printf("%i  ", num_array[numb]);
    numb = up_numb(numb);
    return numb;
}

int ascii_8(int numb, int num_array[]) {//ASCII Funktion Muster "#    "
    printf("%i     ", num_array[numb]);
    numb = up_numb(numb);
    return numb;
}

int ascii_9(int numb, int num_array[]) {//ASCII Funktion Muster "    #"
    printf("    %i ", num_array[numb]);
    numb = up_numb(numb);
    return numb;
}

int ascii_10(int numb, int num_array[]) {//ASCII Funktion Muster " # # "
    printf(" %i ", num_array[numb]);
    numb = up_numb(numb);
    printf("%i  ", num_array[numb]);
    numb = up_numb(numb);
    return numb;
}

int ascii_11(int numb, int num_array[]) {//ASCII Funktion Muster "#### "
    printf("%i", num_array[numb]);
    numb = up_numb(numb);
    printf("%i", num_array[numb]);
    numb = up_numb(numb);
    printf("%i", num_array[numb]);
    numb = up_numb(numb);
    printf("%i  ", num_array[numb]);
    numb = up_numb(numb);
    return numb;
}

int ascii_12(int numb, int num_array[]) {//ASCII Funktion Muster " ####"
    printf(" %i", num_array[numb]);
    numb = up_numb(numb);
    printf("%i", num_array[numb]);
    numb = up_numb(numb);
    printf("%i", num_array[numb]);
    numb = up_numb(numb);
    printf("%i ", num_array[numb]);
    numb = up_numb(numb);
    return numb;
}

int ascii_13(int numb, int num_array[]) {//ASCII Funktion Muster "#  # "
    printf("%i  ", num_array[numb]);
    numb = up_numb(numb);
    printf("%i  ", num_array[numb]);
    numb = up_numb(numb);
    return numb;
}

int ascii_14(int numb, int num_array[]) {//ASCII Funktion Muster " #   "
    printf(" %i    ", num_array[numb]);
    numb = up_numb(numb);
    return numb;
}

int main() {
    while (1) {
        printf("Gebe eine dreistellige Zahl ein: ");//Eingabe der Zahl
        scanf("%i", &num);
        num_calc = num;
        num_length = 1;
        numb = 1;
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
                        case 0: numb = ascii_1(numb, num_array); break;
                        case 1: numb = ascii_2(numb, num_array); break;
                        case 2: numb = ascii_1(numb, num_array); break;
                        case 3: numb = ascii_1(numb, num_array); break;
                        case 4: numb = ascii_3(numb, num_array); break;
                        case 5: numb = ascii_4(numb, num_array); break;
                        case 6: numb = ascii_1(numb, num_array); break;
                        case 7: numb = ascii_4(numb, num_array); break;
                        case 8: numb = ascii_1(numb, num_array); break;
                        case 9: numb = ascii_1(numb, num_array); break;
                    }
                }
                printf("\n");
                break;
                case 1://2.Zeile
                for (int i=1; i<=num_length; i++) {
                    switch (num_array[i]) {
                        case 0: numb = ascii_5(numb, num_array); break;
                        case 1: numb = ascii_6(numb, num_array); break;
                        case 2: numb = ascii_5(numb, num_array); break;
                        case 3: numb = ascii_5(numb, num_array); break;
                        case 4: numb = ascii_7(numb, num_array); break;
                        case 5: numb = ascii_8(numb, num_array); break;
                        case 6: numb = ascii_5(numb, num_array); break;
                        case 7: numb = ascii_9(numb, num_array); break;
                        case 8: numb = ascii_5(numb, num_array); break;
                        case 9: numb = ascii_5(numb, num_array); break;
                    }
                }
                printf("\n");
                break;
                case 2://3. Zeile
                for (int i=1; i<=num_length; i++) {
                    switch (num_array[i]) {
                        case 0: numb = ascii_5(numb, num_array); break;
                        case 1: numb = ascii_2(numb, num_array); break;
                        case 2: numb = ascii_5(numb, num_array); break;
                        case 3: numb = ascii_9(numb, num_array); break;
                        case 4: numb = ascii_10(numb, num_array); break;
                        case 5: numb = ascii_8(numb, num_array); break;
                        case 6: numb = ascii_8(numb, num_array); break;
                        case 7: numb = ascii_9(numb, num_array); break;
                        case 8: numb = ascii_5(numb, num_array); break;
                        case 9: numb = ascii_5(numb, num_array); break;
                    }
                }
                printf("\n");
                break;
                case 3://4.Zeile
                for (int i=1; i<=num_length; i++) {
                    switch (num_array[i]) {
                        case 0: numb = ascii_5(numb, num_array); break;
                        case 1: numb = ascii_2(numb, num_array); break;
                        case 2: numb = ascii_3(numb, num_array); break;
                        case 3: numb = ascii_1(numb, num_array); break;
                        case 4: numb = ascii_13(numb, num_array); break;
                        case 5: numb = ascii_11(numb, num_array); break;
                        case 6: numb = ascii_11(numb, num_array); break;
                        case 7: numb = ascii_3(numb, num_array); break;
                        case 8: numb = ascii_1(numb, num_array); break;
                        case 9: numb = ascii_12(numb, num_array); break;
                    }
                }
                printf("\n");
                break;
                case 4://5.Zeile
                for (int i=1; i<=num_length; i++) {
                    switch (num_array[i]) {
                        case 0: numb = ascii_5(numb, num_array); break;
                        case 1: numb = ascii_2(numb, num_array); break;
                        case 2: numb = ascii_2(numb, num_array); break;
                        case 3: numb = ascii_9(numb, num_array); break;
                        case 4: numb = ascii_4(numb, num_array); break;
                        case 5: numb = ascii_9(numb, num_array); break;
                        case 6: numb = ascii_5(numb, num_array); break;
                        case 7: numb = ascii_2(numb, num_array); break;
                        case 8: numb = ascii_5(numb, num_array); break;
                        case 9: numb = ascii_9(numb, num_array); break;
                    }
                }
                printf("\n");
                break;
                case 5://6.Zeile
                for (int i=1; i<=num_length; i++) {
                    switch (num_array[i]) {
                        case 0: numb = ascii_5(numb, num_array); break;
                        case 1: numb = ascii_2(numb, num_array); break;
                        case 2: numb = ascii_14(numb, num_array); break;
                        case 3: numb = ascii_5(numb, num_array); break;
                        case 4: numb = ascii_3(numb, num_array); break;
                        case 5: numb = ascii_5(numb, num_array); break;
                        case 6: numb = ascii_5(numb, num_array); break;
                        case 7: numb = ascii_14(numb, num_array); break;
                        case 8: numb = ascii_5(numb, num_array); break;
                        case 9: numb = ascii_5(numb, num_array); break;
                    }
                }
                printf("\n");
                break;
                case 6://7.Zeile
                for (int i=1; i<=num_length; i++) {
                    switch (num_array[i]) {
                        case 0: numb = ascii_1(numb, num_array); break;
                        case 1: numb = ascii_1(numb, num_array); break;
                        case 2: numb = ascii_4(numb, num_array); break;
                        case 3: numb = ascii_1(numb, num_array); break;
                        case 4: numb = ascii_3(numb, num_array); break;
                        case 5: numb = ascii_1(numb, num_array); break;
                        case 6: numb = ascii_1(numb, num_array); break;
                        case 7: numb = ascii_8(numb, num_array); break;
                        case 8: numb = ascii_1(numb, num_array); break;
                        case 9: numb = ascii_1(numb, num_array); break;
                    }
                }
                printf("\n");
                break;
            }
        }
    }
    return 0;
}