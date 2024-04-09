#include <stdio.h>
void main()
{
    int i,arr[5];
    for(i=0;i<=4;i++)
    {
        printf ("Enter Your Input Value:-");
        scanf ("%d", &arr[i]);
    }
    printf ("Here is Your Output Value Accordingly :-\n");
    for(i=0;i<=4;i++)
    {
        printf("%d\n",arr[i]);
    }
}