#include <stdio.h>
void main()
{
    int a, b;
    printf("Enter Your First Number:- ");
    scanf("%d", &a);
    printf("Enter Your Second Number:- ");
    scanf("%d", &b);
    swap(a,b);
}
void swap(int x, int y)
{
    x = x + y;
    y = x - y;
    x = x - y;
   printf("here is Your Swap Value:\na=%d\nb=%d",x,y);
}