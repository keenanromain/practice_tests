#include <stdlib.h>

long long ft_num(int *sign, int value)
{
	long long num;

	num = (long long)value;
	*sign = 0;
	if (num >= 0)
		return (num);
	*sign = 1;
	return (num * -1);
}

long long ft_index(long long num, int base)
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

char	*ft_itoa_base(int value, int base)
{
	char *str;
	char *refer;
	long long num;
	long long index;
	int sign;

	if (base > 16 || base < 2)
		return (NULL);
	if (value == 0)
		return ("0\0");
	refer = "0123456789ABCDEF";
	num = ft_num(&sign, value);
	index = ft_index(num, base) + sign;
	if (sign == 1 && base != 10)
		index--;
	if (!(str = (char *)malloc(sizeof(char) * index)))
		return (NULL);
	if (sign == 1 && base == 10)
		str[0] = '-';
	str[index] = '\0';
	while (num)
	{
		str[--index] = refer[num % base];
		num /= base;
	}
	return (str);
}

#include <stdio.h> //testing purposes. Delete before submission

int		main(int ac, char **av)
{
	if (ac == 3)
		printf("%s\n", ft_itoa_base(atoi(av[1]), atoi(av[2])));
	return (0);
}
