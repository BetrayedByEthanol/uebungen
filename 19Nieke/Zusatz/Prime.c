#include <stdio.h>

unsigned int primes[2000000] = { 0 };
int numberOfFoundPrimes = 1;

void getPrimes(unsigned int number)
{
    for(int i = 0; i < sizeof(primes)/sizeof(primes[0]) ; i++)
    {
        if(primes[i] == 0) 
        {
            primes[i] = number;
            numberOfFoundPrimes++;
            printf("%d:  %d  ", i, number);
            return;
        }
        if(number % primes[i] == 0 && primes[i] != 0)
        {
            return;
        }
        
        
    }
}

int main()
{   
    int upperLimit = 0;
    unsigned int number = 3;
    puts("Wie viele Primzahlen sollen gesucht werden: ");
    scanf("%d", &upperLimit);
    if(upperLimit < 1) 
    {   
        puts("Falsche Eingabe");
        return -1;
    }

    primes[0] = 2;

    while(numberOfFoundPrimes <= upperLimit)
    {

        getPrimes(number);
        number++;
    }




    return 1;
}