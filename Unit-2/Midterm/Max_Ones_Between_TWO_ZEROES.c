#include <stdio.h>

int MaxOnesBetweenTwoZeroes(int n)
{
    int count = 0;
    int max = 0;
    while(n)
    {
        if(n % 2 == 1)
            count++;
        else
        {
            if(count > max)
                max = count;
            count = 0;
        }
        if(count > max)
            max = count;
        n /= 2;
    }
    return max;
}
int main()
{
    printf("Test case 1:\n");
    printf("input ");
    int n;
    scanf("%d", &n);
    printf("Output: %d\n", MaxOnesBetweenTwoZeroes(n));

    printf("Test case 2:\n");
    printf("Input: ");
    scanf("%d", &n);
    printf("Output %d\n", MaxOnesBetweenTwoZeroes(n));
    return 0;
    
}