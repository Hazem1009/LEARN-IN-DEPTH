#include<stdio.h>

int main()
{
    printf("Enter a character: ");
    char ch;
    scanf("%c", &ch);
    if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
        printf("%c is a vowel\n", ch);
    else
        printf("%c is a consonant\n", ch);
    return 0;
}