#include <stdio.h>

void     print_doublon(int *a, int na, int *b, int nb)
{
	int i = 0;
	int j = 0;
	int space = 0;

	while (i < na && j < nb)
	{
		if (a[i] < b[j])
			++i;
		else if (a[i] > b[j])
			++j;
		else
		{
			printf(space ? " %d" : "%d", a[i]);
			space = 1;
			++i;
			++j;
		}
	}
	printf("\n");
}
