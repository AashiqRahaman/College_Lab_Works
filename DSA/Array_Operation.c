#include <stdio.h>
#include <stdlib.h>
#define max 10;
int top = -1;

int Traversal(int arr[])
{
    for (int i=0;i<=top;i++)
    {
        printf("%d",arr[i])
    }
}

int main()
{
    int n;
    printf("Enter the Max lenth of Your required array: ");
    scanf("%d", &n);
    int arr[n];
    
    top = 10;
    Traversal();


    return 0;
}