#include <stdio.h>

typedef struct
{
    int feet;
    float inch;
} Distance;

int main()
{
    printf("Enter information of first distance:\n");
    Distance d1,d2,sum;
    printf("Enter feet: ");
    scanf("%d", &d1.feet);
    printf("Enter inch: ");
    scanf("%f", &d1.inch);
    printf("Enter information of second distance:\n");
    printf("Enter feet: ");
    scanf("%d", &d2.feet);
    printf("Enter inch: ");
    scanf("%f", &d2.inch);
    sum.feet = d1.feet+d2.feet;
    sum.inch = d1.inch+d2.inch;
    while(sum.inch>=12)
    {
        sum.inch-=12;
        sum.feet++;
    }
    printf("Sum of distances = %d\'-%.1f\"", sum.feet, sum.inch);
    return 0;    
}