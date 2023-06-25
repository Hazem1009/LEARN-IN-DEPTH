#include <stdio.h>
#define PI 3.14159
#define AREA(r) (PI*r*r)
int main()
{
    float radius;
    printf("Enter the radius\n");
    scanf("%f", &radius);
    printf("Area = %.2f \n", AREA(radius));
    return 0;
}
