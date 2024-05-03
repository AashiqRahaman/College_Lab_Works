#include <stdio.h>
void main()
{int n;
 printf("Enter upper limit Number: ");
 scanf("%d", &n);
 int i;
 for(i = 1; i <= n; i++)
   { int j;
     for(j = 1; j <= i/2; j++)
	{  if(j*j*j == i)
	   { int k;
	     for(k = 1; k <= i/2; k++)
		{ if(k*k == i)
		    { printf("%d ", i); }
		}
       	}
	}
	}
}

