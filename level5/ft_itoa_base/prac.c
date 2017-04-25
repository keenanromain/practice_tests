#include <stdlib.h>

long long	ft_num(int value, int *sign)
{
	long long num;

	num = (long long)value;
	*sign = 0;
	if (num >= 0)
		return (num);
	*sign = 1;
	return (num * -1);
}

long long	ft_i(int base, long long num)
{
	long long count;

	count = 0;
	while (num)
	{
		count++;
		num /= base;
	}
	return (count);
}

char	*ft_itoa_base(int value, int base)
{
	long long num;
	long long i;
	int sign;
	char *refer;
	char *ret;

	if (base < 2 || base > 16)
		return (NULL);
	if (value == 0)
		return("0\0");
	refer = "0123456789ABCDEF";
	num = ft_num(value, &sign);
	i = ft_i(base, num) + sign;
	if (base != 10 && sign == 1)
		i--;
	if (!(ret = (char *)malloc(sizeof(char) * i)))
		return (NULL);
	if (base == 10 && sign == 1)
		ret[0] = '-';
	ret[i] = '\0';
	while (num)
	{
		ret[--i] = refer[num % base];
		num /= base;
	}
	return (ret);
}

#include <stdio.h>

int		main(int ac, char **av)
{
	if (ac == 3)
		printf("%s\n", ft_itoa_base(atoi(av[1]), atoi(av[2])));
}
