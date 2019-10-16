
#include <stdio.h>
#include <string.h>

int main(){
    char wochentag[11];
    puts("Fügen Sie einen Wochentag ein: ");
    scanf("%10s", wochentag);
    

    if (strcmp (wochentag,"sonntag")==0){
       printf("1");
    }else if (strcmp (wochentag,"montag")==0){
        printf("2");
    }else if (strcmp (wochentag,"dienstag")==0){
        printf("3");
    }else if (strcmp (wochentag,"mittwoch")==0){
        printf("4");
    }else if (strcmp (wochentag,"donnerstag")==0){
        printf("5");
    }else if (strcmp (wochentag,"freitag")==0){
       printf("6");
    }else if (strcmp (wochentag,"samstag")==0){
        printf("7");
    }else if (strcmp (wochentag,"Sonntag")==0){
        printf("1");
    }else if (strcmp (wochentag,"Montag")==0){
        printf("2");
    }else if (strcmp (wochentag,"Dienstag")==0){
       printf("3");
    }else if (strcmp (wochentag,"Mittwoch")==0){
        printf("4");
    }else if (strcmp (wochentag,"Donnerstag")==0){
        printf("5");
    }else if (strcmp (wochentag,"Freitag")==0){
        printf("6");
    }else if (strcmp (wochentag,"Samstag")==0){
        printf("7");
    }else{
       printf("Ungueltige Eingabe");
    }
    
    return 0;
}
