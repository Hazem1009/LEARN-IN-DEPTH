#include <stdio.h>

int main()
{
    int arr[100];
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to be inserted: ");
    int element;
    scanf("%d", &element);
    printf("Enter the location: ");
    int location;
    scanf("%d", &location);
    for(int i=n-1;i>=location;i--)
    {
        arr[i+1]=arr[i];
    }
    arr[location]=element;
    for(int i=0;i<n+1;i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}