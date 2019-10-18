
#include <stdio.h>

int main() {
    printf("Wie spät ist es?\n");
    float h = 0;
    float min = 0;
    float f = 0;
    printf("Stunde: ");
    scanf("%2d", &h);
    printf("Minute: ");
    scanf("%2d", &min);
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
    printf("%d\n", f);
    printf("Press ENTER key to Continue\n");
    //system("pause");
    return 0;
}