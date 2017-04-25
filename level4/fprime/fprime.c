/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 16:42:48 by kromain           #+#    #+#             */
/*   Updated: 2017/03/15 16:53:29 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	fprime(int num)
{
	int i;
	int check;

	if (num == 1)
		printf("1");
	if (num < 1)
		return ;
	i = 2;
	check = 0;
	while (i <= num)
	{
		if (num % i == 0)
		{
			if (++check > 1)
				printf("*");
			printf("%d", i);
			num /= i;
			i = 1;
		}
		i++;
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		fprime(atoi(av[1]));
	printf("\n");
	return (0);
}
