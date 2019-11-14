#include<stdio.h>
#include<string.h>

int main(){
    char xson[] = "Sonntag\n";
    char xmon[] = "Montag\n";
    char xdie[] = "Dienstag\n";
    char xmit[] = "Mittwoch\n";
    char xdon[] = "Donnerstag\n";
    char xfre[] = "Freitag\n";
    char xsam[] = "Samstag\n";

    char inp[15]= "";


    int son = 1;
    int mon = 2;
    int die = 3;
    int mit = 4; 
    int don = 5; 
    int fre = 6;
    int sam = 7; 

 
    printf("%s", "Gibt Wochentag als Zahl aus. Enter zum Beginnen");

    while(getchar() != '\n');


    fgets(inp, 15, stdin);
  
    


   if(strcmp(inp, xson) == 0){
       printf("%d", son);
   }
   else if(strcmp(inp, xmon) == 0){
       printf("%d", mon);
   }
     else if(strcmp(inp, xdie) == 0){
       printf("%d", die);
   }
     else if(strcmp(inp, xmit) == 0){
       printf("%d", mit);
   }
     else if(strcmp(inp, xdon) == 0){
       printf("%d", don);
   }
     else if(strcmp(inp, xfre) == 0){
       printf("%d", fre);
   }
     else if(strcmp(inp, xsam) == 0){
       printf("%d", sam);
   }


  

            return 0;


    

}
