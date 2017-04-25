#include <stdio.h>
#include <stdlib.h>

int		error_out(void)
{
	return(printf("Error\n"));
}

int		is_sign(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' ? 1 : 0);
}

int		is_num(char c)
{
		return(c >= '0' && c <= '9' ? 1 : 0);
}

int		num_len(char *s)
{
	int size;

	size = 0;
	if (*s == '-')
	{
		size++;
		s++;
	}
	if (*s && is_num(*s))
	{
		size++;
		s++;
	}
	return(size);
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
			s += num_len(s);
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
			stack[0] += stack[1];
		if (*s == '-')
			stack[0] -= stack[1];
		if (*s == '*')
			stack[0] *= stack[1];
		if (*s == '/')
		{
			if (stack[1] == 0)
				return (error_out());
			stack[0] /= stack[1];
		}
		if (*s == '%')
		{
			if (stack[1] == 0)
				return (error_out());
			stack[0] %= stack[1];
		}
		i--;
		s++;
	}
	return (i == 1 ? printf("%d\n", stack[0] ) : error_out());
}

int		main(int ac, char **av)
{
	ac == 2 ? rpn_calc(av[1]) : error_out();
}
