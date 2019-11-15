#include <stdio.h>

int main() {
    float celsius = 0, fahrenheit = 0;
    printf("Geben Sie die Temperatur in Celsius an!\n");
    scanf("%f", &celsius);
    fahrenheit = celsius * 1.8 + 32;
    printf("Die Temperatur in Fahrenheit ist %f Grad.", fahrenheit);
}