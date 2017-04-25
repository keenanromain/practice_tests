/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 21:08:58 by kromain           #+#    #+#             */
/*   Updated: 2017/03/06 21:27:29 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

void	aff_a(char *s)
{
	int i;

	i = -1;
	while (s[++i])
		if (s[i] == 'a' && ft_putchar('a') == 1)
			return ;
}

int		main(int ac, char **av)
{
	if (ac == 2)
		aff_a(av[1]);
	else
		ft_putchar('a');
	ft_putchar('\n');
	return (0);
}
