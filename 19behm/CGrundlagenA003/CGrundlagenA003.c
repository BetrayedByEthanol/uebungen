//Zahl zwischen 0-9 eingeben und als Textformat ausgeben

#include <stdio.h>
#include <string.h>
#include <ctype.h>

char first[10][10], second[10][10], third[10][10];


char definition(char xp, char yp[][10])
{
char zero[10][10] = {{" ### "},{ "#   #"},{ "#   #"},{ "#   #"}, {"#   #"}, {"#   #"}, {" ### "}};
char one[10][10] = {{"  #  "},{ " ##  "},{ "  #  "},{ "  #  "}, {"  #  "}, {"  #  "}, {" ### "}};
char two[10][10] = {{" ### "},{ "#   #"},{ "#   #"},{ "   # "}, {"  #  "}, {" #   "}, {"#####"}};
char three[10][10] = {{" ### "},{ "#   #"},{ "    #"},{ " ### "}, {"    #"}, {"#   #"}, {" ### "}};
char four[10][10] = {{"   # "},{ "  ## "},{ " # # "},{ "#  # "}, {"#####"}, {"   # "}, {"   # "}};
char five[10][10] = {{"#####"},{ "#    "},{ "#    "},{ "#### "},{ "    #"}, {"#   #"}, {" ### "}};
char six[10][10] = {{" ### "},{ "#   #"},{ "#    "},{ "#### "},{ "#   #"}, {"#   #"}, {" ### "}};
char seven[10][10] = {{"#####"},{ "    #"},{ "    #"},{ "   # "},{ "  #  "},{ " #   "},{ "#    "}};
char eight[10][10] = {{" ### "},{ "#   #"},{ "#   #"},{ " ### "},{ "#   #"},{ "#   #"},{ " ### "}};
char nine[10][10] = {{" ### "},{ "#   #"},{ "#   #"},{ " ####"},{ "    #"},{ "#   #"},{ " ### "}};

    if (xp == '0')
        yp = zero;
    else if (xp == '1')
        yp = one;
    else if (xp == '2')
        yp = two;
    else if (xp == '3')
       yp = three;
    else if (xp == '4')
        yp = four;
    else if (xp == '5')
        yp = five;
    else if (xp == '6')
        yp = six;
    else if (xp == '7')
        yp = seven;
    else if (xp == '8')
        yp = eight;
    else
        yp = nine;
}

int main()
{
    char input[10];
    

    printf("Bitte geben Sie die zu zeichnende Zahl ein.\n");
    scanf("%s", &input);
    char inp1 = input[0];
    char inp2 = input[1];
    char inp3 = input[2];

    definition(inp1, first);
    definition(inp2, second);
    definition(inp3, third);

    for(int i = 0; i < 8; i++)
    {
        printf("%s\t%s\t%s\n", first[i], second[i], third[i]);
        /*printf("%s\n", first[i]);
        puts("Test");*/
    }

    return 0;
}