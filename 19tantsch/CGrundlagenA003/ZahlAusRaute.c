#include<stdio.h>

char ja[] = "#";
char nein[] = "";
char forderung[50];                                                                         // Es können maximal 50 Zahlen auf einmal eingeben und gespeichert werden.
//int forderung2;
//int ende;
int a;                                                                                                       // a überprüft in der nachfolgenden Funktion, welche Zahl gedruckt werden soll(1-9)
int print(char a);                                                                                           //funktion print() mit dem Output der Variable a.
int null();
int eins();
int zwei();
int drei();
int vier();
int fuenf();
int sechs();
int sieben();
int acht();
int neun();



int main(){


printf("Geben Sie vier Zahlen(1-9) ein.");
scanf("%s", &forderung);                          //&1d scant immer nur eine Zahl. Speichert nacheinander 1-9 ins Array.

int i;
for(i=0; i<=49;i++){                                    // Schleife um jede einzelne Ziffer nacheinander auszudrücken, wert erhöht sich um 1 bis maximal 49.
print(forderung[i]);

}
}

int print(char a){                                               //print() Funktion , überprüft das übergebene zeichen aus der ASCII Tabelle und gibt dann die entpsrechende Grafik aus
    
if(a == 48){

null(); 
}

else if(a == 49){                                                              //alle Ziffern besitzen eine eigene Darstellung und werden durch die "zahl()" Funktion repräsentiert.
eins();

}

else if(a == 50){
zwei();


}

else if(a == 51){
drei();


}

else if(a == 52){

vier();

}

else if(a == 53){

fuenf();

}

else if(a == 54){
 sechs();


}

else if(a == 55){
sieben();


}

else if(a == 56){
    acht();

}

else if(a == 57){
neun();

}
}





int null(){

    

printf(" %s   %s   %s   %s   %s\n", nein, ja, ja, ja, nein);
printf("  %s   %s   %s   %s   %s\n", ja , nein , nein, nein, ja);
printf("  %s   %s   %s   %s   %s\n", ja , nein , nein, nein, ja);
printf("  %s   %s   %s   %s   %s\n", ja , nein , nein, nein, ja);                           //0 wird gedruckt.
printf("  %s   %s   %s   %s   %s\n", ja , nein , nein, nein, ja);
printf("  %s   %s   %s   %s   %s\n", ja , nein , nein, nein, ja);
printf(" %s   %s   %s   %s   %s\n\n", nein, ja, ja, ja, nein);
    
return 0;

}

int eins(){
printf("  %s   %s   %s   %s   %s\n", nein , nein, ja, nein, nein);
printf(" %s   %s   %s   %s   %s\n", nein, ja, ja, nein, nein);
printf("  %s   %s   %s   %s   %s\n", nein, nein, ja, nein, nein);
printf("  %s   %s   %s   %s   %s\n", nein, nein, ja, nein, nein);                           //1 wird gedruckt.
printf("  %s   %s   %s   %s   %s\n", nein, nein, ja, nein, nein);
printf("  %s   %s   %s   %s   %s\n", nein, nein, ja, nein, nein);
printf(" %s   %s   %s   %s   %s\n\n", nein, ja, ja, ja, nein);

return 0;
}

int zwei(){
printf(" %s   %s   %s   %s   %s\n", nein, ja, ja, ja, nein);
printf("  %s   %s   %s   %s  %s\n", ja , nein , nein, nein, ja);
printf("  %s   %s   %s   %s  %s\n", ja , nein , nein, nein, ja);                           //2 wird gedruckt.
printf("  %s   %s   %s   %s  %s\n", nein, nein, nein, ja, nein);
printf("  %s   %s   %s  %s   %s\n", nein, nein, ja, nein, nein);
printf("  %s   %s  %s   %s   %s\n", nein, ja, nein, nein, nein);
printf(" %s  %s  %s  %s  %s\n\n", ja, ja, ja, ja, ja);

return 0;
}

int drei(){
    printf(" %s   %s   %s   %s   %s\n", nein, ja, ja, ja, nein);
printf("  %s   %s   %s   %s  %s\n", ja , nein , nein, nein, ja);
printf("  %s   %s   %s   %s  %s\n", nein , nein , nein, nein, ja);
printf("  %s   %s   %s  %s %s\n", nein , ja , ja, ja, nein);                            //3 wird gedruckt.
printf("  %s   %s   %s   %s  %s\n", nein, nein , nein, nein, ja);
printf("  %s   %s   %s   %s  %s\n", ja , nein , nein, nein, ja);
printf("  %s   %s   %s   %s  %s\n\n", nein, ja , ja, ja, nein);

return 0;
}

