#include<stdio.h>
#include<stdlib.h>

void simulation(int timeup, int timedown, int sunsensitivity, int senact, int sendeact)
{
    int timer = 0, senspan, r, getlvl, sensor;
    int lvl;
    srand(time(0));

    senspan = 100 / sunsensitivity;

    for(timer = 0; timer <= 24; timer++)
    {
        r = rand() % 100;
        if(timer == timeup)
        {
            lvl = sunsensitivity;
        }
        if(timer == timedown)
        {
            lvl = 0;
        }
        if(timer == senact)
        {
            sensor = 1;
        }
        if(timer == sendeact)
        {
            sensor = 0;
        }
        if(sensor == 1)
        {
            getlvl = r / senspan;
            lvl = getlvl;
        }

        printf("Zeit: %d:00 Uhr", timer);
        if(sensor == 1)
        {
            printf(", Sonnensensor: aktiviert, Einstrahlung: %d Prozent", r);
        }
        printf(", Jalousie: Level %d\n", lvl);
    }

}

void main(void)
{
    int timeup, timedown, sunsensitivity, senact, sendeact;
    int boolean = 0, check = 1, start = 0;
    //simulation(8, 22, 5, 10, 20);
    while(1)
    {
        if(boolean == 1)
        {
            printf("Werte aendern? Y = 1 / N = 0\n");
            scanf("%d", &check);
        }
        if(check == 1)
        {
            printf("\nBitte geben Sie die Stundenzahl an, zu der ihre Jalousie hochfahren soll.\n");
            scanf("%d", &timeup);
            printf("\nBitte geben Sie die Stundenzahl an, zu der ihre Jalousie hinunterfahren soll.\n");
            scanf("%d", &timedown);
            printf("\nBitte geben Sie die Sensitivitaet an, mit der ihr Sonnensensor bei Aktivierung agieren soll.\n");
            scanf("%d", &sunsensitivity);
            printf("\nBitte geben Sie die Stundenzahl an, zu der ihr Sensor aktiviert werden soll.\n");
            scanf("%d", &senact);
            printf("\nBitte geben Sie die Stundenzahl an, zu der ihr Sensor deaktiviert werden soll.\n");
            scanf("%d", &sendeact);
            check = 0;
        }

        printf("Simulation starten? Y = 1 / N = 0\n");
        scanf("%d", &start);

        if(start == 1)
        {
            simulation(timeup, timedown, sunsensitivity, senact, sendeact);
        }

        boolean = 1;

    }
}


