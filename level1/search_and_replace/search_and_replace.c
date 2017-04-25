/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 19:43:03 by kromain           #+#    #+#             */
/*   Updated: 2017/03/01 20:30:43 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	yo(char *str, char one, char two)
{
	int i;
	int count;
	char *tmp;

	i = -1;
	count = 0;
	tmp = str;
	while (str[++i])
	{
		if (str[i] == one)
		{
			str[i] = two;
			count++;
		}
	}
	if (count == 0)
	{
		while (*tmp)
			write(1, tmp++, 1);
		return ;
	}
	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
}

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		main(int ac, char **av)
{
	if (ac == 4 && (ft_strlen(av[2]) > 1 || ft_strlen(av[3]) > 1))
	{
		write(1,"\n", 1);
		return (0);
	}
	if (ac == 4)
		yo(av[1], *av[2], *av[3]);
	write(1, "\n", 1);
	return (0);
}
