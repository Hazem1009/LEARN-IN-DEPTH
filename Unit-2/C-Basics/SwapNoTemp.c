#include <stdio.h>

int main()
{
    int a, b;
    printf("Enter value of a: ");
    scanf("%d", &a);
    printf("Enter value of b: ");
    scanf("%d", &b);
    a = a + b;
    b = a - b;
    a = a - b;
    printf("After swapping, value of a = %d\n", a);
    printf("After swapping, value of b = %d\n", b);
    /*or we do this by using XOR operator
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    */
    return 0;
}