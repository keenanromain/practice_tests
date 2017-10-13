/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 03:23:53 by kromain           #+#    #+#             */
/*   Updated: 2017/02/08 03:39:31 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		valid(char *str, char c, int len)
{
	int i;

	i = -1;
	while (++i < len)
		if (str[i] == c)
			return (0);
	return (1);
}

void	ft_union(char *s1, char *s2)
{
	int i;
	int size;

	i = -1;
	while (s1[++i])
		if (valid(s1, s1[i], i))
			write(1, &s1[i], 1);
	size = --i;
	i = -1;
	while (s2[++i])
		if (valid(s2, s2[i], i))
			if (valid(s1, s2[i], size))
				write(1, &s2[i], 1);
}

int		main(int ac, char **av)
{
	if (ac == 3)
		ft_union(av[1], av[2]);
	write(1, "\n", 1);
	return (0);
}
