#include <stdio.h>
void main()
{
   float n, i, j;
   float sum = 0;
   printf("Enter upper limit number:-  ");
   scanf("%f", &n);
   printf("{");
   for (i = 1; i <= n; i++)
   {
      sum = sum + (1 / i);
      printf("1/%f ", i);
      if (i < n)
      {
         printf("+ ");
      }
   }
   printf("}\n");
   printf("The Sum is = %f", sum);
}
