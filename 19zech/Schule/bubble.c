#include <stdio.h>

int set[10] = {9,6,7,3,4,1,5,2,0,8};
int bigger;
int smaller;

int main()
{
    if(set[0] < set[1])
    {
        //If the first number in the array is smaller than the 2nd number, set Variable "smaller" as Array Index 0
        smaller = set[0];
        //Then, set the Variable "bigger" as the 2nd number in the array
        bigger = set[1];
        //Then set the first index of the array as the bigger Variable
        set[0] = bigger;
        //Then set the 2nd index of the array as the smaller Variable
        set[1] = smaller;
    }
    else 
    {
        smaller = set[1];
        bigger = set[2];
        set[1] = bigger;
        set[2] = smaller;
    }
}

