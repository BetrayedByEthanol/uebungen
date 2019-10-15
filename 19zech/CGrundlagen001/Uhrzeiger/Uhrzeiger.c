#include <stdio.h>

/*The variables are defined here*/
int gradzwischen;
int stunde;
int minute;
int gradminute;
int gradstunde;

/*This is where the input field is coded*/
int main(){
puts("Enter Time: ");
scanf("%2d:%2d", &stunde, &minute);

/*The angle is calculated here*/
gradminute= minute*6;
gradstunde= stunde*60+minute;

/*This is the first loop of the program, it requires an input time where the hours are less than 24, and minutes are also less than 60*/
if(stunde < 24 && minute < 60)

{
	if(gradstunde > 720) gradstunde= gradstunde-720;
	gradstunde=gradstunde/2;
/*If the Hour angle is greater than 720, for example someone using the Military Clock (24 hours), it takes away 720 from the angle*/
	if(gradminute > gradstunde) 
    {
	gradzwischen= gradminute-gradstunde;
	}else
    {
	gradzwischen= gradstunde - gradminute;
	}
    
	if(gradzwischen > 180)
    {
	    printf("%d = Aussen Winkel \n", gradzwischen);
	    gradzwischen= 360-gradzwischen;
	    printf("%d Innen Winkel", gradzwischen);
	} 
    else 
    {
        if(gradzwischen==0) printf("Angle = 0");
        else
        {
	    printf("%d = Innen Winkel\n", gradzwischen);
	    gradzwischen= 360-gradzwischen;
	    printf("%d = Aussen Winkel", gradzwischen);
        }
    }      

}
else 
{
	printf("Falsche Eingabe");
}
}