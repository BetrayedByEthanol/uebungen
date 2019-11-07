#include <stdio.h>

//The variables are defined here
int betweenangle;
int hour;
int minute;
int minuteangle;
int hourangle;

//This is where we start the program
int main()
{
	//Here we ask the user to input a time, in the format HH:MM, and set those inputs as the variables "hour" and "minute"
	puts("Enter Time: ");
	scanf("%2d:%2d", &hour, &minute);

	//The angle is calculated here
	minuteangle = minute * 6;
	hourangle = hour * 60 + minute;

	//This is the first loop of the program, it requires an input time where the hours are less than 24, and minutes are also less than 60
	if (hour < 24 && minute < 60)
	{
		//If the Hour angle is greater than 720, for example someone using the Military Clock (24 hours), it takes away 720 from the angle
		if (hourangle > 720)
			hourangle = hourangle - 720;
		//Then it divides the hour angle by 2 and sets it as the hour angle
		hourangle = hourangle / 2;
		//If the minute angle is greater than the hourangle, the program branches off here
		if (minuteangle > hourangle)
		{
			//Here we take the hour angle from the minute angle and set it as the between angle
			betweenangle = minuteangle - hourangle;
		}
		//Otherwise the program branches off here where the hour angle is greater than the minute angle
		else
		{
			//We take the minute angle from the hour angle and set it as the between angle
			betweenangle = hourangle - minuteangle;
		}
		//If the between angle is greater than 180 degrees, the program branches off here
		if (betweenangle > 180)
		{
			//We then print out the outside angle as the between angle directly
			printf("%d = Outside Angle \n", betweenangle);
			//Then we take 360 from the between angle and then set it as the betweenangle variable
			betweenangle = 360 - betweenangle;
			//Then we print this out as the inside angle
			printf("%d Inside Angle", betweenangle);
		}
		//Otherwise the program branches off here
		else
		{
			//If the between angle is equal to 0, print the message "Angle = O"
			if (betweenangle == 0)
				printf("Angle = 0");
			//Otherwise the program branches off here
			else
			{
				//We then print the between angle as the inside angle, so long as the between angle variable isn't greater than 180
				printf("%d = Inside Angle\n", betweenangle);
				//Then we take 360 from the between angle and set it as the same variable
				betweenangle = 360 - betweenangle;
				//And print it as the outside angle
				printf("%d = Outside Angle", betweenangle);
			}
		}
	}
	//If the input isn't valid, print message "Invalid Input"
	else
	{
		printf("Invalid Input");
	}
}