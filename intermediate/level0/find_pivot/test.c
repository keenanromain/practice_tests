int greater(int *arr, int n, int mid)
{
	int sum;

	sum = 0;
	while (++mid < n)
		sum += arr[mid];
	return (sum);
}

int lesser(int *arr, int n, int mid)
{
	int sum;

	sum = 0;
	while (--mid > n)
		sum += arr[mid];
	return (sum);
}

int		find_pivot(int *arr, int n)
{
	int max;
	int min;
	int great;
	int less;
	int mid;

	max = n;
	min = 0;
	great = 0;
	less = 0;
	mid = n / 2;
	if (n > 2)
	{
		while (max - min > 1)
		{
			great = greater(arr, n, mid);
			less = lesser(arr, -1, mid);
			if (great > less)
			{
				min = mid;
				mid = mid + (max - mid) / 2;
				continue ;
			}
			if (less > great)
			{
				max = mid;
				mid = min + (mid - 2) / 2;
				continue ;
			}
			return (mid);
		}
	}
	return (-1);
}

#include <stdio.h>

int arr1[] =  { 1, 2, 3, 4, 0, 6 };
int arr2[] =  { -5, 10, 2, 5 };
int arr3[] =  { 1, 100, 0, 0, 1 };
int arr4[] =  { 7, 9, 8 };
int arr5[] =  { 0, 0 };

void	print_array(int *arr,  int size)
{
		int i = -1;

		printf("array: [ ");
		while (++i < size - 1)
			printf("%d, ", arr[i]); 
		printf("%d ]\n", arr[i]); 
}

int main()
{
		print_array(arr1, 6);
		printf("pivot: arr[%d]\n\n", find_pivot(arr1, 6));
		print_array(arr2, 4);
		printf("pivot: arr[%d]\n\n", find_pivot(arr2, 4));
		print_array(arr3, 5);
		printf("pivot: arr[%d]\n\n", find_pivot(arr3, 5));
		print_array(arr4, 3);
		printf("pivot: arr[%d]\n\n", find_pivot(arr4, 3));
		print_array(arr5, 2);
		printf("pivot: arr[%d]\n\n", find_pivot(arr5, 2));
		return (0);
}
