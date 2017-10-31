#include <unistd.h>
#include <stdlib.h>

void	ft_putstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

int		ft_strlen(char *s)
{
	int i;

	i = -1;
	while (s[++i])
		;
	return (i);
}


void	str_maxlenoc(char **av)
{
	char *max;
	char *tmp;

	max = *av;
	av++;
	while (*av)
	{
		tmp = "";
		pairing(max, tmp);
		if (ft_strlen(tmp) < ft_strlen(max))
			max = tmp;
		av++;
	}
	ft_putstr(max);
}

int		main(int ac, char **av)
{
	if (ac >= 2)
		ac == 2 ? ft_putstr(av[1]) : str_maxlenoc(++av);
	write(1, "\n", 1);
}
