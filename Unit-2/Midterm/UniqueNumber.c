#include <stdio.h>


int UniqueOneLoop(int arr[], int n)
{
    int freqarray[9] = {0};
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        freqarray[arr[i]]++;
        if(freqarray[arr[i]] == 1)
            index = i;
    }
    return arr[index];

}
int main()
{
    //Test Case 1
     printf("Test case 1:\n");
    int a[7]={4,2,5,2,5,7,4};
    printf("Output: %d\n", UniqueOneLoop(a, 7));

    //Test case 2
     printf("Test case 2:\n");
     int a2[]={4,2,4};
    printf("Output: %d\n", UniqueOneLoop(a2, 3));
    return 0;
}