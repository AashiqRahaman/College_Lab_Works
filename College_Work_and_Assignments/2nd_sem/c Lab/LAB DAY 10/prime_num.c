#include <stdio.h>
#include <stdbool.h>
bool isPrime(int num)
{   if (num <= 1)
    {        return false;    }
    for (int i = 2; i <= num / 2; ++i)
    { if (num % i == 0)
        {            return false;        }
    }
}
void displayPrimeNumbers(int n)
{
    printf("Prime numbers between 1 and %d are:\n { ", n);

    for (int i = 2; i <= n; ++i)
    { if (isPrime(i))
        {            printf("%d ", i);        }
    }
    printf("}");
}
int main()
{   int n;
    printf("Enter a number: ");    
    scanf("%d", &n);
    displayPrimeNumbers(n);
    printf("\n");
    return 0;
}
