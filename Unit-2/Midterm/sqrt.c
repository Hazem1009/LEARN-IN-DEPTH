#include <stdio.h>
#include <math.h>

void Sqrt(int n)
{
    printf("Sqrt of %d is %f\n", n, sqrt(n));
}

int main()
{
    int n;
    printf("Test case 1:\n");
    printf("input ");   
    scanf("%d", &n);
    Sqrt(n);

    printf("Test case 2:\n");
    printf("Input: ");
    scanf("%d", &n);
    Sqrt(n);
    return 0;
}
