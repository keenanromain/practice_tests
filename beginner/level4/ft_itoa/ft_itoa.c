/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 16:10:10 by kromain           #+#    #+#             */
/*   Updated: 2017/03/01 18:58:44 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char		*ft_strdup(char *str)
{
	int i;
	int j;
	char *new;

	i = 0;
	while (str[i])
		i++;
	if (!(new = (char *)malloc(sizeof(char) * i)))
		return (NULL);
	j = -1;
	while (++j < i)
		new[j] = str[j];
	new[j] = '\0';
	return (new);
}

static int		ft_whatsign(int *nbr)
{
	if (*nbr < 0)
	{
		*nbr *= -1;
		return (1);
	}
	return (0);
}

char			*ft_itoa(int nbr)
{
	int		temp;
	int		positions;
	int		sign;
	char	*string;

	if (nbr == -2147483648)
		return (ft_strdup("-2147483648"));
	temp = nbr;
	positions = 2;
	sign = ft_whatsign(&nbr);
	while (temp /= 10)
		positions++;
	positions += sign;
	if (!(string = (char *)malloc(sizeof(char) * positions)))
		return (NULL);
	string[--positions] = '\0';
	while (positions--)
	{
		string[positions] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (sign == 1)
		string[0] = '-';
	return (string);
}
