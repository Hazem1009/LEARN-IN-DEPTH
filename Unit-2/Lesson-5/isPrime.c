#include <stdio.h>

int isPrime(int n)
{
    int i;
    for (i = 2; i < n/2; i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}
int main()
{
    printf("Enter two numbers(intervals): ");
    int a, b;
    scanf("%d %d", &a, &b);
    printf("Prime numbers between %d and %d are: ", a, b);
    for (int i = a; i <= b; i++)
    {
        if (isPrime(i))
            printf("%d ", i);
    }
    return 0;
}