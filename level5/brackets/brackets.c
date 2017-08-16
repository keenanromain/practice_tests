#include <unistd.h>

int		error_out(void)
{
	write(1, "Error\n", 6);
	return (0);
}

int		matches(char a, char b)
{
	return ((a == '(' && b == ')') || (a == '[' && b == ']' ) || (a == '{' && b == '}') ? 1 : 0);
}

int		brackets(char *s)
{
	unsigned char a = 0;
	unsigned char stack[512];

	while (*s)
	{
		if (*s == '(' || *s == '[' || *s == '{')
			stack[a++] = *s;
		if (*s == ')' || *s == ']' || *s == '}')
			if (a == 0 || !matches(stack[--a], *s))
				return(error_out());
		s++;
	}
	return (a == 0 ? 1 : error_out());
}

int		main(int ac, char **av)
{
	int i;

	i = 0;
	if (ac < 2)
		write(1, "\n", 1);
	else
		while(++i < ac)
			if (brackets(av[i]))
				write(1, "OK\n", 3);
	return (0);
}
