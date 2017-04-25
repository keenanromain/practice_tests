#include <stdlib.h>

long long	ft_num(int *sign, int value)
{
	long long copy;

	copy = (long long)value;
	*sign = 1;
	if (copy < 0)
		return (copy * -1);
	*sign = 0;
	return (copy);
}

long long	ft_i(long long num, int base)
{
	long long index;

	index = 0;
	while (num)
	{
		index++;
		num /= base;
	}
	return (index);
}

char		*ft_itoa_base(int value, int base)
{
	long long	num;
	long long	i;
	int			sign;
	char		*ret;
	char		*refer;

	if (base < 2 || base > 16)
		return (NULL);
	if (value == 0)
		return("0\0");
	num = ft_num(&sign, value);
	i = ft_i(num, base) + sign;
	if (base != 10 && sign == 1)
		i--;
	if (!(ret = (char *)malloc(sizeof(char) * i)))
		return (NULL);
	if (base == 10 && sign == 1)
		ret[0] = '-';
	ret[i] = '\0';
	refer = "0123456789ABCDEF";
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
