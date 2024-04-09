#include <stdio.h>
void main()
{   int n, i, s;
    printf("Enter a Integer Value :-  ");
    scanf("%d", &n);
    perfect_num(n, i, s);
}
void perfect_num(int n, int i, int s)
{   s = 0;
    for (i = 1; i < n; i++)
    {
        if (n % i == 0)
        { s += i; }
    }
    if (s == n)
    { printf("Your Input Integer %d Is a Perfect Number.", n); }
    else if (s != n)
    { printf("Your Input Integer %d Is not a Perfect Number.",n); }
    else
    { printf("Invalid Input !!!\nTry Again...\n"); }
}