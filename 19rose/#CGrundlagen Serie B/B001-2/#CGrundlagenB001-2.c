#include <stdio.h>

int main() {
    int zzz;
    printf("Geben Sie eine Zahl an!");
    scanf("%d", &zzz);
    if ((zzz % 2) == 1) {
        printf("Die Zahl %d ist ungerade!", zzz);
    } else {
        printf("Die Zahl %d ist gerade!", zzz);
    }
}