#include <stdio.h>
void add(int *a, int *b, int *result) 
{
    *result = *a + *b;
}
void main()
{
   int a,b,result;
   printf("Enter Your First Number: ");
   scanf("%d",&a);
   printf("Enter Your Second Number: ");
   scanf("%d",&b);
   add(&a, &b, &result);
   printf("Here is Your Output: \n%d + %d = %d\n", a, b, result);
}
