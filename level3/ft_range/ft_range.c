/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 21:32:41 by kromain           #+#    #+#             */
/*   Updated: 2017/03/01 21:53:54 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int start, int end)
{
	int *arr;
	int i;

	if (!(arr = (int *)malloc(sizeof(int *) * (start - end))))
		return (NULL);
	if (start == end)
	{
		arr[0] = start;
		return (arr);
	}
	i = 0;
	while (start <= end)
	{
		arr[i++] = start++;
		if (start > end)
			return (arr);
	}
	while (start >= end)
	{
		arr[i++] = end++;
		if (start < end)
			return (arr);
	}
}
