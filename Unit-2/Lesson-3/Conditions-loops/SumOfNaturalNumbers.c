#include<stdio.h>

int main()
{
    printf("Enter a number: ");
    int num;
    scanf("%d", &num);
    int sum=0;
    for(int i=1; i<=num; i++)
    {
        sum+=i;
    }
    printf("Sum =%d\n",sum);
    return 0;
}