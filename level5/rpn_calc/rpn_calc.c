#include <stdio.h>
#include <stdlib.h>

int		error_out(void)
{
	return (printf("Error\n"));
}

int		is_num(char c)
{
	return (c >= '0' && c <= '9' ? 1 : 0);
}

int		is_sign(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' ? 1 : 0);
}

int		nb_len(char *s)
{
	int size;

	size = 0;
	if (*s == '-')
	{
		size++;
		s++;
	}
	while (*s && is_num(*s))
	{
		size++;
		s++;
	}
	return (size);
}

int		rpn_calc(char *s)
{
	int i;
	int stack[512];

	i = 0;
	while (*s)
	{
		if (is_num(*s) || (*s == '-' && is_num(*(s + 1))))
		{
			stack[i++] = atoi(s);
			s += nb_len(s);
			continue ;
		}
		if (*s == ' ')
		{
			s++;
			continue ;
		}
		if (!is_sign(*s))
			return(error_out());
		if (*s == '+')
			stack[i - 2] += stack[i - 1];
		if (*s == '-')
			stack[i - 2] -= stack[i - 1];
		if (*s == '*')
			stack[i - 2] *= stack[i - 1];
		if (*s == '/')
		{
			if (stack[i - 1] == 0)
				return (error_out());
			stack[i - 2] /= stack[i - 1];
		}
		if (*s == '%')
		{
			if (stack[i - 1] == 0)
				return (error_out());
			stack[i - 2] %= stack[i - 1];
		}
		i--;
		s++;
	}
	if (i != 1)
		return (error_out());
	return (printf("%d\n", stack[i - 1]));
}

int		main(int ac, char **av)
{
	if (ac != 2)
		return (error_out());
	return(rpn_calc(av[1]));
}
