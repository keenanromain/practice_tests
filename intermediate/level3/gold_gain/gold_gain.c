#include <stdlib.h>

int		ft_max(int **tab, int n, int col)
{
	int i;
	int ret;

	i = -1;
	ret = 0;
	while (++i < n)
		ret = tab[i][col] > ret ? tab[i][col] : ret;
	return (ret);
}

int		check_top(int **mine, int i);
int		check_middle(int **mine, int i);
int		check_bottom(int **mine, int i);

int		gold_gain(int **mine, int n)
{
	int i;
	int j;
	int	ret;
	int **tab;

	ret = 0;
	if (n > 0)
	{
		i = 0;
		j = 0;
		if (n == 1)
			return (mine[i][j]);
		//fill tab copy with mine's first column
		i = -1;
		while (++i < n)
			tab[i][0] = mine[i][0];
		//now run thru mine's second to n columns following Kyle's method
		i = 0; // start at second column as we know what's in the first
		while (++i < n)
		{
			if (i == 1)
				tab[i][++j] = check_top(mine, i);
			else if (i + 1 == n)
				tab[i][++j] = check_bottom(mine, i);
			else
				tab[i][++j] = check_middle(mine, i);
		}
		ret = ft_max(tab, n, n - 1); //fill ret's value with the max value stored in tab's final column.
	}
	return (ret);
}
