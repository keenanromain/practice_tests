#include <stdio.h>

int		max_of_two(int a, int b)
{
	return (a > b ? a : b);
}

int		max_of_three(int a, int b, int c)
{
	if (a > b)
		return (a > c ? a : c);
	return (b > c ? b : c);
}

int		gold_gain(int **mine, int n)
{
	int		tab[n][n];
	int		ret;
	int		x;
	int		y;

	ret = 0;
	if (mine && n > 1)
	{
		x = -1;
		while (++x < n)
			tab[x][0] = mine[x][0];
		y = 0;
		while (++y < n)
		{
			x = 0;
			tab[x][y] = mine[x][y] + max_of_two(tab[x][y - 1], tab[x + 1][y - 1]);							//top position in a column can only be summed with the previous column's top spot or one below it. See the bottom column's position for a mirror
			while (++x < n - 1)
				tab[x][y] = mine[x][y] + max_of_three(tab[x - 1][y - 1], tab[x][y - 1], tab[x + 1][y - 1]); //run through the middle elements of each columne
			tab[x][y] = mine[x][y] + max_of_two(tab[x][y - 1], tab[x - 1][y - 1]);							// the highest value is always stored in the bottom column as the middle column's highest value progressed down the loop as it executed
			ret = max_of_two(tab[x][y], tab[x - 1][y]);														// then ret stores said value if it is higher than the previous column's bottom-most value
		}
	}
	return (mine && n == 1 ? mine[0][0] : ret);
}

/*
 * 7 0 3 9 2  <- only can check back-left and back-left-below
 * 4 3 2 6 6  {
 * 4 1 6 3 2  {- can check back-left, back-left-below, and back-left-above which is why the inner loop is ran
 * 3 5 5 7 8  {
 * 1 8 6 1 2  <- only can check back-left and back-left-above
 */
