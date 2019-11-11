
#include <stdio.h>

int main()
{
float length, width;
printf("Um den Flächeninhalt zu berechnen benötige ich von Ihnen zwei Werte. Länge und Breite.\n");
printf("Geben Sie mir bitte zuerst die Länge in Zentimetern an.\n");
scanf("%f", &length);
printf("Sehr gut, und nun bitte die Breite, ebenfalls in Zentimetern.\n");
scanf("%f", &width);
float area = length*width;
if(area >= 1000)
{
    area /= 1000;
    printf("Der Flächeninhalt des Rechtecks beträgt: %.2f m²", area);
}
else
{
    printf("Der Flächeninhalt des Rechtecks beträgt: %.2f cm²", area);
}
return 0;
}