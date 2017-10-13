/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hider.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 00:44:49 by kromain           #+#    #+#             */
/*   Updated: 2017/03/13 00:56:41 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		hidenp(char *s1, char *s2)
{
	int i;
	int j;

	i = -1;
	j = 0;
	while (s2[++i])
		if (s2[i] == s1[j])
			if (s1[++j] == '\0')
				return (1);
	write(1, "0", 1);
	return (0);
}

int		main(int ac, char **av)
{
	if (ac == 3)
		if (hidenp(av[1], av[2]))
			write(1, "1", 1);
	write(1, "\n", 1);
	return (0);
}
