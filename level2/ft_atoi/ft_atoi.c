/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 16:57:48 by kromain           #+#    #+#             */
/*   Updated: 2017/02/03 03:09:05 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int   ft_atoi(const char *str)
{
    int nb;
    int i;
    
    i = 0;
    nb = 0;
	while(str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
    if (str[i] == '+' || str[i] == '-')
	{
		if(str[i] == '-')
			nb = -nb;
        ++i;
	}
    while (str[i] >= '0' && str[i] <= '9')
    {
        nb = nb * 10 - ('0' - str[i]);
        ++i;
    }
    return (nb);
}
