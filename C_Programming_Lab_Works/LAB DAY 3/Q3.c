#include <stdio.h>
void main()
{
    int i, j, n;
    printf("Enter The Row Number:- ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (i==1 || i==n)
            { printf("* "); }
            else if(j==1 || j==n)
            { printf("* "); }
            else{ printf("  "); }
        }
        printf("\n");
    }
}