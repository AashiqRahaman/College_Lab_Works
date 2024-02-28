#include <stdio.h>
void calculateSum(int* arr, int size) 
{   int sum = 0;
    int A[size]; 
    for (int i = 0; i < size - 1; i++) 
    {   sum = *(arr + i) + *(arr + i + 1);
        A[i]=sum;    }
    printf("{");
    for(int i=0;i<size-1;i++)
    {     printf("%d ",A[i]);  }
       printf("}");  }
void main() 
{   int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) 
    {        scanf("%d", &arr[i]);    }
    printf("Addition of consecutive elements:\n");
    calculateSum(arr, size); }