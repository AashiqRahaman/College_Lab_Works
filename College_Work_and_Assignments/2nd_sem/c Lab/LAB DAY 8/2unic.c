#include <stdio.h>
void UniqueElements(int *arr, int size) 
{   printf("Unique elements: ");
    for (int i = 0; i < size; i++) 
    {   int j;
        for (j = 0; j < i; j++) 
        {   if (*(arr + i) == *(arr + j)) 
            {  break;  }
        }
        if (i == j) 
        {  printf("%d ", *(arr + i));   }
    } 
    printf("\n"); }
void main() 
{   int n=100;
    int arr[n];
    int size;
    printf("Enter the size of the array (maximum %d): ", n);
    scanf("%d", &size);
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) 
    {    scanf("%d", arr + i);   }
    UniqueElements(arr, size);
}