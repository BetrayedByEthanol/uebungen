/*Cody Zech
11.11.2019
CGrundlagenA003-A
ALBBW, Berlin
*/

//Here we include the Standard Input/Output library
#include <stdio.h>

//Here we define the variables needed for the program
int graphicNumber;
int graphic;
//Here we declare the function we use later in the program
void graphicOutput(int graphic);

//Here is the main program
int main()
{
    //We use a while loop here to allow the user to input numbers endlessly until they close the program
    while (1)
    {
        //Here we ask the user to input a number
        printf("Please input a number:\n");
        //Here we scan the input from the user and set it as the "graphicNumber" variable
        scanf("%d", &graphicNumber);
        //Here is where we call the function we define later and tell the function to exchange its parameters with the "graphicNumber" variable
        graphicOutput(graphicNumber);
    }
    //Here we return a value
    return 0;
}

//This is where we start a function
void graphicOutput(int graphic)
{
    //Here we assign a temporary variable that is to be set as the parameter of the function
    int tmp = graphic;
    //This is where our Switch/Case command is defined using the "tmp" variable
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
        //We then print a message telling the user to input a correct value
        printf("Please input a number between 0-9\n");
        break;
    }
}
