#include <stdio.h>
void freq(int n)
{   int i;
    int frequency[10] = {0};
    while (n != 0)
    {   int digit = n % 10;
        frequency[digit]++;
        n = n / 10;
    }
    printf("Frequency of each digit:\n");
    for (i = 0; i < 10; i++)
    {   if (frequency[i] != 0)
        {  printf("%d: %d\n", i, frequency[i]);  }
    }
}
void main()
{   int n;
    printf("Enter any number: ");
    scanf("%d", &n);
    freq(n);
}