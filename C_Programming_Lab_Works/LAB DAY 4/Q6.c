#include <stdio.h>
int main()
{   int i, j, num[6], type[3];
    for (i = 0; i < 6; i++)
    {   printf("Enter Your Input Value :- ");
        scanf("%d", &num[i]);
    }
    int t1=0, t2=0, t3=0;
    for (i = 0; i < 6; i++)
    {   if (num[i] < 10)
        {    t1++;   }
        else if (num[i] / 10 < 10)
        {    t2++;   }
        else if (num[i] / 10 >= 10)
        {    t3++;   }
    }
    printf("Here is Output:- {1,%d,2,%d,3,%d}", t1, t2, t3);
}