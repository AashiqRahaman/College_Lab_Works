#include <stdio.h>
int is_prime(int num)
{
    if (num <= 1)
    {    return 0;       }
    for (int i = 2; i * i <= num; i++)
    {   if (num % i == 0)
        {    return 0;   }
    }
    return 1;
}
void main()
{   int num, prime;
    printf("Enter a number: ");
    scanf("%d", &num);
    prime = num + 1;
    while (!is_prime(prime))
    {
        prime++;
    }
    printf("The next prime number is %d.\n", prime);
}