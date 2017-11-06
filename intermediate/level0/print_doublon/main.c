
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define BLACK "\x1b[30m"
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define WHITE "\x1b[37m"
#define BBLACK "\x1b[40m"
#define BRED "\x1b[41m"
#define BGREEN "\x1b[42m"
#define BYELLOW "\x1b[43m"
#define BBLUE "\x1b[44m"
#define BMAGENTA "\x1b[45m"
#define BCYAN "\x1b[46m"
#define BWHITE "\x1b[47m"
#define RESET "\x1b[0m"
#define CLEAR "\033c"
#define BOLD "\033[1m"

void	print_doublon(int *a, int na, int *b, int nb);

void	print_arrays(int *x, int a, int *y, int b)
{
	int i = -1;
	printf(BOLD"ARRAY 1: [ ");
	while (++i < a)
		printf("%s%d", i > 0 ? ", " : "", x[i]);
	printf(" ]\n");
	i = -1;
	printf("ARRAY 2: [ ");
	while (++i < b)
		printf("%s%d", i > 0 ? ", " : "", y[i]);
	printf(" ]\n"RESET);
}

#define SEPARATOR "\x1b[0m\n----------------------------------------------------------\n\n"

int main()
{
		int	a[] = {1, 2, 10, 15};
		int b[] = {2, 20, 40, 70};
		int c[] = {-5, 2, 10, 15, 50, 70, 100, 200, 300, 1200, 5000};
		int d[] = {2, 4, 5, 6, 7, 10, 40, 70};
		int	e[] = {100, 200, 300};
		int f[] = {1, 2, 3, 4};
		int g[] = {3, 4, 5, 6};
		int h[] = {1, 2, 3, 4};
		int i[] = {3, 4, 5, 6};
		int j[] = {3, 5, 8, 20};

		print_arrays(a, 4, b, 4);
		printf(YELLOW"Expected: 2\n");
		printf(GREEN"Output:   ");
		print_doublon(a, 4, b, 4);
		printf(SEPARATOR);
		print_arrays(c, 11, d, 8);
		printf(YELLOW"Expected: 2 10 70\n");
		printf(GREEN"Output:   ");
		print_doublon(c, 11, d, 8);
		printf(SEPARATOR);
		print_arrays(e, 3, f, 4);
		printf(YELLOW"Expected: \n");
		printf(GREEN"Output:   ");
		print_doublon(e, 3, f, 4);
		printf(SEPARATOR);
		print_arrays(g, 4, h, 4);
		printf(YELLOW"Expected: 3 4\n");
		printf(GREEN"Output:   ");
		print_doublon(g, 4, h, 4);
		printf(SEPARATOR);
		print_arrays(i, 4, j, 4);
		printf(YELLOW"Expected: 3 5\n");
		printf(GREEN"Output:   ");
		print_doublon(i, 4, j, 4);
		printf(RESET);
		return (0);
}
