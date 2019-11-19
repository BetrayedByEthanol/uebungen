#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void) {
    char eingabetag[11];
    //char vgltag[11];

    //int tagyn;

    /*char  Sonntag = 'Sonntag';
    char  Montag = 'Montag';
    char  Dienstag = 'Dienstag';
    char  Mittwoch = 'Mittwoch';
    char  Donnerstag = 'Donnerstag';
    char  Freitag = "Freitag";
    char  Samstag = "Samstag";*/

    printf("Bitte geben Sie den aktuellen Wochentag ausgeschrieben an.\n");
    // fgets(eingabetag, 11, stdin);
    scanf("%10s", eingabetag);
    
    //printf("%s\n", eingabetag);

    //strcpy(vgltag, "Sonntag");
    //tagyn = strcmp(eingabetag, vgltag);

    if (strcmp(eingabetag,  "Sonntag") == 0){
        printf("Wochentag: %s, Nummer: 1\n", eingabetag);
        return(1);
    }else 
        //strcpy(vgltag, "Montag");
        //printf("%s\n", vgltag);
        //tagyn = strcmp(eingabetag, vgltag);
        //printf("tagyn: %d\n", tagyn);
        if (strcmp(eingabetag,  "Montag") == 0){ 
            printf("Wochentag: %s, Nummer: 2\n", eingabetag);
            return(2);
            }else if (strcmp(eingabetag,  "Dienstag") == 0){
                printf("Wochentag: %s, Nummer: 3\n", eingabetag);
                return(3);
                } else if (strcmp(eingabetag,  "Mittwoch") == 0){
                    printf("Wochentag: %s, Nummer: 4\n", eingabetag);
                    return(4);
                    }else if (strcmp(eingabetag,  "Donnerstag") == 0){
                        printf("Wochentag: %s, Nummer: 5\n", eingabetag);
                        return(5);
                        }else if (strcmp(eingabetag,  "Freitag") == 0){
                            printf("Wochentag: %s, Nummer: 6\n", eingabetag);
                            return(6);
                            }else if (strcmp(eingabetag,  "Samstag") == 0){
                                printf("Wochentag: %s, Nummer: 7\n", eingabetag);
                                return(7);
                                }else {
                                    printf("Hascht dich vertippt du Bloedi");
                                    return(0);
                                }
}
           
                
    