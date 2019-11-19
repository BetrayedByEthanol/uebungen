#include <stdio.h>


int main(void){
    int stundenzeiger, minutenzeiger, stdwinkel, mntwinkel, winkel, stundenfortschritt, angefstd;
    //float stundenfortschritt; (Alternativversuch)


    printf("Bitte geben Sie die Position (Uhrzeit) des Stundenzeigers an.\n");
    scanf("%d", &stundenzeiger);
    //printf("%d", stundenzeiger); Kontrolle
    if(stundenzeiger > 12){
        stundenzeiger = stundenzeiger - 12;
        //printf("%d", stundenzeiger); Kontrolle
    }
    //printf("%d", stdwinkel); Kontrolle


    printf("Bitte geben Sie die Position (Uhrzeit) des Minutenzeigers an.\n");
    scanf("%d", &minutenzeiger);
    mntwinkel = minutenzeiger * 6;

    stundenfortschritt = minutenzeiger * 100 / 60;
    angefstd = 30 * stundenfortschritt / 100;
    stdwinkel = stundenzeiger * 5 * 6 + angefstd;


    //Kontrolle
    //printf("stdwinkel: %d\n", stdwinkel);
    //printf("angefstd: %d\n", angefstd);    
    //printf("Stundenfortschritt: %d\n", stundenfortschritt);



    if(stdwinkel < mntwinkel){
        winkel = mntwinkel-stdwinkel;
        printf("Der Winkel zwischen Minuten- und Stundenzeiger beträgt %d Grad.\n", winkel);
        return(winkel);
    }else if(stdwinkel > mntwinkel){
        winkel = stdwinkel - mntwinkel;
        printf("Der Winkel zwischen Minuten- und Stundenzeiger beträgt %d Grad.\n", winkel);
        return(winkel);
    }else if(stdwinkel == mntwinkel){
        winkel = mntwinkel - stdwinkel;
        printf("Der Winkel zwischen Minuten- und Stundenzeiger beträgt %d Grad.\n", winkel);
    }


}