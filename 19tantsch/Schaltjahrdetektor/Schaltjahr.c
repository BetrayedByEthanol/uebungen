#include<stdio.h>

int jahr;
int main(){
    printf("Fragen Sie den Computer ob Ihr Jahr ein Schaltjahr ist.\nEingabe:"); //Interaktion mit dem User
    scanf("%d", &jahr);         //Eingabe 

    if(jahr % 4 == 0 && jahr % 100 != 0 && jahr % 400 != 0){
        printf("Das Jahr %d ist ein Schaltjahr", jahr);         // Bedingungen der Schaltjahre
}
    else if(jahr % 100 == 0 && jahr % 400 != 0){            //Bediungungen der nicht-Schaltjahre
        printf("Das Jahr %d ist kein Schaltjahr", jahr);
}
    else if(jahr % 400 == 0){             //Bedingung ausnahmefälle der Schaltjahre
        printf("Das Jahr %d ist ein Schaltjahr", jahr);
    }
        return 0;
}