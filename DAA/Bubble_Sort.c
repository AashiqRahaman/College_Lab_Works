#include <stdbool.h>
#include <stdio.h>

void swap(float *xp, float *yp)
{
    float temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void bubbleSort(float arr[], int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++)
    {
        swapped = false;
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
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

    bubbleSort(a, n);
    printf("\nSorted array using Bubble Sort:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%.2f ", a[i]);
    }
    return 0;
}
