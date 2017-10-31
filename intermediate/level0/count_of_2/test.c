int		count_of_2(int n)
{
	int i;
	int j;
	int k;

	if (n <= 1)
		return (0);
	i = 1;
	k = 0;
	while (++i <= n)
	{
		j = i;
		while (j)
		{
			if (j % 10 == 2)
				k++;
			j /= 10;
		}
	}
	return (k);
}

#include <stdio.h>

int		main(void)
{
	printf("%d\n", count_of_2(25));
}
