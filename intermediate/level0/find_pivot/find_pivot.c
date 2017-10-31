int greater(int *arr, int half, int n, int sum)
{
	while (++half < n)
		sum += arr[half];
	return (sum);
}
int lesser(int *arr, int half, int n, int sum)
{
	while (--half > n)
		sum += arr[half];
	return (sum);
}

int find_pivot(int *arr, int n)
{
	int min;
	int max;
	int half;
	int less;
	int great;

	min = 0;
	max = n;
	half = n / 2;
	if (n > 2)
	{
		while (max - min > 1)
		{
			great = greater(arr, half, n, 0);
			less = lesser(arr, half, -1, 0);
			if (great > less)
			{
				min = half;
				half = half + (max - half) / 2;
				continue ;
			}
			if (great < less)
			{
				max = half;
				half = min + (half - min) / 2;
				continue ;
			}
			return (half);
		}
	}
	return (-1);
}
