/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 19:26:26 by kromain           #+#    #+#             */
/*   Updated: 2017/02/03 03:22:48 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_last_word(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	i -= 1;
	while(str[i--])
		if(str[i] >= 33 && str[i] <= 126)
			break;
	while (str[i] != ' ' || (str[i] < 9 && str[i] > 13))
		i--;
	i += 1;
	while (str[i++])
		if (str[i] >= 33 && str[i] <= 126)
			ft_putchar(str[i]);
}

int		main(int argc, char** argv)
{
	if(argc == 2)
		ft_last_word(argv[1]);
	write(1, "\n", 1);
	return (0);
}
