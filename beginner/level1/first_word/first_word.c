/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 20:08:33 by kromain           #+#    #+#             */
/*   Updated: 2017/03/06 22:37:51 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_first_word(char *str)
{
	int i;

	i = -1;
	while(str[++i])
		if(str[i] >= 33 && str[i] <= 126)
			break;
	while(str[i] && (str[i] != ' ' || (str[i] >= 9 && str[i] <= 13)))
		write(1, &str[i++], 1);
}

int		main(int ac, char **av)
{
	if (ac == 2)
		ft_first_word(av[1]);
	write(1, "\n", 1);
	return (0);
}
