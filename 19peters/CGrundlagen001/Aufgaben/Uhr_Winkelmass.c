
#include <stdio.h>

int main() {
    float h = 0, min = 0, f = 0;
    printf("Wie spät ist es?\nStunde: ");
    scanf("%2f", &h);
    printf("Minute: ");
    scanf("%2f", &min);
    while (h >= 12) h = h - 12;
    min = min * 6;
    h = (h * 30) + (min / 12);
    if ((min - h) < 0) {
        if (-(min-h) > 180) f = 360+(min-h);
        else f = -(min-h);
    }
    else {
        if ((min - h) > 180) f = 360 - (min - h);
        else f = min - h;
    }
    printf("%f°\n", f);
    printf("Press ENTER key to Continue\n");
    //system("pause");
    return 0;
}