// C program for implementation of selection sort
#include <stdio.h>

void swap(float *xp, float *yp)
{
    float temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(float arr[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        if (min_idx != i)
            swap(&arr[min_idx], &arr[i]);
    }
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    float a[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Arr[%d]: ", i);
        scanf("%f", &a[i]);
    }

    printf("\nOriginal array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%.2f ", a[i]);
    }

    selectionSort(a, n);
    printf("\nSorted array using Selection Sort:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%.2f ", a[i]);
    }
    return 0;
}