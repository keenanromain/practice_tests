/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 12:47:33 by kromain           #+#    #+#             */
/*   Updated: 2016/11/17 15:16:24 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
    if (nb < 0)
    {
        ft_putchar('-');
        nb = -nb;
    }
    if (nb >= 10)
    {
        ft_putnbr(nb / 10);
        ft_putnbr(nb % 10);
    }
    if (nb < 10)
        ft_putchar('0' + nb);
}

int   ft_atoi(char *str)
{
    int nb;
    int i;
    
    i = 0;
    nb = 0;
    if (str[i] == '+' || str[i] == '-')
        ++i;
    while (str[i] >= '0' && str[i] <= '9')
    {
        nb = nb * 10 - ('0' - str[i]);
        ++i;
    }
    if (str[0] == '-')
        nb = -nb;
    return (nb);
}

int		main(int argc, char **argv)
{
	int storage;

	if (argc != 4)
	{
		write(1, "\n", 1);
		return (0);
	}
	if (*argv[2] == '*')
		storage = ft_atoi(argv[1]) * ft_atoi(argv[3]);
	if (*argv[2] == '/')
		storage = ft_atoi(argv[1]) / ft_atoi(argv[3]);
	if (*argv[2] == '+')
		storage = ft_atoi(argv[1]) + ft_atoi(argv[3]);
	if (*argv[2] == '-')
		storage = ft_atoi(argv[1]) - ft_atoi(argv[3]);
	if (*argv[2] == '%')
		storage = ft_atoi(argv[1]) % ft_atoi(argv[3]);
	ft_putnbr(storage);
	write(1, "\n", 1);
	return (0);
}
