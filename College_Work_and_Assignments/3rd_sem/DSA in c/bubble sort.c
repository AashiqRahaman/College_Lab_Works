#include <stdio.h>
int bubble(int arr[], int num)
{
    int x, y, temp;
    for (x = 0; x < num - 1; x++)
    {
        for (y = 0; y < num - x - 1; y++)
        {
            if (arr[y] > arr[y + 1])
            {
                temp = arr[y];
                arr[y] = arr[y + 1];
                arr[y + 1] = temp;
            }
        }
    }
    printf("\n \nArray after implementing bubble sort the output willbe : ");
    for (x = 0; x < num; x++)
    {
        printf("%d  ", arr[x]);
    }
    printf("\n");
    return 0;
}
int main()
{
    int num;
    printf("Please Enter the Number of Elements you want in the array: ");
    scanf("%d", &num);
    int arr[num];
    for (int x = 0; x < num; x++)
    {
        printf("Enter the input values to the array :");
        scanf("%d", &arr[x]);
    }
    bubble(arr, num);
    return 0;
}
