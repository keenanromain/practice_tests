#include <unistd.h>

int		error_out(void)
{
	write(1, "Error\n", 6);
	return (0);
}

int		is_open(char c)
{
	return (c == '{' || c == '(' || c == '[' ? 1 : 0);
}

int		is_close(char c)
{
	return (c == '}' || c == ')' || c == ']' ? 1 : 0);
}

int		is_pair(char a, char b)
{
	return ((a == '{' && b == '}') || ( a== '(' && b == ')') || (a == '[' && b == ']') ? 1 : 0);
}

int		brackets(char *s)
{
	int		i;
	char	stack[512];

	i = 0;
	while (*s)
	{
		if (is_open(*s))
			stack[i++] = *s;
		if (is_close(*s))
			if (i == 0 || !is_pair(stack[--i], *s))
				return(error_out());
		s++;
	}
	return ( i == 0 ? 1 : error_out());
}

int		main(int ac, char **av)
{
	int i;

	i = 0;
	if (ac < 2)
		return(error_out());
	while (++i < ac)
		if (brackets(av[i]))
			write(1, "OK\n", 3);
}
