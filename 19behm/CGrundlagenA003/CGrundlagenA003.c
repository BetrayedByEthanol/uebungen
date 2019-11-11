//Zahl zwischen 0-9 eingeben und als Textformat ausgeben

#include <stdio.h>
#include <string.h>

int main()
{
    int input;

    printf("Bitte geben Sie die zu zeichnende Zahl ein.\n");
    scanf("%d", &input);

    char line11[6] = {" ### "}, line12[6] = {"  #  "}, line13[6] = {"   # "}, line14[6] = {"#####"};
    char line21[6] = {"#   #"}, line22[6] = {" ##  "}, line23[6] = {"  ## "}, line24[6] = {"#    "}, line25[6] = {"    #"};
    char line31[6] = {"#   #"}, line32[6] = {"  #  "}, line33[6] = {"    #"}, line34[6] = {" # # "}, line35[6] = {"#    "};
    char line41[6] = {"#   #"}, line42[6] = {"  #  "}, line43[6] = {"   # "}, line44[6] = {" ### "}, line45[6] = {"#  # "}, line46[6] = {"#### "}, line47[6] = {" ####"};
    char line51[6] = {"#   #"}, line52[6] = {"  #  "}, line53[6] = {"    #"}, line54[6] = {"#####"};
    char line61[6] = {"#   #"}, line62[6] = {"  #  "}, line63[6] = {" #   "}, line64[6] = {"   # "};
    char line71[6] = {" ### "}, line72[6] = {"#####"}, line73[6] = {"   # "}, line74[6] = {"#    "};

    if(input == 0)
    {
        printf("%s\n", line11);
        printf("%s\n", line21);
        printf("%s\n", line31);
        printf("%s\n", line41);
        printf("%s\n", line51);
        printf("%s\n", line61);
        printf("%s\n", line71);
    }
    else if(input == 1)
    {
        printf("%s\n", line12);
        printf("%s\n", line22);
        printf("%s\n", line32);
        printf("%s\n", line33);
        printf("%s\n", line43);
        printf("%s\n", line53);
        printf("%s\n", line63);
        printf("%s\n", line71);
    }
    else if (input == 2)
    {
        printf("%s\n", line11);
        printf("%s\n", line21);
        printf("%s\n", line31);
        printf("%s\n", line43);
        printf("%s\n", line52);
        printf("%s\n", line63);
        printf("%s\n", line72);
    }
    else if (input == 3)
    {
        printf("%s\n", line11);
        printf("%s\n", line21);
        printf("%s\n", line33);
        printf("%s\n", line44);
        printf("%s\n", line53);
        printf("%s\n", line61);
        printf("%s\n", line71);
    }
    else if (input == 4)
    {
        printf("%s\n", line13);
        printf("%s\n", line23);
        printf("%s\n", line34);
        printf("%s\n", line45);
        printf("%s\n", line54);
        printf("%s\n", line64);
        printf("%s\n", line73);
    }
    else if (input == 5)
    {
        printf("%s\n", line14);
        printf("%s\n", line24);
        printf("%s\n", line35);
        printf("%s\n", line46);
        printf("%s\n", line53);
        printf("%s\n", line61);
        printf("%s\n", line71);
    }
    else if (input == 6)
    {
        printf("%s\n", line11);
        printf("%s\n", line21);
        printf("%s\n", line35);
        printf("%s\n", line46);
        printf("%s\n", line51);
        printf("%s\n", line61);
        printf("%s\n", line71);
    }
    else if (input == 7)
    {
        printf("%s\n", line14);
        printf("%s\n", line25);
        printf("%s\n", line33);
        printf("%s\n", line43);
        printf("%s\n", line52);
        printf("%s\n", line63);
        printf("%s\n", line74);
    }
    else if (input == 8)
    {
        printf("%s\n", line11);
        printf("%s\n", line21);
        printf("%s\n", line31);
        printf("%s\n", line44);
        printf("%s\n", line51);
        printf("%s\n", line61);
        printf("%s\n", line71);
    }
    else
    {
        printf("%s\n", line11);
        printf("%s\n", line21);
        printf("%s\n", line31);
        printf("%s\n", line47);
        printf("%s\n", line53);
        printf("%s\n", line61);
        printf("%s\n", line71);
    }
    return 0;
}