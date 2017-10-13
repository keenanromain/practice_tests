/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 23:03:49 by kromain           #+#    #+#             */
/*   Updated: 2017/03/06 23:18:26 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int		pgcd(int a, int b)
{
	int res;
	int min;
	int i;

	res = 1;
	min = ft_min(a, b);
	i = 0;
	while (++i <= min)
		if (a % i == 0 && b % i == 0)
			res = i;
	return (res);
}

int		main(int ac, char **av)
{
	if (ac == 3)
		printf("%d", pgcd(atoi(av[1]), atoi(av[2])));
	printf("\n");
	return (0);
}
