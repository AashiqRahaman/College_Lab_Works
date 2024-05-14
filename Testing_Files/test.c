#include <stdio.h>

int main()
{
    int n;
    printf("Enter the length of your input array : \n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elments of the array : \n");
    for (int i = 0; i < n; i++)
    {
        printf("Array[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    printf("Here is the sorted array :\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}