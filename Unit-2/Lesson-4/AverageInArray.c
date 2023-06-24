#include <stdio.h>

int main()
{
    float arr[100];
    float sum=0;
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    if(n>100)
    {
        printf("Error! number should in range of (1 to 100).\n");
        return 0;
    }
    for(int i = 0; i < n; i++)
    {
        printf("Enter number%d: ",i+1);
        scanf("%f", &arr[i]);
        sum += arr[i];
    }
    printf("Average = %.2f", sum/n);

    return 0;   
}