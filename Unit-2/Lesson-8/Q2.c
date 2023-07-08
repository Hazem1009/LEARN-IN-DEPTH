#include <stdio.h>  

#define ALPHABET_SIZE 26
int main()
{
    char alphabet[ALPHABET_SIZE];
    char* ptr = alphabet;
    int i;
    for (i = 0; i < ALPHABET_SIZE; i++)
    {
        *ptr = 'A' + i;
        ptr++;
    }
    for (i = 0; i < ALPHABET_SIZE; i++)
    {
        printf("%c ", alphabet[i]);
    }

    return 0;
}