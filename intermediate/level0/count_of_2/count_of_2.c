int		count_of_2(int n)
{
	int i;
	int j;
	int	k;

	i = 2;
	j = 0;
	while (i <= n)
	{
		k = i;
		while (k)
		{
			if (k % 10 == 2)
				++j;
			k /= 10;
		}
		++i;
	}
	return (j);
}

#include <stdio.h>

int		main(void)
{
	printf("%d\n", count_of_2(25));
}
