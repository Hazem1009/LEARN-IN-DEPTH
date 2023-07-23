#include <stdio.h>

void reverseArrayElements(int arr[], int size)
{
    int i=0;
    int j=size-1;
    while (j>i)
    {
        //swap
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
}

int main()
{
    printf("Test case 1:\n");

    int arr[5]={1,2,3,4,5};
    reverseArrayElements(arr, 5);
    printf("Output: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }
}