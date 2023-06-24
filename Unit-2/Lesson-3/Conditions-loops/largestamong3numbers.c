#include <stdio.h>

int main()
{
    printf("Enter three numbers: ");
    float a, b, c;
    scanf("%f%f%f", &a, &b, &c);
    if(a>b && a>c)
        printf("largest number=%.2f", a);
    else if(b>a && b>c)
        printf("largest number=%.2f", b);
    else
        printf("largest number=%.2f", c);
    return 0; 
}