#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

# define BLACK "\x1b[30m"
# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define YELLOW "\x1b[33m"
# define BLUE "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN "\x1b[36m"
# define WHITE "\x1b[37m"
# define BBLACK "\x1b[40m"
# define BRED "\x1b[41m"
# define BGREEN "\x1b[42m"
# define BYELLOW "\x1b[43m"
# define BBLUE "\x1b[44m"
# define BMAGENTA "\x1b[45m"
# define BCYAN "\x1b[46m"
# define BWHITE "\x1b[47m"
# define RESET "\x1b[0m"
# define CLEAR "\033c"
# define BOLD "\033[1m"

int	gold_gain(int **mine, int n);

int	**int_array(int size)
{
	int i = -1;
	int	**arr = (int **)malloc(sizeof(int *) * size);
	while (++i < size)
		arr[i] = (int *)malloc(sizeof(int) * size);
	return (arr);
}

int main()
{
	int		gg;	
	int		**missingno = NULL;
	printf(BOLD"NO MINE:\n");
	printf(RESET""YELLOW"Expected: "BOLD"0\n"RESET);
	printf(GREEN"Output: "BOLD"%d\n\n"RESET, gold_gain(missingno, 0));
	
	printf("----------------------------------------------\n");
	int		mine0[1][1] = {	{69} };
	int		i = -1;
	int		j;
	int		s = 1;
	int		**m0 = int_array(s);
	printf(BOLD"ARRAY SIZE ONE:\n");
	while (++i < s)
	{
		j = -1;
		printf("\t\t[ ");
		while (++j < s)
		{
			m0[i][j] = mine0[i][j];
			printf("%s%d", j > 0 ? ", " : "", m0[i][j]);
		}
		printf(" ]\n");
	}
	printf(RESET""YELLOW"Expected: "BOLD"69\n"RESET);
	gg = gold_gain(m0, s);
	printf("%sOutput: "BOLD"%d\n\n"RESET, gg == 69 ? GREEN : RED, gg);
	
	printf("----------------------------------------------\n");
	int		mine1[3][3] = {	{1, 0, 0},
							{0, 3, 4},
							{0, 0, 0}	};
	i = -1;
	s = 3;
	int		**m1 = int_array(s);
	printf(BOLD"GIVEN EXAMPLE 1:\n");
	while (++i < s)
	{
		j = -1;
		printf("\t\t[ ");
		while (++j < s)
		{
			m1[i][j] = mine1[i][j];
			printf("%s%d", j > 0 ? ", " : "", m1[i][j]);
		}
		printf(" ]\n");
	}
	printf(RESET""YELLOW"Expected: "BOLD"8\n"RESET);
	gg = gold_gain(m1, s);
	printf("%sOutput: "BOLD"%d\n\n"RESET, gg == 8 ? GREEN : RED, gg);
	
	printf("----------------------------------------------\n");
	int		mine2[3][3] = {	{1, 2, 3},
							{3, 4, 8},
							{9, 6, 7}	};
	i = -1;
	s = 3;
	int		**m2 = int_array(s);
	printf(BOLD"GIVEN EXAMPLE 2:\n");
	while (++i < s)
	{
		j = -1;
		printf("\t\t[ ");
		while (++j < s)
		{
			m2[i][j] = mine2[i][j];
			printf("%s%d", j > 0 ? ", " : "", m2[i][j]);
		}
		printf(" ]\n");
	}
	printf(RESET""YELLOW"Expected: "BOLD"23\n"RESET);
	gg = gold_gain(m2, s);
	printf("%sOutput: "BOLD"%d\n\n"RESET, gg == 23 ? GREEN : RED, gg);

	printf("----------------------------------------------\n");
	int		mine3[4][4] = {	{1, 3, 1, 5},
							{2, 2, 4, 1},
							{5, 0, 2, 3},
							{0, 6, 1, 2}	};
	i = -1;
	s = 4;
	int		**m3 = int_array(s);
	printf(BOLD"GIVEN EXAMPLE 3:\n");
	while (++i < s)
	{
		j = -1;
		printf("\t\t[ ");
		while (++j < s)
		{
			m3[i][j] = mine3[i][j];
			printf("%s%d", j > 0 ? ", " : "", m3[i][j]);
		}
		printf(" ]\n");
	}
	printf(RESET""YELLOW"Expected: "BOLD"16\n"RESET);
	gg = gold_gain(m3, s);
	printf("%sOutput: "BOLD"%d\n\n"RESET, gg == 16 ? GREEN : RED, gg);
}
