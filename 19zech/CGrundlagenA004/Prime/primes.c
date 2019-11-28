#include <stdio.h>
int n = 0, i = 0;
void calculate_Primes(int a, int b);



int main()
{
    int lowest_Value;
    int highest_Value;
    printf("Please input your starting value:");
    scanf("%d", &lowest_Value);
    printf("Please input your end value:");
    scanf("%d", &highest_Value);
    calculate_Primes(lowest_Value, highest_Value);
    return 0;
}

void calculate_Primes(int a, int b)
{
    while (a < b)
    {
        n = 0;

        for (i = 2; i <= a/2; ++i)
        {
            if (a % i == 0)
            {
                n = 1;
                break;
            }
        }

        if (n == 0)
        {
            printf("%d ", a);
            
        }
        ++a;
    }
    return 0;
}