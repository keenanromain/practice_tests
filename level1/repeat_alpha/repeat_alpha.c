/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 21:23:12 by kromain           #+#    #+#             */
/*   Updated: 2016/11/17 21:40:55 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_repeat_alpha(char *str)
{
	int i;
	int j;

	i = 0;
	while(str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			j = str[i] - 'a';
			while (j-- >= 0)
				write(1, &str[i], 1);
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			j = str[i] - 'A';
			while (j-- >= 0)
				write(1, &str[i], 1);
		}
		i++;
	}
}

int		main(int ac, char **av)
{
	if(ac == 2)
	{
		ft_repeat_alpha(av[1]);
	}
	write(1, "\n", 1);
	return(0);
}
