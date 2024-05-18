#include <stdio.h>
void main()
{
    int c, i, j, k = 1, l = 2;
    printf("Ener Your Column Number :- ");
    scanf("%d", &c);
    for (i = 1; i <= c; i++)
    {
        for (j = c; j >= i; j--)
        {
            if (i == 1)
            {
                printf("%d ", k);
                k++;
            }
            else if (j == i)
            {
                printf("%d ", c);
            }
            else if (j == c)
            {
                printf("%d ", l);
                l++;
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
}