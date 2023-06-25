#include <stdio.h>


int factorial(int n)
{
    if(n == 0)
        return 1;
    return n * factorial(n - 1);
}

int main()
{
    int arg;
    printf("Enter a positive integer: ");
    scanf("%d", &arg);
    printf("Factorial of %d = %d", arg, factorial(arg));


    return 0;
}