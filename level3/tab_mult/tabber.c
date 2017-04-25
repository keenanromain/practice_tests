/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabber.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 17:45:22 by kromain           #+#    #+#             */
/*   Updated: 2017/03/01 22:16:35 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

void	ft_putnbr(int nb)
{
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}

int		ft_atoi(char *s)
{
	int result;
	int i;

	result = 0;
	i = -1;
	while (s[++i] && (s[i] >= '0' && s[i] <= '9'))
		result = result * 10 + s[i] - '0';
	return (result);
}

int		main(int ac, char **av)
{
	int count;
	int product;
	int value;

	if (ac == 2)
	{
		value = ft_atoi(av[1]);
		count = 0;
		while (++count <= 9)
		{
			product = count * value;
			ft_putnbr(count);
			ft_putstr(" x ");
			ft_putnbr(value);
			ft_putstr(" = ");
			ft_putnbr(product);
			ft_putchar('\n');
		}
	}
	else
		ft_putchar('\n');
	return (0);
}
