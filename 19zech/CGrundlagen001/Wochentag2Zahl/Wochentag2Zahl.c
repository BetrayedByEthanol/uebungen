#include <stdio.h>
#include <string.h>

int main()
{

     char week[4];

        printf("Enter Day of the Week (Mon-Sun): ");
        scanf("%3s", week);

    if (strcmp(week, "Sun") ==0) {
            printf("1");
        } else if(strcmp(week, "Mon") ==0) {
            printf("2");
        } else if(strcmp(week, "Tue") ==0){
            printf("3");
        } else if(strcmp(week, "Wed") ==0){
            printf("4");
        } else if(strcmp(week, "Thu") ==0){
            printf("5");
        } else if(strcmp(week, "Fri") ==0){
            printf("6");
        } else if(strcmp(week, "Sat") ==0){
            printf("7");
        } else {
            printf("Day invalid, please enter Sun/Mon/Tue/Wed/Thu/Fri/Sat.");
        }
    
    return 0;

}