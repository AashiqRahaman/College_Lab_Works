#include <stdio.h>

int binary(int array[], int n, int key)
{
	int low, high, mid;
	low = 0;
	high = n - 1;
	mid = (low + high) / 2;
	while (low <= high)
	{
		if (array[mid] < key)
			low = mid + 1;
		else if (array[mid] == key)
		{
			printf("%d found in the array at position : %d \n", key, mid + 1);
			break;
		}
		else
			high = mid - 1;
		mid = (low + high) / 2;
	}
	if (low > high)
		printf("Not found! %d isn't present in the array", key);
	return 0;
}
int main()
{
	int i, n, key;
	printf("Enter number of elements to insert in array   :");
	scanf("%d", &n);
	int array[n];

	for (i = 0; i < n; i++)
	{
		printf("Enter the input values to the array :");
		scanf("%d", &array[i]);
	}
	printf("\n \nEnter value to search in given array :");
	scanf("%d", &key);
	binary(array, n, key);
	return 0;
}
