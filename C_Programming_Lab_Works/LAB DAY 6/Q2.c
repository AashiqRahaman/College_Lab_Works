#include <stdio.h>

int main()
{
    int n, i, j, k, count, c[1000];
    printf("Please Declear the Length of the Array: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter Your  input:");
        scanf("%d", &arr[i]);
    }
    for (j = 0; j < n; j++)
    {
        count = 1;
        if (arr[j] != -1)
        {
            for (k = j + 1; k < n; k++)
            {
                if (arr[j] == arr[k])
                {
                    count++;
                    arr[k] = -1;
                }
            }
            c[j] = count;
            printf("%d occurs %d times\n", arr[j], c[j]);
        }
    }
    return 0;
}