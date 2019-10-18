#include <stdio.h>
#include <string.h>
int main() {

    char Wochentag[20];
    printf("Enter Weekday: ");
    scanf("%s", &Wochentag);

    if (strcmp (Wochentag, "Sonntag")==0){
        printf("1");
    }
    else if (strcmp (Wochentag, "Montag")==0){
        printf("2");
    }
    else if (strcmp (Wochentag, "Dienstag")==0){
        printf("3");
    }
    else if (strcmp (Wochentag, "Mittwoch")==0){
        printf("4");
    }
    else if (strcmp (Wochentag, "Donnerstag")==0){
        printf("5");
    }
    else if (strcmp (Wochentag, "Freitag")==0){
        printf("6");
    }
    else if (strcmp (Wochentag, "Samstag")==0){
        printf("7");
    }
    return 0;
}