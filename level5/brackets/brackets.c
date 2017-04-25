#include <unistd.h>

int		ft_open(char c)
{
	return (c == '(' || c == '{' || c == '[' ? 1 : 0);
}

int		ft_close(char c)
{
	return (c == ')' || c == '}' || c == ']' ? 1 : 0);
}

int		ft_match(char a, char b)
{
	return ((a == '[' && b == ']') || (a == '{' && b == '}') || (a == '(' && b == ')') ? 1 : 0);
}

int		ft_brackets(char *s)
{
	int i;
	char stack[512];

	i = 0;
	while (*s)
	{
		if (ft_open(*s))
			stack[i++] = *s;
		if (ft_close(*s))
			if (i == 0 || !ft_match(stack[--i], *s))
				return (0);
		s++;
	}
	if (i != 0)
		return (0);
	return (1);
}

int		main(int ac, char **av)
{
	int i;

	i = 0;
	if (ac > 1)
	{
		while (++i < ac)
		{
			if (ft_brackets(av[i]))
				write(1, "OK\n", 3);
			else
				write(1, "Error\n", 6);
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