int vier(){
printf("  %s   %s   %s   %s  %s\n", nein, nein , nein, ja, nein);
printf("  %s   %s   %s   %s  %s\n", nein, nein , ja, ja, nein);
printf("  %s   %s   %s   %s  %s\n", nein, ja , nein, ja, nein);
printf("  %s   %s   %s   %s  %s\n", ja, nein , nein, ja, nein);                           //4 wird gedruckt.
printf("  %s   %s   %s  %s %s\n", ja, ja , ja, ja, ja);
printf("  %s   %s   %s   %s  %s\n", nein, nein , nein, ja, nein);
printf("  %s   %s   %s   %s  %s\n\n", nein, nein , nein, ja, nein);

return 0;
}

int fuenf(){
    printf("  %s %s  %s  %s  %s\n", ja, ja, ja, ja, ja);
printf("  %s   %s   %s   %s  %s\n", ja, nein , nein, nein, nein);
printf("  %s   %s   %s   %s  %s\n", ja, nein , nein, nein, nein);
printf("  %s   %s  %s  %s  %s\n", ja, ja, ja, ja, nein);                           //5 wird gedruckt.
printf("  %s   %s   %s   %s  %s\n", nein, nein, nein, nein, ja);
printf("  %s   %s   %s   %s  %s\n", ja, nein, nein, nein, ja);
printf("  %s   %s   %s   %s  %s\n\n", nein, ja, ja, ja, nein);

return 0;
}

int sechs(){
   printf(" %s   %s   %s   %s   %s\n", nein, ja, ja, ja, nein);
printf("  %s   %s   %s   %s   %s\n", ja , nein , nein, nein, ja);
printf("  %s   %s   %s   %s   %s\n", ja , nein , nein, nein, nein);
printf("  %s   %s   %s   %s   %s\n", ja , ja , ja, ja, nein);                           //6 wird gedruckt.
printf("  %s   %s   %s   %s   %s\n", ja , nein , nein, nein, ja);
printf("  %s   %s   %s   %s   %s\n", ja , nein , nein, nein, ja);
printf(" %s   %s   %s   %s   %s\n\n", nein, ja, ja, ja, nein);

return 0;
}

int sieben(){
    printf(" %s  %s  %s  %s  %s\n", ja, ja, ja, ja, ja);
printf("  %s   %s   %s   %s  %s\n", nein, nein , nein, nein, ja);
printf("  %s   %s   %s   %s  %s\n", nein , nein , nein, nein, ja);
printf("  %s   %s   %s   %s  %s\n", nein, nein, nein, ja, nein);                           //7 wird gedruckt.
printf("  %s   %s   %s  %s   %s\n", nein, nein, ja, nein, nein);
printf("  %s   %s  %s   %s   %s\n", nein, ja, nein, nein, nein);
printf(" %s  %s  %s  %s  %s\n\n", ja, nein, nein, nein, nein);

return 0;
}

int acht(){
    printf(" %s   %s   %s   %s   %s\n", nein, ja, ja, ja, nein);
printf("  %s   %s   %s   %s   %s\n", ja , nein , nein, nein, ja);
printf("  %s   %s   %s   %s   %s\n", ja , nein , nein, nein, ja);
printf("  %s   %s   %s   %s   %s\n", nein, ja , ja, ja, nein);                           //8 wird gedruckt.
printf("  %s   %s   %s   %s   %s\n", ja , nein , nein, nein, ja);
printf("  %s   %s   %s   %s   %s\n", ja , nein , nein, nein, ja);
printf(" %s   %s   %s   %s   %s\n\n", nein, ja, ja, ja, nein);

return 0;
}
int neun(){
    printf(" %s   %s   %s   %s   %s\n", nein, ja, ja, ja, nein);
printf("  %s   %s   %s   %s   %s\n", ja , nein , nein, nein, ja);
printf("  %s   %s   %s   %s   %s\n", ja , nein , nein, nein, ja);
printf("  %s   %s   %s   %s   %s\n", nein, ja , ja, ja, nein);                           //9 wird gedruckt.
printf("  %s   %s   %s   %s   %s\n", nein , nein , nein, nein, ja);
printf("  %s   %s   %s   %s   %s\n", ja , nein , nein, nein, ja);
printf(" %s   %s   %s   %s   %s\n\n", nein, ja, ja, ja, nein);

return 0;
}