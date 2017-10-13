/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 03:01:57 by kromain           #+#    #+#             */
/*   Updated: 2017/02/13 15:46:19 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		wdmatch(char *s1, char *s2)
{
	int x;
	int y;

	x = -1;
	y = 0;
	while (s2[++x])
		if (s2[x] == s1[y])
			if (s1[++y] == '\0')
				while (*s1)
					write(1, s1++, 1);
}

int			main(int ac, char **av)
{
	if (ac == 3)
		wdmatch(av[1], av[2]);
	write(1, "\n", 1);
	return (0);
}
