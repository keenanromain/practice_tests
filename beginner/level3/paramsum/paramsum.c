/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 17:39:54 by kromain           #+#    #+#             */
/*   Updated: 2017/03/01 17:49:30 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
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

int		main(int ac, char **av)
{
	int temp;
	char *storage;

	temp = 0;
	storage = av[1];
	if (ac > 1)
	{
		temp = --ac;
		ft_putnbr(temp);
	}
	else
		ft_putchar('0');
	ft_putchar('\n');
	return (0);
}
