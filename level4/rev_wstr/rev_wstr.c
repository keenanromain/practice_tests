/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 10:42:50 by kromain           #+#    #+#             */
/*   Updated: 2017/03/14 10:54:43 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *s)
{
	int count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}

void	rev_wstr(char *s)
{
	int i;
	int j;

	i = ft_strlen(s);
	while (--i >= 0)
	{
		j = i;
		if (s[i - 1] == ' ' || s[i -1 ] == '\t' )
		{
			while (s[j] && s[j] != ' ' && s[j] != '\t')
				write(1, &s[j++], 1);
			write(1, " ", 1);
		}
		if (i - 1 == -1)
			while (s[j] && s[j] != ' ' && s[j] != '\t')
				write(1, &s[j++], 1);
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		rev_wstr(av[1]);
	write(1, "\n", 1);
	return (0);
}
