#include <stdio.h>

int main()
{
    int upper_Limit, prime_Output;
    printf("Input the amount of prime numbers you wish to list:");
    scanf("%d", &upper_Limit);
    calculate_Primes(upper_Limit);

    return 0;
}


void prime_Numbers(int upper_Limit, int prime_Output)
{
    while(prime_Output <= upper_Limit)
    {
        if(calculate_Primes()
        {
            printf("%d", prime_Output);
        }
        
    }
    prime_Output++;
}


int calculate_Primes(int num)
{
    int i;

    for (i=2; i<=num/2; i++)
    {
        if(num % i == 0)
        {
            return 0;
        }
    }
    
    return 1;
}

