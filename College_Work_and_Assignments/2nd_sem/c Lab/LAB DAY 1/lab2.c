#include <stdio.h>
void main()
{
    int a;
    printf("Enter The Year to Check Whether It is leap Year or Not:-\n");
    scanf("%d", &a);

    if ((a%4==0 && a%100!=0) || (a%400==0))
    {
        printf("This Year is Leap Year,\n");
    }
    else
    {
        printf("This is Not a Leap Year,\n");
    }
}