#include <unistd.h>
#include <stdlib.h>

int		count_spaces(char *s)
{
	int i;
	int ret;

	i = -1;
	ret = 0;
	while (s[++i])
		if (s[i] == 32)
			ret++;
	return (ret);
}

void	ord_alphlong(char *s)
{
	char **tab;
	int i;
	int j;

	tab = ft_strsplit(s);
	// too lazy to continue right now, will come back before next test
}

char	*only_spaces(char *s)
{
	int i;

	i = -1;
	while (s[++i])
		if (s[i] == 9)
			s[i] = 32;
	return (s);
}

int		main(int ac, char **av)
{
	if (ac == 2 && av[1])
		ord_alphlong(only_spaces(av[1]));
	write(1, "\n", 1);
	return (0);
}
