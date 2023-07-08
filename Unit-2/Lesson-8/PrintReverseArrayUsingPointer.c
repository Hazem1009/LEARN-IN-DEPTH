#include <stdio.h>

int main()
{
    int arr[15];
    int* ptr = arr;
    int numberofelements;
    printf("Input the number of elements to store in the array (max 15) : ");
    scanf("%d", &numberofelements);
    printf("Input %d number of elements in the array :  \n", numberofelements);
    for (int i = 0; i < numberofelements; i++)
    {
        printf("element - %d : ", i);
        scanf("%d", ptr);
        ptr++;
    }
    ptr--; // ptr is now pointing to the last element in the array
    printf("The elements of array in reverse order are :\n");
    for (int i = numberofelements; i > 0; i--)
    {
        printf("element - %d : %d\n", i, *ptr);
        ptr--;
    }

    return 0;

}