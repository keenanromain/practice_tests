/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot13.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 22:01:34 by kromain           #+#    #+#             */
/*   Updated: 2016/11/17 22:18:34 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_switch1(char c)
{
	char	*s1;
	char	*s2;
	int		i;

	i = 0;
	s1 = "abcdefghijklmnopqrstuvwxyz";	
	s2 = "nopqrstuvwxyzabcdefghijklm";
	while (s1[i])
	{
		if (s1[i] == c)
			return (s2[i]);
		i++;
	}	
	return (0);
}

int		ft_switch2(char c)
{
	char	*s1;
	char	*s2;
	int		i;

	i = 0;
	s1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";	
	s2 = "NOPQRSTUVWXYZABCDEFGHIJKLM";
	while (s1[i])
	{
		if (s1[i] == c)
			return (s2[i]);
		i++;
	}
	return (0);
}
void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}
void	ft_rot(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if(str[i] >= 'a' && str[i] <= 'z')
			str[i] = ft_switch1(str[i]);
		if(str[i] >= 'a' && str[i] <= 'z')
			str[i] = ft_switch2(str[i]);
		i++;
	}
	ft_putstr(str);
}

int		main(int ac, char **av)
{
	if (ac == 2)
		ft_rot(av[1]);
	write(1, "\n", 1);
	return (0);
}
