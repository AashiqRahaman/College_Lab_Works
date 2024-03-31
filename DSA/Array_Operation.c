#include <stdio.h>
#include <stdlib.h>
#define max 5
int arr[5];
int top = -1;

int Is_Full()
{
    if (top == max)
        return 1;
    else
        return 0;
}

int Is_Empty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

int Traversal()
{
    if (Is_Empty())
    {
        printf("In Array no element to print or travers");
        return 0;
    }
    else
    {
        printf("The Current Array Elements are Printed Below: \n");
        for (int i = 0; i <= top; i++)
        {
            printf(" %d ", arr[i]);
        }
        printf("\n");
        return 0;
    }
}

int Insert(int index)
{
    if (index <= -1 && index >= max)
    {
        printf("Insert operation failed !! invalid index Number");
    }
    else
    {
        printf("Enter an integer input to Array[%d]:  ", index);
        scanf("%d", &arr[index]);
        top++;
    }
    return 0;
}

void Delete(int index)
{
    if (index <= -1 && index > top)
    {
        printf("Deletion Operation Failed !! Insert a valid index number...\n");
    }
    else
    {
        printf("Deleted element is:  %d \n\n", arr[index]);
        for (index; index < top; index++)
        {
            arr[index] = arr[index + 1];
        }
        top--;
    }
}

int Search(int element)
{
    if (Is_Empty())
    {
        printf("The array is Empty!!!\n");
        return 0;
    }
    else
    {
        for (int i = 0; i <= top; i++)
        {
            if (arr[i] == element)
            {
                printf("Element found at index arr[%d]", i);
                return 0;
            }
        }
    }
    printf("\nError 404!, Not Found\n");
    return 0;
}

void Update(int index, int value)
{
    if (index <= -1 && index >= top)
    {
        printf("Insert Update failed !! invalid index Number");
    }
    else
    {
        arr[index] = value;
    }
}

int main()
{
    Insert(0);
    Insert(1);
    Insert(2);
    Insert(3);
    Insert(4);
    Traversal();
    Delete(3);
    Traversal();
    Search(5);
    Update(3, 9);

    return 0;
}