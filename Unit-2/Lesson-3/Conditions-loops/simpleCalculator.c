#include <stdio.h>

int main()
{
    char choice;
    printf("Enter Operator either + or - or * or / : ");
    scanf("%c", &choice);
    float a, b;
    printf("Enter two operands: ");
    scanf("%f%f", &a, &b);
    switch(choice)
    {
        case '+':
            printf("%.1f + %.1f = %.1f", a, b, a+b);
            break;
        case '-':
            printf("%.1f - %.1f = %.1f", a, b, a-b);
            break;
        case '*':
            printf("%.1f * %.1f = %.1f", a, b, a*b);
            break;
        case '/':
            printf("%.1f / %.1f = %.1f", a, b, a/b);
            break;
        default:
            printf("Invalid Operator");
    }
}