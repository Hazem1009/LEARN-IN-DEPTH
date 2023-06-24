#include <stdio.h>

int main()
{
    char str[100];
    printf("Enter a string: ");
    gets(str);
    char ch;
    printf("Enter a character to find frequency: ");
    scanf("%c", &ch);
    int count=0;
    for(int i=0; str[i]!='\0'; i++)
    {
        if(str[i]==ch)
            count++;
    }
    printf("Frequency of %c = %d", ch, count);
    return 0;
}