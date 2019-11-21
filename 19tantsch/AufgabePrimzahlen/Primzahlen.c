#include<stdio.h>
#include<math.h>



int rahmen = 0;
int i = 0;
float wurzel;

int main(){
    
    printf("Maximale Groesse der Primzahlen Eingeben: ");
    scanf("%d", &rahmen);

    for(i=0; i<=rahmen; i++){
        wurzel = sqrt(i);
       
        printf("%d:%f\n", i, wurzel);
       

    }
    return 0;
}