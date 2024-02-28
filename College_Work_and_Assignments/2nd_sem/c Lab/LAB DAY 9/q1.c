#include <stdio.h>
int factorial(int n);
void main()
{
int n;
printf("Enter any number: ");
scanf("%d", &n);
int fac = factorial(n);
printf("%d! = %d\n", n, fac);
} int factorial(int n)
{
if (n == 0)
{
return 1;
}
else
{
return n * factorial (n - 1);
}
}