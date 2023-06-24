#include <stdio.h>

int main()
{
    int arr[100];
    printf("enter the number of elements: ");
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("enter the element to be searched: ");
    int element;
    scanf("%d", &element);
    int index=-1;
    for(int i=0; i<n; i++)
    {
        if(arr[i]==element)
        {
            index=i+1;
            break;
        }
    }
    if(index!=-1)
         printf("element found at index %d", index);
    else
        printf("element not found");
    return 0;
}