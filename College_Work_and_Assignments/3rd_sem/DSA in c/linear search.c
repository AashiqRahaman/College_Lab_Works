#include <stdio.h>
int search(int arr[], int a, int n)
{
	for (int i = 0; i < a; i++)
	{
		if (arr[i] == n)
		{
			printf("match fonund at index %d of given array\n", i);
			return 0;
		}
		else
		{
			continue;
		}
	}
	printf("No match found");
	return 0;
}
int main()
{
	int n;
	int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25};
	int a = sizeof(arr) / sizeof(arr[0]);
	printf("Enter the the number to find in the array :");
	scanf("%d", &n);
	search(arr, a, n);
	return 0;
}
