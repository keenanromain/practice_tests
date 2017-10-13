/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_last_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrabet <smrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 10:16:49 by smrabet           #+#    #+#             */
/*   Updated: 2017/03/06 22:02:15 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

int		main(int ac, char **av)
{
	if (ac > 1)
		ft_putstr(av[ac - 1]);
	write(1, "\n", 1);
	return(0);
}
