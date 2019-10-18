#include <stdio.h>

int minute;
int hour;
int hangle;
int mangle;
int bangle;

int main()
{
    printf("Enter Time: ");
    scanf("%2d:%2d", &hour, &minute);

    mangle=minute*6;
    hangle=hour*60+minute;

    if(hour < 24 && minute < 60){
        if(hangle > 720);
        hangle=hangle-720;
        hangle=hangle/2;

    if (mangle>=hangle){
        bangle=mangle-hangle;
    }
    if(hangle>=mangle){
        bangle=hangle-mangle;
    }
    if(bangle>180){
        printf("%d = Outer angle\n", bangle);
        bangle=360-bangle;
        printf("%d = Inner angle", bangle);
    } else if(bangle==0){
        printf("Angle = 0");
    } else {
        printf("%d = Inner angle\n", bangle);
        bangle=360-bangle;
        printf("%d = Outer angle", bangle);
    }
    }
    else {
        printf("Entered wrongly");
    }

}
