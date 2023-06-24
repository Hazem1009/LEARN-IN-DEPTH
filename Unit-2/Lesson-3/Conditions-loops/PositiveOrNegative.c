#include <stdio.h>

int main()
{
    printf("Enter a number: ");
    float num;
    scanf("%f", &num);
    if(num>0)
    {
        printf("%.2f is positive\n", num);
    }
    else if(num<0)
    {
        printf("%.2f is negative\n", num);
    }
    else
    {
        printf("You entered zero\n");
    }
    return 0;
}