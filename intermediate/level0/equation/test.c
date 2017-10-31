#include <stdio.h>

int		combine(int first, int second)
{
	int i;

	i = -1;
	while (++i < 100)
		if (i / 10 == first && i % 10 == second)
			break;
	return (i);
}

void	equation(int n)
{
	int a;
	int b;
	int c;

	a = -1;
	while (++a < 10 && (b = -1) == -1)
		while (++b < 10 && (c = -1) == -1)
			while (++c < 10)
				if (combine(a, b) + combine(c, a) == n)
					printf("A = %d, B = %d, C = %d\n", a, b, c);
}

int main()
{
	equation(42);
	printf("\n\n");
	equation(111);
	printf("\n\n");
	equation(0);
}
