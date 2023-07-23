#include <stdio.h>
long long sumDigits(long long number)
{
    long long sum = 0;
    while (number > 0)
    {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

int main()
{
    long long number;
    printf("Test case 1:\n");
    printf("input ");
    scanf("%lld", &number);
    printf("SOutput: %lld\n", sumDigits(number));
    
    printf("Test case 2:\n");
    printf("Input: ");
    scanf("%lld", &number);
    printf("Output %lld\n", sumDigits(number));

    return 0;
}