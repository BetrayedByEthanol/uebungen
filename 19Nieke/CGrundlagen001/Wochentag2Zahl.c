
#include <stdio.h>

int main()
{
    char string[50];
    int run =1;
    puts("Wandelt einen Wochentagnamen in einen Zahlen Wert um");
    puts("Bitte Wochentag eingeben (Montag/Dienstag/Mittwoch/Donnerstag/Freitag/Samstag/Sonntag");
    gets(string);
    while(run==1)
    {
        if(string[0]=='M' && string[1]=='o' && string[2]=='n'&& string[3]=='t'&& string[4]=='a'&& string[5]=='g' && string[6]=='\0') puts("2");
        if(string[0]=='D' && string[1]=='i' && string[2]=='e'&& string[3]=='n'&& string[4]=='s'&& string[5]=='t' && string[6]=='a' && string[7]=='g'  && string[8]=='\0') puts("3");
        if(string[0]=='M' && string[1]=='i' && string[2]=='t'&& string[3]=='t'&& string[4]=='w'&& string[5]=='o' && string[6]=='c' && string[7]=='h'  && string[8]=='\0') puts("4");
        if(string[0]=='D' && string[1]=='o' && string[2]=='n'&& string[3]=='n'&& string[4]=='e'&& string[5]=='r' && string[6]=='s' && string[7]=='t'  && string[8]=='a'  && string[9]=='g' && string[10]=='\0') puts("5");
        if(string[0]=='F' && string[1]=='r' && string[2]=='e'&& string[3]=='i'&& string[4]=='t'&& string[5]=='a' && string[6]=='g' && string[7]=='\0') puts("6");
        if(string[0]=='S' && string[1]=='a' && string[2]=='m'&& string[3]=='s'&& string[4]=='t'&& string[5]=='a' && string[6]=='g' && string[7]=='\0') puts("7");
        if(string[0]=='S' && string[1]=='o' && string[2]=='n'&& string[3]=='n'&& string[4]=='t'&& string[5]=='a' && string[6]=='g' && string[7]=='\0') puts("1");
        gets(string);
    }
    gets(string);
    return 0;
}