/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 21:21:23 by kromain           #+#    #+#             */
/*   Updated: 2017/03/01 21:30:01 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_min(unsigned int a, unsigned int b)
{
    if (a > b)
        return (b);
    else
        return (a);
}

unsigned int	lcm(unsigned int a, unsigned int b)
{
    unsigned int div;
    unsigned int i;
	unsigned int check;
	unsigned int min;
    
    div = 1;
    i = 1;
	check = 0;
	if (a == NULL || b == NULL)
		return (0);
	min = ft_min(a, b);
    while (i <= min)
    {
        if (a % i == 0 && b % i == 0 && ++check == 1)
            div = i;
        i++;
    }
    return (div);
}
