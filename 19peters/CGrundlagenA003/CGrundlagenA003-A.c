#include <stdio.h>

int main() {
    int num;
    while (1) {
        printf("Gebe eine Zahl zwischen 0-9 ein: ");//Eingabe der Zahl
        scanf("%i", &num);
        switch (num) {// Zahl wird in ASCII umgewandelt
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
            default: printf("Zahl ist ungültig!"); break;
        }
    }
    return 0;
}