#include <stdlib.h>

long long	ft_num(int *sign, int value)
{
	long long num;

	num = (long long)value;
	*sign = 0;
	if (num >= 0)
		return (num);
	*sign = 1;
	return (num * -1);
}

long long	ft_i(long long num, int base)
{
	long long i;

	i = 0;
	while (num)
	{
		i++;
		num /= base;
	}
	return (i);
}

char	*ft_itoa_base(int value, int base)
{
	char *str;
	char *refer;
	long long num;
	long long i;
	int sign;

	if (base > 16 || base < 2)
		return (NULL);
	if (value == 0)
		return("0\0");
	refer = "0123456789abcdef";
	num = ft_num(&sign, value);
	i = ft_i(num, base) + sign;
	if (base != 10 && sign == 1)
		i--;
	if (!(str = (char *)malloc(sizeof(char) * i)))
		return (NULL);
	if (base == 10 && sign == 1)
		str[0] = '-';
	str[i] = '\0';
	while (num)
	{
		str[--i] = refer[num % base];
		num /= base;
	}
	return (str);
}

#include <stdio.h>

int		main(int ac, char **av)
{
	if (ac == 3)
		printf("%s\n", ft_itoa_base(atoi(av[1]), atoi(av[2])));
}
