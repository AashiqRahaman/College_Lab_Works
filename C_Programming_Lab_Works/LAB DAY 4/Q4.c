#include <stdio.h>
void main()
{   int n, fd, ld, temp, place = 1;
    printf("Enter an integer: ");
    scanf("%d", &n);
    ld = n % 10;
    temp = n;
    while (temp > 9)
    {   temp = temp / 10;
        place = place * 10;
    }
    fd = temp;
    n = ld * place + n % place;
    n = n / 10 * 10 + fd;
    printf("The new number after swapping first and last digit: %d\n", n);
}