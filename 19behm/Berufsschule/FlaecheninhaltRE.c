
#include <stdio.h>

int main()
{
float length, width;
printf("Um den Flaecheninhalt zu berechnen benoetige ich von Ihnen zwei Werte. Laenge und Breite.\n");
printf("Geben Sie mir bitte zuerst die Laenge in Zentimetern an.\n");
scanf("%f", &length);
printf("Sehr gut, und nun bitte die Breite, ebenfalls in Zentimetern.\n");
scanf("%f", &width);
float area = length*width;
if(area >= 10000)
{
    area /= 10000;
    printf("Der Flaecheninhalt des Rechtecks betraegt: %.2f m^2", area);
}
else
{
    printf("Der Flaecheninhalt des Rechtecks betraegt: %.2f cm^2", area);
}
return 0;
}