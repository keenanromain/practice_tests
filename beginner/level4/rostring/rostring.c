/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 18:50:26 by kromain           #+#    #+#             */
/*   Updated: 2017/03/14 19:18:02 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	epur(char *s)
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
			write(1, " ", 1);
	}
	write(1, " ", 1);
}

void	rostring(char *s)
{
	char *tmp;

	tmp = s;
	while (*tmp && (*tmp == ' ' || *tmp == '\t'))
		tmp++;
	while (*tmp && !(*tmp == ' ' || *tmp == '\t'))
		tmp++;
	while (*tmp && (*tmp == ' ' || *tmp == '\t'))
		tmp++;
	if (*tmp)
		epur(tmp);
	while (*s && (*s == ' ' || *s == '\t'))
		s++;
	while (*s && !(*s == ' ' || *s == '\t'))
		write(1, s++, 1);
}

int		main(int ac, char **av)
{
	if (ac == 2)
		rostring(av[1]);
	write(1, "\n", 1);
	return (0);
}
