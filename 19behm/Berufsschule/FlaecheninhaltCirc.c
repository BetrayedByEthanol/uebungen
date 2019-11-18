
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>

int main()
{
    float area, radius;
    printf("Um den Flaecheninhalt eines Kreises zu berechnen benoetige ich von Ihnen den Radius des Kreises.\n");
    printf("Bitte geben Sie den Radius des Kreises in Zentimetern an.\n");
    scanf("%f", &radius);
    area = M_PI*radius*radius;
    if(area>=10000)
    {
        area /= 10000;
        printf("Der Flaecheninhalt des Kreises betraegt %.2f m^2.", area);
    }
    else
    {
        printf("Der Flaecheninhalt des Kreises betraegt %.2f cm^2", area);
    }
    return 0;    
}