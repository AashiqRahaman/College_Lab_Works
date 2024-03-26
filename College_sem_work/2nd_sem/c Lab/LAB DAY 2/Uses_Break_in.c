#include <stdio.h>
int main()
{
    int i,n=2;
    for(i=0;i<=100;i++)
    {
        if(i==n)
        {
            n=n+2;
            break;
        }
    printf("%d",i);
    }
    return 0;
}