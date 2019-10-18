
#include <stdio.h>
#include <stdlib.h>

int min(int x, int y)
{
    return (x < y) ? x : y;
}

int calculation(double h, double m)
{
    if (h == 12 || h == 24)
        h = 0;
    if (m == 60)
        m = 0;

    int hour_angle = 0.5 * (h * 60 + m);
    int minute_angle = 6 * m;

    int angle = abs(hour_angle - minute_angle);

    angle = min(360 - angle, angle);
    if (angle <= 0)
        angle *= (-1);

    return angle;
}

int h, m;

int main()
{
    printf("Please enter Time. \n");
    scanf("%d:%d", &h, &m);

    if (h < 0 || m < 0 || h > 24 || m > 60)
    {
        printf("Wrong input");
    }
    else
    {
        printf("The angle of the hands is %d degrees\n", calculation(h, m));
    }

    return 0;
}
