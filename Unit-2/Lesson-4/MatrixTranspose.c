#include <stdio.h>

int main()
{
    float Matrix[100][100];
    int rows,cols;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);
    if(rows>100 || cols>100)
    {
        printf("Error! number should in range of (1 to 100).\n");
        return 0;
    }
    printf("Enter the elements of the matrix: \n");
    for(int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("Enter the element a%d%d:", i+1, j+1);
            scanf("%f", &Matrix[i][j]);
        }
    }
    printf("entered matrix: \n");
    for(int i = 0; i < rows; i++)
    {
        printf("\n");
        for (int j = 0; j < cols; j++)
        {
            printf("%.0f\t", Matrix[i][j]);
        }
    }
    printf("\nTranspose of Matrix:\n");
    for (int i = 0; i < cols; i++)
    {
        printf("\n");
        for (int j = 0; j < rows; j++)
        {
            printf("%.0f\t", Matrix[j][i]);
        }
    }
}