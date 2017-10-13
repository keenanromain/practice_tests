/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 18:37:26 by kromain           #+#    #+#             */
/*   Updated: 2017/02/18 19:03:01 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_atoi(char *s)
{
	int i;
	int result;

	i = 0;
	result = 0;
	while (s[i])
	{
		result = result * 10 + s[i] - '0';
		i++;
	}
	return (result);
}

void	ft_putnbr(int nb)
{
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		nb += '0';
		ft_putchar(nb);
	}
}

void	ft_putstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

int		main(int ac, char **av)
{
	int num;
	int product;
	int count;

	num = 0;
	product = 0;
	count = 0;
	if (ac >= 2)
	{
		num = ft_atoi(av[1]);
		while (++count <= 9)
		{
			ft_putnbr(count);
			ft_putstr(" x ");
			ft_putstr(av[1]);
			ft_putstr(" = ");
			product = count * num;
			ft_putnbr(product);
			write(1, "\n", 1);
		}
	}
	else
		write (1, "\n", 1);
	return (0);
}
