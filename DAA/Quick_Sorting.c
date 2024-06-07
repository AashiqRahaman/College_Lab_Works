// C program for QuickSort
#include <stdio.h>


void swap(float *a, int i, int j)
{
    float temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int partition(float *a, int low, int high)
{
    float pivot = a[low];
    int i = low - 1, j = high + 1;

    while (1)
    {
        do
        {
            i++;
        } while (a[i] < pivot);

        do
        {
            j--;
        } while (a[j] > pivot);

        if (i >= j)
        {
            return j;
        }

        swap(a, i, j);
    }
}


void quickSort(float *a, int low, int high)
{
    if (low < high)
    {
        int pi = partition(a, low, high);
        quickSort(a, low, pi);
        quickSort(a, pi + 1, high);
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

    quickSort(a, 0, n - 1);
    printf("\nSorted array using Quick Sort:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%.2f ", a[i]);
    }
    return 0;
}