#include<stdio.h>
int add(int *b,int len)
{   int sum=0,i;
    for(i=0;i<len;i++)
    {   sum += b[i]; }
return sum; }
void main()
{   int size;
    printf("Enter the length of array : ");
    scanf("%d",&size);
    int a[size];
    for(int i=0;i<size;i++)
    {   printf("Enter the value of a[%d] : ",i);
        scanf("%d",&a[i]);    }
    printf("The sum of given numbers is : %d",add(a,size));
}
