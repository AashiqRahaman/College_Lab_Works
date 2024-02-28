#include <stdio.h>
void main()
{
    int i, j, n;
    printf("Enter The Value Of n:  ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)

    {
        for (j = n - i + 1; j > 1; j--)
        {
            printf(" ");
        }
        for (j = 1; j <= i; j++)
        {
            printf("* ");
        }
        printf("\n");
    }
}