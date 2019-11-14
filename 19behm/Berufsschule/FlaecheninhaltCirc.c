
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>

int main()
{
    float area, radius;
    printf("Um den Flächeninhalt eines Kreises zu berechnen benötige ich von Ihnen den Radius des Kreises.\n");
    printf("Bitte geben Sie den Radius des Kreises in Zentimetern an.\n");
    scanf("%f", &radius);
    area = M_PI*radius*radius;
    if(area>=1000)
    {
        area /= 1000;
        printf("Der Flächeninhalt des Kreises beträgt %.2f m².", area);
    }
    else
    {
        printf("Der Flächeninhalt des Kreises beträgt %.2f cm²", area);
    }
    return 0;    
}