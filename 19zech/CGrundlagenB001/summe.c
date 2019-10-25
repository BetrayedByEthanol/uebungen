//Here is where we include the standard input/output library
#include <stdio.h>

//Here we define the variables without declaring a value
int var1;
int var2;
int var3;
int sum;

//Here is the start of the program
int main()
{
    //Here we print out the input field where the user can input their own numbers in the form of x,y,z
    printf("Input 3 varibales in the form of x,y,z; \n");
    //Here we scan the user input and assign those values to the variables using a pointer
    scanf("%d,%d,%d", &var1, &var2, &var3);
    //Here we print the user's input just for reference
    printf("Input: %d,%d,%d", var1, var2, var3);
    //This is the addition of the variables to get the sum
    sum= var1+var2+var3;
    //Here we print the equation using the variables and print the sum
    printf("\nEquation: %d+%d+%d=%d", var1, var2, var3, sum);
    //Here we print the result of the equation using words
    printf("\nThe sum of the numbers %d, %d and %d is: %d.", var1, var2, var3, sum);
    //Here we return a value of 0
    return 0;
}