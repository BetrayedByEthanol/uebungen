/*
 Dennis Nieke
 14.11.2019
 CGrundlagenA004
 Programm zur Steuerung der Jalousie
 */
#include <stdio.h>
#include <unistd.h>

//converts time values
int parseTime(int hours, int minutes)
{
    return hours*60+minutes;
}

// Returns 93 should get the Sensor Valeu
int getSensorValue()
{
    return 93;
}

//Initial System Setup
void setInitialState(int * time, int * protectionHeight, int * nightTime, int * dayTime, int * protectionValue)
{
    int hours;
    int minutes;

    puts("Bitte aktuelle Uhrzeit eingeben:");
    scanf("%2d:%2d", &hours, &minutes);
    *time = parseTime(hours, minutes);
    puts("Bitte Sonnensenor kalibrieren ( Simulation bitte Lichtstaerke Wert einben (vergleichs Wert normales Tageslicht 93)");
    scanf("%d",protectionValue);
    puts("Bitte die Hoehe (0 herunter gefahren -100 oben ) bei Sonnenschutz einstellen:");
    scanf("%d", protectionHeight);
    puts("Bitte Startzeit fuer Nachtmodus eingeben: ");
    scanf("%2d:%2d", &hours, &minutes);
    *nightTime = parseTime(hours,minutes);
    puts("Bitte Endzeit fuer Nachtmodus eingeben: ");
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

    setInitialState(&time, &protectionHeight, &nightTime, &dayTime, &protectionBrightness);
    puts("Die Jalosie ist oben");
    //accelerated Simulation Timing 1 sec equals 1 min 
    while (1)
    {    
        if(time == nightTime) 
        {
            nightMode = 1;
            actualHeight = setjalousieHeight(0);
        }
        else if(time == dayTime) nightMode = 0;

        if(nightMode == 0) 
        {
            brightness = getSensorValue();
            if(brightness == protectionBrightness && actualHeight != protectionHeight)
            {
                actualHeight = setjalousieHeight(protectionHeight);
            }
            else if(actualHeight != 100)
            {
                actualHeight = setjalousieHeight(100);
            }
        } 
        Sleep(1000);
        printf("%2d:%2d\n",time/60,time%60);
        
        time++;
        if (time == 1440) time -= 1440;
        
    }
    
    return 1;
}