#include <stdio.h>
void main()
{
    int num;
    printf("Enter an integer:- ");
    scanf("%d", &num);

    if (num % 2 == 0)
        printf("%d is an even number.", num);
    else if (num % 400 == 0)

        printf("%d is an even number.", num);
    else if (num % 100 == 0)

        printf("%d is an even number.", num);
    else
        printf("%d is an odd number.", num);

    
}
