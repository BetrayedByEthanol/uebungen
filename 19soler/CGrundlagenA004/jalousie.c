//including libaries
#include<stdio.h>
#include<unistd.h>

//declare global variables
int heightValue, defaultHeightValue, position;
int hour, hourDay, hourNight;
int sun;
int graphicRep;
void menu();
void defaultHeight();
void dayNight();
void setHeight();
void sunValue();
void jalousieGraphic();

//main programm starts here
int main()
{
    menu();
}

//function for the menu 
void menu()
{
    //declare a local variable for the menu choice
    int menuValue;
    graphicRep = 0;
    printf("Set default Height [1]\nSet Height [2]\nSet Day and Night [3]\nReset to Automatic [4]\nSimulate Time [5]\nPower Off[6]\n");
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
        printf("Reset to automatic\n");
        sun = 0;
        menu();
        break;
    case 5:
        printf("Input a time to simulate the program because C is fucking retarded:\n");
        scanf("%d", &hour);
        sunValue();
        break;
    case 6:
        break;
    default:
        printf("Please select a valid menu option!");
        menu();
        break;
    }
}

//function to set the custom height 
void setHeight()
{
    printf("You have chosen to input a new value for the height. \nPlease input your new desired height:");
    scanf("%d", &heightValue);
    graphicRep = 0;
    position = heightValue;
    sun = 2;
    jalousieGraphic();
}

//function to check if the sun is shining
void sunValue()
{
    if (hour >= hourDay || hour <= hourNight)
    {
        sun = 1;
    }
    if (hour >= hourNight || hour <= hourDay)
    {
        sun = 0;
    }
    graphicRep = 0;
    jalousieGraphic();
}

//function for the jalousie graphic
void jalousieGraphic()
{
    //Default height for day
    int n = 0;
    if (graphicRep == 0 && sun == 1 && hour >= hourDay && hour <= hourNight)
    {
        for (int i = 0; i < defaultHeightValue; i++)
        {
            n++;
            printf("%d\t####################\n", n);
        }
        for (int j = defaultHeightValue; j < 24; j++)
        {
            n++;
            printf("%d\t00000000000000000000\n", n);
        }
        graphicRep++;
    }
    //Completely closed for Night
    if (graphicRep == 0 && sun == 0 && hour >= hourNight || hour < hourDay)
    {
        for (int j = 0; j < 24; j++)
        {
            n++;
            printf("%d\t####################\n", n);
        }
        graphicRep++;
    }

    //User defined height
    if (graphicRep == 0 && sun == 2)
    {
        for (int i = 0; i < position; i++)
        {
            n++;
            printf("%d\t####################\n", n);
        }
        for (int j = position; j < 24; j++)
        {
            n++;
            printf("%d\t00000000000000000000\n", n);
        }
        graphicRep++;
    }
    menu();
}

//function to choose the desirred day and night time
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

//function to choose your default jalousie height
void defaultHeight()
{
    printf("You have chosen the option to allow you to set your default height.\n");
    printf("Please input your preferred default height[0-24]:\n");
    scanf("%d", &defaultHeightValue);
    printf("Your default height is now set to %d\n", defaultHeightValue);
    graphicRep = 0;
    sunValue();
}