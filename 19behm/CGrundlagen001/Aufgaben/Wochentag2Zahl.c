
#include <stdio.h>
#include <string.h>

int main() {
    char wochentag[11];
    char montag[7] ="Montag";
    char dienstag[9] ="Dienstag";
    char mittwoch[9] = "Mittwoch";
    char donnerstag[11] = "Donnerstag";
    char freitag[8] = "Freitag";
    char samstag[8] = "Samstag";
    char sonntag[8] = "Sonntag";
    printf("Bitte Wochentag eingeben:");
    scanf("%10s", &wochentag);
    if(strcmp(wochentag, montag) == 0){
        printf("2");
    }   else if(strcmp(wochentag, dienstag) == 0){
        printf("3");
    }   else if(strcmp(wochentag, mittwoch) == 0){
        printf("4");
    }   else if(strcmp(wochentag, donnerstag) == 0){
        printf("5");
    }   else if(strcmp(wochentag, freitag) == 0){
        printf("6");
    }   else if(strcmp(wochentag, samstag) == 0){
        printf("7");
    }   else if(strcmp(wochentag, sonntag) == 0){
        printf("1");
    }   else {
        printf("Unbekannte Eingabe.");
    }
    return(0);

    

}

