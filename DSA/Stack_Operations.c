#include <stdio.h>
#include <stdlib.h>
#define max 10
int arr[10];
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
        for (int i = top; i >= 0; i--)
        {
            printf(" %d \n", arr[i]);
        }
        printf("\n");
        return 0;
    }
}

int Push()
{
    if (Is_Full())
    {
        printf("Push operation failed !! Stack Overflow \n");
    }
    else
    {
        top++;
        printf("Enter an integer input to Stack[%d]:  ", top);
        scanf("%d", &arr[top]);
    }
    return 0;
}

void Pop()
{
    if (Is_Empty())
    {
        printf("Pop Operation Failed !! Stack Underflow...\n");
    }
    else
    {
        printf("Poped element is:  %d \n\n", arr[top]);
        top--;
    }
}

int Search(int element)
{
    if (Is_Empty())
    {
        printf("The Stack is Empty!!!\n");
        return 0;
    }
    else
    {
        for (int i = 0; i <= top; i++)
        {
            if (arr[i] == element)
            {
                printf("Element found at index Stack[%d]", i);
                return 0;
            }
        }
    }
    printf("\nError 404!, Not Found\n");
    return 0;
}

int main()
{
    Push();
    Push();
    Push();
    Push();
    Push();
    Push();
    Traversal();
    Pop();
    Traversal();
    Search(10);

    return 0;
}