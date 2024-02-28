#include <stdio.h>
void main()
{   int n, i, j, k;
    printf("Enter The Row Number:-  ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j < i; j++)
        {   printf(" ");    }
        for (k = 1; k <= n; k++)
        {
            if (i == 1 || k == 1 || i == n || k == n)
            {   printf("* ");  }
            else
            {  printf("  ");   }
        }
        printf("\n"); 
    }
}