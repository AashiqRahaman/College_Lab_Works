#include <stdio.h>
int main ()
{   int i,j;
    printf("Delear the Degree of Your first Eqn1: ");
    scanf("%d",&i);
    int arr1[i+1];
    for(int a=0;a<=i;a++)
      { printf("please enter the coefficient of x^%d : ",a);
        scanf("%d",&arr1[a]);     }
    printf("\n\nDelear the Degree of Your second Eqn2: ");
    scanf("%d",&j);
    int arr2[j+1];
    for(int a=0;a<=j;a++)
      { printf("please enter the coefficient of x^%d : ",a);
        scanf("%d",&arr2[a]);  }
    if(i<j)
      { int sum[j];
        for (int a=0;a<=i;a++)
          { sum[a] = (arr1[a] + arr2[a]);    }
         for (int a=i+1;a<=j;a++)
          {   sum[a] = (arr2[a]);         }
        printf("Here is Your Output\n");
        for (int a=0;a<=j;a++)
          {     printf("%dx^%d",sum[a],a);
                if(a<j)
                  {printf(" + ");}        }   }
     else if(j<i)
      { int sum[i];
        for (int a=0;a<=j;a++)
          { sum[a] = (arr1[a] + arr2[a]);    }
         for (int a=j+1;a<=i;a++)
          {   sum[a] = (arr2[a]);         }
        printf("Here is Your Output\n");
        for (int a=0;a<=i;a++)
          { printf("%dx^%d",sum[a],a);
            if(a<i)
              {printf(" + ");}        }   }
     else
      { int sum[i];
        for (int a=0;a<=i;a++)
          { sum[a] = (arr1[a] + arr2[a]);    }
        printf("Here is Your Output:-\n");
        for (int a=0;a<=j;a++)
          {     printf("%dx^%d",sum[a],a);
                if(a<j)
                    {printf(" + ");}          }   } }
