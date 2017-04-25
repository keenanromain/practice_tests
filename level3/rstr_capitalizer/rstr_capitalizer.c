/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*  wstr_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 15:20:14 by kromain           #+#    #+#             */
/*   Updated: 2017/03/02 17:53:22 by kromain          ###   ########.fr       */
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
	int i;

	i = 0;
	while (s[i])
	{
		while (s[i] && (s[i] == ' ' || s[i] == '\t'))
			write(1, &s[i++], 1);
		while (s[i] && !(s[i] == ' ' || s[i] == '\t'))
		{
			if (s[i + 1] == ' ' || s[i + 1] == '\t' || s[i + 1] == '\0')
				check_me(s[i++]);
			else
				check_we(s[i++]);
		}	
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
