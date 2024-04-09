#include <stdio.h>
int swap(int x, int y)
{
    x = x + y;
    y = x - y;
    x = x - y;
    printf("here is Your Swap Value:\na=%d\nb=%d\n\n\n", x, y);
}
void swap2(int* a, int* b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
    printf("here is Your Swap Value:\na=%d\nb=%d\n\n", a, b);
}
void main()
{
    int a, b;
    printf("Enter Your First Number:- ");
    scanf("%d", &a);
    printf("Enter Your Second Number:- ");
    scanf("%d", &b);
    swap(a, b);
    swap2(&a, &b);
}
