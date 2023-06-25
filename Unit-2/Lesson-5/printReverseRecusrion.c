#include <stdio.h>

void printReverse(char *str)
{
    if (*str == '\0')
        return;
    printReverse(str + 1);
    printf("%c", *str);
}


int main()
{
    printf("Enter a sentence: ");
    char str[100];
    gets(str);
    printReverse(str);
    return 0;
}
