#include <stdio.h>

int main()
{
    char tag[89];
    gets(tag);
    //if (tag == 'montag') puts("1");
    //else if (tag == 'dienstag') puts("2");
    if (tag[0,1,2,3,4,5] == ('m','o','n','t','a','g'))//test
        puts("2");
    else if (tag[0,1,2,3,4,5,6,7] == ('d','i','e','n','s','t','a','g'))
        puts("3");
    else if (tag[0,1,2,3,4,5,6,7] == ('m','i','t','t','w','o','c','h'))
        puts("4");
    else if (tag[0,1,2,3,4,5,6,7,8,9] == ('d','o','n','n','e','r','s','t','a','g'))
        puts("5");
    else if (tag[0,1,2,3,4,5,6] == ('f','r','e','i','t','a','g'))
        puts("6");
    else if (tag[0,1,2,3,4,5,6] == ('s','a','m','s','t','a','g'))
        puts("7");
    else if (tag[0,1,2,3,4,5,6] == ('s','o','n','n','t','a','g'))
        puts("1");
    return 0;
}