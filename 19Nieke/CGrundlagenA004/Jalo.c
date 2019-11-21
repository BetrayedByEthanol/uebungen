/*
 Dennis Nieke
 14.11.2019
 CGrundlagenA004
 Programm zur Steuerung der Jalousie
 */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> 


//converts time values
int parseTime(int hours, int minutes)
{
    return hours*60+minutes;
}

// Returns 93 should get the Sensor Value
int getSensorValue()
{
    
    int random = rand() %  (121) + 80;  
    return random;
}

//Initial System Setup
void setInitialState(int * time, int * protectionHeight, int * nightTime, int * dayTime, int * protectionValue)
{
    int hours;
    int minutes;

    puts("Bitte aktuelle Uhrzeit eingeben: (hh:mm)");
    scanf("%2d:%2d", &hours, &minutes);
    *time = parseTime(hours, minutes);
    puts("Bitte Sonnensenor kalibrieren ( Simulation bitte Lichtstaerke Wert einben (vergleichs Wert normales Tageslicht 93)");
    scanf("%d",protectionValue);
    puts("Bitte die Hoehe (0 (herunter gefahren) - 100 (oben) ) bei Sonnenschutz einstellen:");
    scanf("%d", protectionHeight);
    puts("Bitte Startzeit fuer Nachtmodus eingeben: (hh:mm)");
    scanf("%2d:%2d", &hours, &minutes);
    *nightTime = parseTime(hours,minutes);
    puts("Bitte Endzeit fuer Nachtmodus eingeben: (hh:mm)");
    scanf("%2d:%2d", &hours, &minutes);
    *dayTime= parseTime(hours,minutes);
}

// moves the jalousie with a magical engine
int setjalousieHeight(int newHeight)
{
    printf("Jalousie bewegt sich auf %d %% Hoehe \n", newHeight);
    return newHeight;
}


//Main Function
int main()
{
    //current Minute of the day
    int time = 0;
    //actual Height % (0% down 100% up)
    int actualHeight = 100;
    //height for sun protection
    int protectionHeight = 100;
    //night mode start time
    int nightTime = 0;
    //start of day time
    int dayTime = 600;
    //night mode on
    short nightMode = 0;
    //brightness required for protection
    int protectionBrightness = 0;
    //brightness
    int brightness = 0;
    //generate Random Seed
    srand(200);
    
    //Perform Initial Setup
    setInitialState(&time, &protectionHeight, &nightTime, &dayTime, &protectionBrightness);
    
    //Initial Position for the Jalosie
    if(time > nightTime || time < dayTime) puts("Die Jalosie ist unten");
    else puts("Die Jalosie ist oben");

    //accelerated Simulation Timing 0.5 sec equals 1 min 
    while (1)
    {    
        //Turn on NightMode on or off
        if(time == nightTime) 
        {
            //if nightMode gets turn on, set Jalosie to 0 height
            nightMode = 1;
            if(actualHeight != 0) actualHeight = setjalousieHeight(0);
        }
        else if(time == dayTime) nightMode = 0;

        //If nightMode is off
        if(nightMode == 0) 
        {
            //Check the Sensor
            brightness = getSensorValue();
            if(brightness >= protectionBrightness && actualHeight != protectionHeight)
            {
                actualHeight = setjalousieHeight(protectionHeight);
            }
            else if(actualHeight != 100)
            {
                actualHeight = setjalousieHeight(100);
            }
        } 

        //Simulated increased Speed of RealTime
        Sleep(500);

        //Displayed Message
        if(nightMode == 0) printf("%2d:%2d Sonnenstaerke: %d\n",time/60,time%60,brightness);
        else printf("%2d:%2d \n",time/60,time%60);
        //Go to next min
        time++;

        //Next Day
        if (time == 1440) time -= 1440;
        
    }
    
    return 1;
}