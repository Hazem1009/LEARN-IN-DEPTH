#include <stdio.h>

char isPrime(int num)
{
    if (num == 1)
        return 1;
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
            return 0;
    }
    return 1;
}
int main()
{
    int lower, upper;
    printf("Enter lower and upper limit: ");
    scanf("%d %d", &lower, &upper);
    printf("Prime numbers between %d and %d are: ", lower, upper);
    for (int i = lower; i <= upper; i++)
    {
        if (isPrime(i))
            printf("%d ", i);
    }
    printf("\n");
    return 0;
}
