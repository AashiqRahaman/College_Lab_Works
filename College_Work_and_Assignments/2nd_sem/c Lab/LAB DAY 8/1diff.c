#include <stdio.h>
void dif(int *a, int size);
void main()
{   int len, i;
    printf("Enter size of array: ");
    scanf("%d", &len);
    int a[len];
    printf("Enter elements: ");
    for (i = 0; i < len; i++)
    {        scanf("%d", &a[i]);    }
    int *p = a;
    dif(p, len);
}
void dif(int *a, int size)
{   int i, dif[size - 1];
    for (i = 0; i < size; i++)
    {        dif[i] = a[i] - a[i + 1];    }
    printf("Output array: ");
    for (i = 0; i < size - 1; i++)
    {        printf("%d ", dif[i]);    }
    int *ptr = dif;
    int max = *ptr;
    for (i = 0; i < size - 1; i++)
    { if (max < *(ptr + 1))
        {     max = *(ptr + 1);  }
    }
    printf("\nLargest difference is = %d\n", max);
}