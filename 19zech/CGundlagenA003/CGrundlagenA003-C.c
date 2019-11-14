/* Cody Zech
11.11.2019
CGrundlagenA003-C
ALBBW, Berlin
*/

//Here we include the Standard Input/Output and String libraries
#include <stdio.h>
#include <string.h>

//Here we define an array of the size 510 called "arrayOutput", and tell it to only work when 7 newlines are present
char arrayOutput[510] = "\n\n\n\n\n\n\n";
//We then define an array of the size 120 called "arrayCache"
char arrayCache[120];

//Here we define the graphicOutput function with the parameter "char graphic" which can be switched for a different variable later
void graphicOutput(char graphic)
{
    //Here we define a temporary variable named "cache" which takes on the value of the "graphic" parameter
    char cache = graphic;
    //Here we start our Switch/Case control structure with the variable "cache"
    switch (cache)
    {
    case '0':
        //If "cache" has the value of '0', case '0' applies and we use the strcpy command to copy the string into another cache variable named "arrayCache" which we will use later
        strcpy(arrayCache, " ### \n#   #\n#   #\n#   #\n#   #\n#   #\n ###\n");
        //We then break to end the control structure
        break;
    case '1':
        //We repeat the same expression as in Case 0, for all other cases
        strcpy(arrayCache, "  #  \n ##  \n  #  \n  #  \n  #  \n  #  \n ### \n");
        break;
    case '2':
        strcpy(arrayCache, " ### \n#   #\n#   #\n   # \n  #  \n #   \n#####\n");
        break;
    case '3':
        strcpy(arrayCache, " ### \n#   #\n    #\n ### \n    #\n#   #\n ### \n");
        break;
    case '4':
        strcpy(arrayCache, "   # \n  ## \n # # \n#  # \n#####\n   # \n   # \n");
        break;
    case '5':
        strcpy(arrayCache, "#####\n#    \n#    \n#### \n    #\n#   #\n ### \n");
        break;
    case '6':
        strcpy(arrayCache, " ### \n#   #\n#    \n#### \n#   #\n#   #\n ### \n");
        break;
    case '7':
        strcpy(arrayCache, " ######\n      #\n     #\n    #\n   # \n  #  \n #    \n");
        break;
    case '8':
        strcpy(arrayCache, " ### \n#   #\n#   #\n ### \n#   #\n#   #\n ### \n");
        break;
    case '9':
        strcpy(arrayCache, " ### \n#   #\n#   #\n ####\n    #\n#   #\n ### \n");
        break;
    default:
        strcpy(arrayCache, "Blah");
        break;
    }
}
//Here we define the cache2array function which takes the "arrayCache" variable and sets it as the "arrayOutput" variable 
void cache2array()
{
    //We first define a temporary character array of the size [510], named "tmp"
    char tmp[510];
    //We then define variables for counting up the index of the arrays
    int upTmp = 0;
    int upTmp1 = 0;
    int upTmp2 = 0;
    //We then start a While loop, with the condition that it executes as long as the index of the arrayOutput isn't the value of '\0' which indicates the end of a string
    while (arrayOutput[upTmp] != '\0')
    {
        //Here we set the temporary variable "tmp[indexPositionVar]" as "arrayOutput[indexPositionVar]"
        tmp[upTmp] = arrayOutput[upTmp];
        //Then we add 1 to the counting variable "upTmp"
        upTmp++;
    }
    //Once the above While loop finishes, because eventually it will have counted up to the point where the string ends and the value in the arrayOutput variable is '\0'
    //We set the temporary variable "tmp[indexPositionVar]" as '\0'
    tmp[upTmp] = '\0';
    //We then set the counting variable "upTmp" as 0 to reset the index position of the array to 0 again
    upTmp = 0;
    //We then start another While loop, with the condition that it executes to long as the temporary variable "tmp[indexPositionVar]" isn't equal to '\0' which indicates the end of a string
    while (tmp[upTmp] != '\0')
    { 
        //Within this While loop, we start another While loop, with the condition that the temporary variable "tmp[indexPositionVar]" isn't equal to '\n' which indicates a newline
        while (tmp[upTmp] != '\n')
        {
            //We say the variable "arrayOutput[indexPositionVar1]" is equal to the temporary variable "tmp[indexPositionVar]"
            arrayOutput[upTmp1] = tmp[upTmp];
            //We then add 1 to the counting variable "upTmp"
            upTmp++;
            //We then add 1 to the counting variable "upTmp1"
            upTmp1++;
        }
        
        //We then start a new While loop with the condition that "arrayCache[indexPositionVar3]" isn't equal to '\n' which indicates a newline
        while (arrayCache[upTmp2] != '\n')
        {
            //Here we say that the variable "arrayOutput[indexPositionVar1]" is equal to the variable "arrayCache[indexPositionVar2]"
            arrayOutput[upTmp1] = arrayCache[upTmp2];
            //We then add 1 to the counting variable "upTmp1"
            upTmp1++;
            //We then add 1 to the counting variable "upTmp2"
            upTmp2++;
        } 
        //We then add 1 to both the counting variable "upTmp" as well as "upTmp2"
        upTmp++;
        upTmp2++;
        //We then say that the variable "arrayOutput[indexPositionVar1]" is equal to ' ' which indicates a space
        arrayOutput[upTmp1] = ' ';
        //We then add 1 to the counting variable "upTmp1"
        upTmp1++;
        //We then say that the variable "arrayOutput[indexPositionVar1]" is equal to '\n' which indicates a newline
        arrayOutput[upTmp1] = '\n';
        //We then add 1 to the counting variable "upTmp1"
        upTmp1++; 
    }
    //We then start another While loop with the condition that the variable arrayCache[indexPositionVar2] is not equal to '\0' which indicates the end of a string
    while (arrayCache[upTmp2] != '\0')
    {
        //We then say that the variable "arrayOutput[indexPositionVar1]" is equal to the variable "arrayCache[indexPositionVar2]
        arrayOutput[upTmp1] = arrayCache[upTmp2];
        //We then add 1 to both the variable "upTmp1" as well as the variable "upTmp2"
        upTmp1++;
        upTmp2++;
    }
    //We then say that the variable "arrayOutput[indexPositionVar1]" is equal to '\0' which indicates the end of a string
    arrayOutput[upTmp1] = '\0';
    
}

//Here we start the main program
int main()
{
    //First we define a local count variable named "count" and set its value as 0
    int count = 0;
    //Then we define a character array with the size [100], named "input" for the user input
    char input[100];
        //We then ask the user to input a number
        puts("Input a number:");
        //We set that input as the variable "input"
        gets(input);
        //We then start a while loop with the condition that it executes so long as the variable "input[indexPosition]" is not equal to '\0' which indicates the end of a string
        while (input[count] != '\0')
        {
            //Here we call the function "graphicOutput", telling it to use the variable "input[indexPosition]"
            graphicOutput(input[count]);
            //We then call the function "cache2array" without telling it what variables to use
            cache2array();
            //We then add 1 to the counting variable "count"
            count++;
        }
        //Then we print the variable "arrayOutput"
        puts(arrayOutput);
        //And return a value of 1
        return 1;
}