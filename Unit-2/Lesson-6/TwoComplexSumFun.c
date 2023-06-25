#include <stdio.h>  
typedef struct  
{  
    float real;  
    float imag;
}Complex;

Complex addComplex(Complex* n1, Complex* n2)
{
    Complex temp;
    temp.real = n1->real+n2->real;
    temp.imag = n1->imag+n2->imag;
    return(temp);
}

int main()
{
    Complex n1,n2,sum;
    printf("For 1st complex number \n");
    printf("Enter real and imaginary part respectively:");
    scanf("%f", &n1.real);
    scanf("%f", &n1.imag);
    printf("\nFor 2nd complex number \n");
    printf("Enter real and imaginary part respectively:");
    scanf("%f", &n2.real);
    scanf("%f", &n2.imag);
    sum = addComplex(&n1, &n2);
    printf("Sum = %.1f + %.1fi", sum.real, sum.imag);
    return 0;
}