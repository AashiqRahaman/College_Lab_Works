#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr, n;
    printf("enter the value of n: ");
    scanf("%d", &n);
    ptr = (int *)malloc(n * sizeof(int));
    printf("Enter your Input :\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ptr[i]);
    }
    printf("Here is your output vale :\n{");
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", ptr[i]);
    }
    printf("}");
}