#include <stdio.h>
#include <stdlib.h>

int uhrKonverter(int z1, int z2);

int main() {
    char modi = 'd';
    int Max_hoehe = 600;
    int Min_hoehe = 0;
    int zeit = 0, tagNacht = 0, simLaenge = 0, Bhoehe = 0, Bhoehe_Vaw = 0, Aktuelle_hoehe = 0, Tageslicht = 0, Menu_aktiv = 0;
    srand(94);
    while(modi != 115) {
        printf("Simulationsmenu:\n(A)ktiviere Simulation\n(W)aehle Hoeheneinstellung\n(S)chliesse Programm\n");
        scanf("%c", &modi);
        fflush(stdin);
        if(modi == 'a') {
            printf("Wie lange soll die Simulation dauern? (Zeit in min.)\n");
            scanf("%d", &simLaenge);
            fflush(stdin);
            while(simLaenge > 0) {
                zeit = (zeit + 1) % 1440;
                if(zeit < 720) {
                    tagNacht = 0;
                } else {
                    tagNacht = 1;
                }
                if(tagNacht == 0) {
                    Tageslicht = rand() % 2;
                    while(Aktuelle_hoehe < Bhoehe) {
                        Aktuelle_hoehe = ((Aktuelle_hoehe / 10) * 10) + 10;
                    }
                    if(Tageslicht == 1) {
                        while(Aktuelle_hoehe > Bhoehe) {
                            Aktuelle_hoehe = ((Aktuelle_hoehe / 10) * 10) - 10;
                        }
                    } else {
                        while(Aktuelle_hoehe < Max_hoehe) {
                            Aktuelle_hoehe = ((Aktuelle_hoehe / 10) * 10) + 10;
                        }
                    }
                } else {
                    while(Aktuelle_hoehe > Min_hoehe) {
                        Aktuelle_hoehe = ((Aktuelle_hoehe / 10) * 10) - 10;
                    }
                }
                simLaenge --;
                printf("Bericht: Zeit(%d:%d) Licht(%d) Nacht(%d) Hoehe(%d)\n", (((zeit / 60) + 6) % 24), scanf((zeit / 10) % 6), (zeit % 10), Tageslicht, tagNacht), Aktuelle_hoehe;
            }
            printf("\nSimulation Ende\n\n");
        }
        if(modi == 'w') {
            Menu_aktiv = 1;
            while(Menu_aktiv == 1) {
                printf("Gewuenschte Hoehe eingeben!\n");
                scanf("%d", &Bhoehe_Vaw);
                fflush(stdin);
                if((Bhoehe_Vaw < Max_hoehe) && (Bhoehe_Vaw > Min_hoehe)) {
                    Bhoehe = Bhoehe_Vaw;
                    Menu_aktiv = 0;
                } else {
                    printf("Fehler! Eingabe ungueltig!");
                }
            }
        }
        if(modi == 'u') {
            printf("Start-Uhrzeit der Simulation:\n(%d:%d%d)", (((zeit / 60) + 6) % 24), ((zeit / 10) % 6)), (zeit % 10);
            printf("Neue Start-Uhrzeit eingeben!(hh:mm)");
            int zahl1, zahl2;
            scanf("%d:%d", &zahl1, &zahl2);
            fflush(stdin);
            zeit = uhrKonverter(zahl1, zahl2);
        }
    }
    
}

int uhrKonverter(int z1, int z2) {
    int zeitzeiger;
    zeitzeiger = (z1 - 6) * 60 + z2;
    return zeitzeiger;
}