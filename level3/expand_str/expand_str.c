/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 22:01:57 by kromain           #+#    #+#             */
/*   Updated: 2017/03/13 00:39:37 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	expand(char *s)
{
	while (*s)
	{
		while (*s && (*s == ' ' || *s == '\t'))
			s++;
		while (*s && !(*s == ' ' || *s == '\t'))
			write(1, s++, 1);
		while (*s && (*s == ' ' || *s == '\t'))
			s++;
		if (*s)
			write(1,"   ", 3);
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		expand(av[1]);
	write(1, "\n", 1);
	return (0);
}
