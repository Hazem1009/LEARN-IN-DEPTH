#include <stdio.h>
#include <string.h>
int main()
{
    float a[2][2], b[2][2], c[2][2];
  
    printf("Enter the elements of 1st matrix: \n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("Enter the element a%d%d:", i+1, j+1);
            scanf("%f", &a[i][j]);
        }            
    }

    printf("Enter the elements of 2nd matrix: \n");
    for(int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("Enter the element b%d%d:", i+1, j+1);
            scanf("%f", &b[i][j]);
        }
    }

    printf("Sum of Matrix:\n");
    for (int i = 0; i < 2; i++)
    {
        printf("\n");
        for (int j = 0; j < 2; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
            printf("%.1f\t", c[i][j]);
        }
    }
    return 0;
}