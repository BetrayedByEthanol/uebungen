#include<stdio.h>

int main(){

    int eingabe;

    printf("Dieses Programm erkennt ungerade und gerade Zahlen.\nBitte geben sie eine Zahl ein\n");
    scanf("%d", &eingabe);

    if (eingabe % 2 == 0){
        printf("die Zahl %d ist gerade", eingabe);
    }

    else {                                                                  //wird immer 1 sein und damit ist es eine ungerade Zahl.
        printf("die Zahl %d ist ungerade", eingabe);
    }
    
}
