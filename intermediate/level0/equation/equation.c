#include <stdio.h>

void	print(int a, int b, int c)
{
	printf("A = %d, B = %d, C = %d\n", a, b, c);
}

int		combine(int tens, int singles)
{
	int ret;

	ret = 0;
	while (ret < 100)
	{
		if (ret / 10 == tens && ret % 10 == singles)
			break ;
		ret++;
	}
	return (ret);
}

void	equation(int n)
{
	int a;
	int b;
	int c;

	if (n == 0)
	{
		print(0, 0, 0);
		return ;
	}
	a = 0;
	while (a < 10)
	{
		b = 0;
		while (b < 10)
		{
			c = 0;
			while (c < 10)
			{
				if (combine(a, b) + combine(c, a) == n)
					print(a, b, c);
				c++;
			}
			b++;
		}
		a++;
	}
}
