#include <stdio.h>
void swap(int *x, int *y)
{   int temp;
    temp = *x;
    *x = *y;
    *y = temp; }
void main()
{   int a, b;
    printf("Enter two integer(a,b) for swpping :\n");
    scanf("%d%d", &a, &b);
    swap(&a, &b);
    printf("After swapping :a=%d  b=%d", a, b); }
