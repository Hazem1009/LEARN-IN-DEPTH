#include <stdio.h>

int solver(int n)
{
    return (n * (n + 1) / 2);   
}
int main()
{
    printf("Sum of numbers from 1 to 100 is %d\n", solver(100));

}