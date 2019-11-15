#include <stdio.h>

int main() {
    int jahreingabe;
    printf("Welches Jahr soll getestet werden, ob es ein Schalt Jahr ist?\n");
    scanf("%d", &jahreingabe);
    if(((jahreingabe % 4) == 0) && ((jahreingabe % 100) != 0)) {
        printf("Das Jahr %d ist ein Schaltjahr!", jahreingabe);
    } else if(((jahreingabe % 100) == 0) && ((jahreingabe % 400) != 0)) {
        printf("Das Jahr %d ist kein Schaltjahr!", jahreingabe);
    } else if((jahreingabe % 400) == 0) {
        printf("Das Jahr %d ist ein Schaltjahr!", jahreingabe);
    } else {
        printf("Das Jahr %d ist kein Schaltjahr!", jahreingabe);
    }
}