/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 00:11:07 by kromain           #+#    #+#             */
/*   Updated: 2017/03/13 00:31:04 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_atoi(char *s)
{
	int res;
	int i;

	res = 0;
	i = 0;
	while (*s && (*s == ' ' || (*s >= 9 && *s <= 13)))
		++s;
	if (s[i] == '-')
		return (0);
	while (s[i])
	{
		res = res * 10 + (s[i] - '0');
		++i;
	}
	return (res);
}

void	ft_putnbr(int nb)
{
	char c;

	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		c = nb + '0';
		write(1, &c, 1);
	}
}

int		ft_catch(int num)
{
	int i;

	i = 1;
	while (++i < num)
		if (num % i == 0)
			return (0);
	return (1);
}

void	ft_is_prime(int nb)
{
	int i;
	int count;

	i = 1;
	count = 0;
	while (++i <= nb)
		if (ft_catch(i))
			count = count + i;
	ft_putnbr(count);
}

int		main(int ac, char **av)
{
	if (ac == 2)
		ft_is_prime(ft_atoi(av[1]));
	else
		write(1, "0", 1);
	write(1, "\n", 1);
	return (0);
}
