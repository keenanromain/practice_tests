#include <stdlib.h>

long long	ft_number(int value, int *sign)
{
	long long num;

	num = (long long)value;
	*sign = 0;
	if (num >= 0)
		return (num);
	*sign = 1;
	return (num * -1);
}

long long	ft_index(int base, long long num)
{
	long long size;

	size = 0;
	while (num)
	{
		size++;
		num /= base;
	}
	return (size);
}

char	*ft_itoa_base(int value, int base)
{
	char *ret;
	char *refer;
	long long num;
	long long i;
	int sign;

	if (base > 16 || base < 2)
		return (NULL);
	if (value == 0)
		return ("0\0");
	num = ft_number(value, &sign);
	i = ft_index(base, num) + sign;
	if (sign == 1 && base != 10)
		i--;
	refer = "0123456789ABCDEF";
	if (!(ret = (char *)malloc(sizeof(char) * i)))
		return (NULL);
	if (sign == 1 && base == 10)
		ret[0] = '-';
	ret[i] = '\0';
	while (num)
	{
		ret[--i] = refer[num % base];
		num /= base;
	}
	return (ret);
}

#include <stdio.h> //testing purposes

int		main(int ac, char **av)
{
	if (ac == 3)
		printf("%s\n", ft_itoa_base(atoi(av[1]), atoi(av[2])));
	return (0);
}
