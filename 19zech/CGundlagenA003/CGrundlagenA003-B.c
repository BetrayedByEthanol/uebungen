/*Cody Zech
11.11.2019
CGrundlagenA003-B
ALBBW, Berlin
*/

//Here we include the Standard Input/Output library
#include <stdio.h>

//Here we define a character array with 4 useable characters, as well as 3 different tmp variables 
char number[5];
char index0;
char index1;
char index2;
//Here we declare the function graphicOutput with the parameters "char graphic"
void graphicOutput(char graphic);
//Here we write the function graphicOutput to display the input numbers from the User into an ASCII graphic
void graphicOutput(char graphic)
{
    //Here we set a temporary variable to take on the value of "graphic"
    char tmp = graphic;
    //Here we use the tmp variable and use it in the Switch/Case function
    switch (tmp)
    {
       //If the "graphicNumber" in the main function is 0, it is set as the tmp variable in this function, and thus "Case 0" applies
    case 0:
        //We then print out the number in ASCII using #
        printf("\n ### \n#   #\n#   #\n#   #\n#   #\n#   #\n ###\n");
        //We then break to end the function and return to the while loop
        break;
    //If the "graphicNumber" in the main function is 1, it is set as the tmp variable in this function, and thus "Case 1" applies
    case 1:
        printf("\n  #  \n ##  \n  #  \n  #  \n  #  \n  #  \n ### \n");
        break;
    //If the "graphicNumber" in the main function is 2, it is set as the tmp variable in this function, and thus "Case 2" applies
    case 2:
        printf("\n ### \n#   #\n#   #\n   # \n  #  \n #   \n#####\n");
        break;
    //If the "graphicNumber" in the main function is 3, it is set as the tmp variable in this function, and thus "Case 3" applies
    case 3:
        printf("\n ### \n#   #\n    #\n ### \n    #\n#   #\n ### \n");
        break;
    //If the "graphicNumber" in the main function is 4, it is set as the tmp variable in this function, and thus "Case 4" applies
    case 4:
        printf("\n   # \n  ## \n # # \n#  # \n#####\n   # \n   # \n");
        break;
    //If the "graphicNumber" in the main function is 5, it is set as the tmp variable in this function, and thus "Case 5" applies
    case 5:
        printf("\n#####\n#    \n#    \n#### \n    #\n#   #\n ### \n");
        break;
    //If the "graphicNumber" in the main function is 6, it is set as the tmp variable in this function, and thus "Case 6" applies
    case 6:
        printf("\n ### \n#   #\n#    \n#### \n#   #\n#   #\n ### \n");
        break;
    //If the "graphicNumber" in the main function is 7, it is set as the tmp variable in this function, and thus "Case 7" applies
    case 7:
        printf("\n#####\n    #\n    #\n   # \n  #  \n #   \n#    \n");
        break;
    //If the "graphicNumber" in the main function is 8, it is set as the tmp variable in this function, and thus "Case 8" applies
    case 8:
        printf("\n ### \n#   #\n#   #\n ### \n#   #\n#   #\n ### \n");
        break;
    //If the "graphicNumber" in the main function is 9, it is set as the tmp variable in this function, and thus "Case 9" applies
    case 9:
        printf("\n ### \n#   #\n#   #\n ####\n    #\n#   #\n ### \n");
        break;
    //If the "graphicNumber" in the main function does not match any of the cases, then the default case applies
    default:
        //We then print a message telling the user to input a correct (up to) 3 digit value
        printf("Please input a number between 000-999\n");
        break;
    }
}
//Here we start the main program
int main()
{
    //We use a while loop to allow the user to repeatedly give inputs
    while (1)
    {
        //Using the memset command, we set the value of the array as 0, so that when the user inputs 3 numbers, 
        //and then only inputs 1 or 2 numbers, the program still only shows the one number
        //For example, inputting 123, would display 123, but then in the next input, if the user only input a 1, the program would show 1 and 3 in an ASCII graphic
        memset(number, 0, sizeof(number));
        //Here we ask the user to input a number
        printf("Input a number between:\n");
        //Here we scan the input and set it as the character array named "number"
        scanf("%s", &number);
        //Here we use a form of cache, where we set the variable "index0" as the same value as the array index 0
        index0 = number[0];
        //We do the same for the array index 1
        index1 = number[1];
        //And again for the array index 2
        index2 = number[2];
        //Then we call the function and tell it to use the variable "index0"
        graphicOutput(index0);
        //We call the function again and tell it to use the variable "index1"
        graphicOutput(index1);
        //And again for the variable "index2"
        graphicOutput(index2);
    }
    //We then return an int value of 0
    return 0;
}
