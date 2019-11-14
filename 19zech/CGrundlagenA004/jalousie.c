#include <stdio.h>
#include <unistd.h>

int heightValue;
int hour;
int hourDay;
int hourNight;
int sun;
int defaultHeightValue;
int position;
int graphicRep;





int main()
{
    menu();
}

void menu()
{
    int menuValue;
    graphicRep = 0;
        printf("Set Default Height [1]\nSet Height [2]\nSet Day and Night [3]\nReset to Automatic [4]\nSimulate Time [5]\nPower Off [6]\n");
        scanf("%d", &menuValue);

            switch (menuValue)
            {
            case 1:
                defaultHeight();
                break;
            case 2:
                setHeight();
                break;
            case 3:
                dayNight();
                break;
            case 4:
                printf("Reset to automatic");
                sun = 0;
                menu();
                break;
            case 5:
                printf("Input a time to simulate the program because C is fucking retarded:\n");
                scanf("%d", &hour);
                jalousieGraphic();
                break;
            case 6:
                break;
            default: 
                printf("Please select a valid menu option: [1], [2], [3], [4] or [5]\n");
                break;
            }
}

void defaultHeight() //Expand
{
    
        printf("You have chosen the option to allow you to set your default height.\n");
        printf("Please input your preferred default height[0-24]:\n");
        scanf("%d", &defaultHeightValue);
        printf("Your default height is now set to %d\n", defaultHeightValue);
        graphicRep = 0;
        sunValue();
}

void dayNight()
{
    printf("Please input your desired Day time:\n");
    scanf("%d", &hourDay);
    printf("Now please input your desired Night time:\n");
    scanf("%d", &hourNight);
    position = 24;
    graphicRep = 0;
    menu();
}

void setHeight()
{
    printf("You have chosen to input a new value for the height.\nPlease input your new desired height:");
    scanf("%d", &heightValue);
    graphicRep = 0;
    position = heightValue;
    sun = 2;
    jalousieGraphic();
}

void sunValue()
{
    if (hour >= hourDay || hour <= hourNight)
    {
        sun = 1;
    }
    if (hour >=hourNight || hour <= hourDay)
    {
        sun = 0;
    }
    graphicRep = 0;
    jalousieGraphic();
}

void jalousieGraphic()
{       //Default height for day
        if (graphicRep == 0 && sun == 1 && hour >= hourDay && hour <= hourNight)
        {
            for (int i=0; i < defaultHeightValue; i++)
            {
            printf("####################\n");
            }
            for (int j = defaultHeightValue; j < 24; j++)
            {
                printf("00000000000000000000\n");
            }
            graphicRep++;
        }
        //Completely closed for Night
        if (graphicRep == 0 && sun == 0 && hour >= hourNight || hour < hourDay)
        {
            for (int j = 0; j < 24; j++)
            {
                printf("####################\n");
            }
            graphicRep++;
        }
        //User defined height
        if (graphicRep == 0 && sun == 2)
        {
            for (int i=0; i < position; i++)
            {
            printf("####################\n");
            }
            for (int j = position; j < 24; j++)
            {
                printf("00000000000000000000\n");
            }
            graphicRep++;
        }
        

        menu();
}