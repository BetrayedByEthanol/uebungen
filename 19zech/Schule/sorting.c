#include <stdio.h>

    void main()

    {
        int number[10] = {1, 3, 7, 2, 5, 6, 4, 8, 9, 10};
        int i, j, a;
        int n = 10;

        for (i = 0; i < n; ++i) 
        {
            for (j = i + 1; j < n; ++j)
            {
                if (number[i] < number[j]) 
                {
                    a =  number[i];
                    number[i] = number[j];
                    number[j] = a;
                }
            }
        }
        printf("The numbers arranged in ascending order are given below \n");
        for (i = 0; i < n; ++i)
            printf("%d\n", number[i]);
    }