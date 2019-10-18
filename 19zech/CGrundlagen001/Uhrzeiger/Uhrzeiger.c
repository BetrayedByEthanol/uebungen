#include <stdio.h>

/*The variables are defined here*/
int betweenangle;
int hour;
int minute;
int minuteangle;
int hourangle;

/*This is where the input field is coded*/
int main(){
puts("Enter Time: ");
scanf("%2d:%2d", &hour, &minute);

/*The angle is calculated here*/
minuteangle= minute*6;
hourangle= hour*60+minute;

/*This is the first loop of the program, it requires an input time where the hours are less than 24, and minutes are also less than 60*/
if(hour < 24 && minute < 60)

{
	if(hourangle > 720) hourangle= hourangle-720;
	hourangle=hourangle/2;
/*If the Hour angle is greater than 720, for example someone using the Military Clock (24 hours), it takes away 720 from the angle*/
	if(minuteangle > hourangle) 
    {
	betweenangle= minuteangle-hourangle;
	}else
    {
	betweenangle= hourangle - minuteangle;
	}
    
	if(betweenangle > 180)
    {
	    printf("%d = Aussen Winkel \n", betweenangle);
	    betweenangle= 360-betweenangle;
	    printf("%d Innen Winkel", betweenangle);
	} 
    else 
    {
        if(betweenangle==0) printf("Angle = 0");
        else
        {
	    printf("%d = Innen Winkel\n", betweenangle);
	    betweenangle= 360-betweenangle;
	    printf("%d = Aussen Winkel", betweenangle);
        }
    }      

}
else 
{
	printf("Falsche Eingabe");
}
}