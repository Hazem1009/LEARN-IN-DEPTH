#include <stdio.h>

int main()
{
    printf("Enter a number: ");
    int num;
    scanf("%d", &num);
    int fact=1;
    if (num<0)
    {
        printf("Error!!! Factorial of negative number doesn't exist\n");
        return 0;
    }
    for(int i=1; i<=num; i++)
    {
        fact*=i;
    }
    printf("Factorial of %d = %d\n", num, fact);
    return 0;
}