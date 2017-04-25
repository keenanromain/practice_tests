#include <unistd.h>

int		error_out(void)
{
	write(1, "Error\n", 6);
	return (0);
}

int		match(char a, char b)
{
	return ((a =='(' && b == ')') || (a == '{' && b == '}') || (a == '[' && b == ']') ? 1 : 0);
}

int	brackets(char *s)
{
	unsigned char i;
	unsigned char stack[512];

	i = 0;
	while (*s)
	{
		if (*s == '(' || *s == '{' || *s == '[')
			stack[i++] = *s;
		if (*s == ')' || *s == '}' || *s == ']')
			if (i == 0 || !match(stack[--i], *s))
				return(error_out());
		s++;
	}
	return (i == 0 ? write(1, "OK\n", 3) : error_out());
}

int		main(int ac, char **av)
{
	int i;

	i = 0;
	if (ac > 1)
		while (++i < ac)
			brackets(av[i]);
	else
		write(1, "\n", 1);
}
