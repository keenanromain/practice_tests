/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 12:47:33 by kromain           #+#    #+#             */
/*   Updated: 2017/02/26 16:26:32 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int		main(int argc, char **argv)
{
	int storage;

	if (argc == 4)
	{
		if (*argv[2] == '*')
		{
			storage = atoi(argv[1]) * atoi(argv[3]);
			printf("%d\n", storage);
		}
		if (*argv[2] == '/')
		{
			storage = atoi(argv[1]) / atoi(argv[3]);
			printf("%d\n", storage);
		}
		if (*argv[2] == '+')
		{
			storage = atoi(argv[1]) + atoi(argv[3]);
			printf("%d\n", storage);
		}
		if (*argv[2] == '-')
		{
			storage = atoi(argv[1]) - atoi(argv[3]);
			printf("%d\n", storage);
		}
		if (*argv[2] == '%')
		{
			storage = atoi(argv[1]) % atoi(argv[3]);
			printf("%d\n", storage);
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
