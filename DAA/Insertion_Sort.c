#include <math.h>
#include <stdio.h>

void insertionSort(float arr[], int n)
{
    int i, j;
    float key;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
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

    insertionSort(a, n);
    printf("\nSorted array using Insertion Sort:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%.2f ", a[i]);
    }
    return 0;
}
