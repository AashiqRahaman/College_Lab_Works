#include <stdio.h>
void main()
{
    int i,j,n;
    printf("Enter The Row Number:-  ");
    scanf("%d", &n);

    for(i=0;i<n;i++)
    {
     for(j=0;j<(2*n-1);j++)
     {
        printf("*");
     }
     printf("\n");
    }
}