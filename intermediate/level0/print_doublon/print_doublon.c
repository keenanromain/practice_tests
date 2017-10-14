#include <stdio.h>

void	print_doublon(int *a, int na, int *b, int nb)
{
	int i;
	int j;
	int space;

	i = -1;
	space = 0;
	while (++i < na)
	{
		j = -1;
		while (++j < nb)
		{
			if (a[i] == b[j])
			{
				if (space)
					printf(" ");
				printf("%d", a[i]);
				space = 1;
				break ;
			}
		}
	}
	printf("\n");
}

int main(void)
{

	int a[11] = {-5, 2, 10, 15, 50, 70, 100, 200, 300, 1200, 5000};
	int na = 11;
	int b[8] = {2, 4, 5, 6, 7, 10, 40, 70};
	int nb = 8;
	print_doublon(a, na, b, nb);
	return (0);
}
