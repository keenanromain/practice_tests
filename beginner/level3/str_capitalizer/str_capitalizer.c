/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 15:20:14 by kromain           #+#    #+#             */
/*   Updated: 2017/03/02 15:47:38 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	check_me(char c)
{
	if (c >= 'a' && c <= 'z')
		ft_putchar(c - 32);
	else
		ft_putchar(c);
}

void	check_we(char c)
{
	if (c >= 'A' && c <= 'Z')
		ft_putchar(c + 32);
	else
		ft_putchar(c);
}
void	capper(char *s)
{
	while (*s)
	{
		while (*s && (*s == ' ' || *s == '\t'))
			write(1, s++, 1);
		if (*s && !(*s == ' ' || *s == '\t'))
			check_me(*s++);
		while (*s && !(*s == ' ' || *s == '\t'))
			check_we(*s++);
	}
}

int		main(int ac, char **av)
{
	int i;

	i = 0;
	if (ac > 0)
	{
		while (++i < ac)
		{
			capper(av[i]);
			ft_putchar('\n');
		}
	}
	else
		ft_putchar('\n');
	return (0);
}
