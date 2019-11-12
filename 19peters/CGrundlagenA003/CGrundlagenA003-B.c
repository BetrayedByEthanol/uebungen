#include <stdio.h>
#include <math.h>

int main() {
    int num, num_length, num_calc;
    while (1) {
        printf("Gebe eine Zahl ein: ");//Eingabe der Zahl
        scanf("%i", &num);
        num_calc = num;
        num_length = 1;
        while (num_calc / 10 >= 1) {//Bestimmung der Zahllänge
            num_length++;
            num_calc /= 10;
        }
        for (int i=0; i<num_length; i++) {//Zahl wird in ASCII umgewandelt
            int pot = pow(10, num_length-i);
            switch ((num % pot)/(pot/10)) {
                case 0: printf(" ### \n#   #\n#   #\n#   #\n#   #\n#   #\n ### \n"); break;
                case 1: printf("  #  \n ##  \n  #  \n  #  \n  #  \n  #  \n ### \n"); break;
                case 2: printf(" ### \n#   #\n#   #\n   # \n  #  \n #   \n#####\n"); break;
                case 3: printf(" ### \n#   #\n    #\n ### \n    #\n#   #\n ### \n"); break;
                case 4: printf("   # \n  ## \n # # \n#  # \n#####\n   # \n   # \n"); break;
                case 5: printf("#####\n#    \n#    \n#### \n    #\n#   #\n ### \n"); break;
                case 6: printf(" ### \n#   #\n#    \n#### \n#   #\n#   #\n ### \n"); break;
                case 7: printf("#####\n    #\n    #\n   # \n  #  \n #   \n#    \n"); break;
                case 8: printf(" ### \n#   #\n#   #\n ### \n#   #\n#   #\n ### \n"); break;
                case 9: printf(" ### \n#   #\n#   #\n ####\n    #\n#   #\n ### \n"); break;
                default: printf("Zahl ist ungueltig!"); break;
            }
        }
    }
    return 0;
}