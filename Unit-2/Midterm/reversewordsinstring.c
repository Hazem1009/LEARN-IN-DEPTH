#include <stdio.h>
#include <string.h>


void reverse_words_in_string(char *str)
{
    char *token = strtok(str, " ");
    char *arr[100];
    int i = 0;
    while (token != NULL)
    {
        arr[i] = token;
        i++;
        token = strtok(NULL, " ");
    }
    for (int j = i - 1; j >= 0; j--)
    {
        printf("%s ", arr[j]);
    }
    printf("\n");


}
int main()
{
    char str[100];
    printf("Enter a string: ");
    gets(str);
    reverse_words_in_string(str); 

    return 0;
}