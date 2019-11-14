/*Der Entwicklungsleiter der Jalousie-City GmbH hat eine neue Steuerung für die vollautomatischen 
Sonnenschutzjalousien entworfen. Diese sollen eine automatisch einstellbare Höhe haben, 
die der Benutzer voreinstellen kann (Sonnenschutz). Registriert der Sonnensensor also eine hohe Sonneneinstrahlung
fährt die Jalousie bis zu der voreingestellten Höhe herunter. Zusätzlich ist ein Tag – Nacht – Modus integriert, 
das die Jalousien bei einer voreingestellten Zeit 
vollends herunterfahren und wieder hochfahren, wenn die morgendlich voreingestellte Zeit erreicht wurde.*/

//fixed height user set
//signal controlled
//day night circle

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

int height, check = 0, userset = 50;
int evening = 16;
int morning = 13;
char input;
int rand(void);

int main()
{

    do
    {

        input = ' ';

        printf("Was moechten Sie tun? 'o'ptionen, 'a'usgabe, 'q'uit\n");

        scanf(" %c", &input);

        if (input == 'o')
        {
            printf("Welche Option moechten sie aendern?\n Gewuenschte 'h'oehe, 'z'eit, z'u'rueck, 's'onne\n");
            scanf(" %c", &input);
            if (input == 'h')
            {
                printf("Bitte geben Sie die neue gewuenschte Hoehe in %% ein.\n");
                scanf("%d", &userset);
            }
            else if (input == 'z')
            {
                printf("Welche Zeit moechten Sie aendern? 'M'orgen oder A'b'end?\n");
                scanf(" %c", &input);
                if (input == 'm')
                {
                    printf("Geben Sie bitte die neue Uhrzeit fuer morgens ein.\nDerzeit: %d\n", morning);
                    scanf("%d", &morning);
                }
                else if (input == 'b')
                {
                    printf("Geben Sie die neue Uhrzeit fuer Abends ein.\nDerzeit: %d\n", evening);
                    scanf("%d", &evening);
                }
                else
                    break;
            }
            else if (input == 's')
            {
                printf("Geben Sie die Sonneneinstrahlung ein 0-5\n");
                scanf("%d", &check);
            }
            else
                break;
        }
        else if (input == 'a')
            printf("Die Hoehe betraegt: %d%%.", height);
        else
            break;
    } while (input != 'q');

    while (1)
    {
        time_t now;
        struct tm *now_tm;
        int hour,minute;

        now = time(NULL);
        now_tm = localtime(&now);
        hour = now_tm->tm_hour;
        minute = now_tm->tm_min;
        if (now_tm->tm_hour >= evening && now_tm->tm_hour <= morning)
            height = 100;
        else if (check >= 3)
        {
            height = userset;
        }
        else
            height = 0;
        printf("Hoehe: %d\tZeit: %d:%d\tSonne: %d\n", height, now_tm->tm_hour,now_tm->tm_min, check);
        sleep(10);
        srand(time(0));
        check = rand() % (4 - 1 + 1) + 1;
    }
}