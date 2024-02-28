#include <stdio.h>
void main()
{
    float a, b;
    printf("Enter a value of A:-\n");
    scanf("%f", &a);

    printf("Enter a value of B:-\n");
    scanf("%f", &b);
    a = a+b;
    b= a-b;
    a=a -b;
        printf("Values after swaps :\n");
    printf("A=%f \nB=%f", a,b);
}