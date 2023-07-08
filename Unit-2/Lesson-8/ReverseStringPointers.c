#include <stdio.h>

int main()
{
    char str[100];
    char rev[100];
    char* ptr = str;
    char* ptr2 = rev;
    
    printf("input a string\n");
    scanf("%s", str);
    int size=0;
    while (*ptr != '\0')
    {
        size++;
        ptr++;
    }
    ptr--;
    while (size > 0)
    {
        *ptr2 = *ptr;
        ptr2++;
        ptr--;
        size--;
    }
    *ptr2 = '\0';
    printf("%s\n", rev);
    return 0;
}