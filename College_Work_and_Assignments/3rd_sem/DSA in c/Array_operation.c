#include <stdio.h>
int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int i, x, pos, index;
    printf("the current arr is:\n");
    for (i = 0; i < 5; i++)
        printf("%d ", arr[i]);
    printf("\n");
    printf("Enter a position to insert: ");
    scanf("%d", &pos);

    printf("Enter a number to insert: ");
    scanf("%d", &x);

    for (i = 5; i >= pos; i--)
        arr[i] = arr[i - 1];
    arr[pos - 1] = x;
    printf("after insert new arr is elements are that: \n");
    for (i = 0; i < 5 + 1; i++)
        printf("%d ", arr[i]);
    printf("\n");

    for (i = 0; i < 5+1; i++)
        printf("%d ", arr[i]);
    printf("\n");
    printf("Enter the index of the element to be deleted: ");
    scanf("%d", &index);
    if (index >= 6)
    {
        printf(" \n Deletion is not possible in the array.");
    }
    else
    {
        for (i = index; i < 5; i++)
            arr[i] = arr[i + 1];
        printf("The array after deleting the element is: ");
        for (i = 0; i < 5; i++)
            printf("%d ", arr[i]);
        printf("\n");
        return 0;
    }
    }

  