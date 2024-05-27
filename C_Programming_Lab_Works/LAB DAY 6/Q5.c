#include <stdio.h>

void main()
{
  int clm,n;
  printf("Enter Your Uper Limit Numer:- ");
  scanf("%d",&n);
  clm=n-2;
  for (int i = 1; i < 2 * clm; i++)
  { 
    int p = i > clm ? 2 * clm - i : i;
    for (int j = 0; j < p; j++)
    {
      printf(" ");
    }
    for (int j = clm - p; j >= 0; j--)
    {
      if (j == 0 || j == clm - p)
        printf("%d ", i);
      else
        printf("  ");
    }
    printf("\n");
  }
}