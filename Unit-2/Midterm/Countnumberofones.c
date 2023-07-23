#include    <stdio.h>   
int CountNumberofOnes(int n)
{
    int count = 0;
    while(n)
    {
       if(n%2 == 1)
            count++;
        n /= 2;

    }
    return count;
}

int main()
{
    int n;
    printf("Test case 1:\n");
    printf("input ");   
    scanf("%d", &n);
    printf("Output: %d\n", CountNumberofOnes(n));

    printf("Test case 2:\n");
    printf("Input: ");
    scanf("%d", &n);
    printf("Output %d\n", CountNumberofOnes(n));
    return 0;
}