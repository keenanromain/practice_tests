/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 18:50:26 by kromain           #+#    #+#             */
/*   Updated: 2017/03/20 18:55:25 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rostring(char *s)
{
	int i;

	i = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\t'))
		i++;
	while (s[i] && !(s[i] == ' ' || s[i] == '\t'))
		i++;
	while (s[i])
	{
		while (s[i] && (s[i] == ' ' || s[i] == '\t'))
			i++;
		while (s[i] && !(s[i] == ' ' || s[i] == '\t'))
			write(1, &s[i++], 1);
		while (s[i] && (s[i] == ' ' || s[i] == '\t'))
			i++;
		write(1, " ", 1);
	}
	i = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\t'))
		i++;
	while (s[i] && !(s[i] == ' ' || s[i] == '\t'))
		write(1, &s[i++], 1);
}

int		main(int ac, char **av)
{
	if (ac > 1)
		rostring(av[1]);
	write(1, "\n", 1);
	return (0);
}
