#include <stdio.h>


long long reverseDigits(long long n)
{
    long long temp = n;
    long long rev = 0;
    while(temp > 0)
    {
        rev = rev * 10 + temp % 10;
        temp /= 10;
    }
    return rev;
}
int main()
{
    long long n;
    printf("Test case 1:\n");
    printf("input ");   
    scanf("%lld", &n);
    printf("Output: %lld\n", reverseDigits(n));

    printf("Test case 2:\n");
    printf("Input: ");
    scanf("%lld", &n);
    printf("Output %lld\n", reverseDigits(n));
    return 0;
}