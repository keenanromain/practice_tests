/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 22:36:42 by kromain           #+#    #+#             */
/*   Updated: 2016/11/17 22:38:56 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>

void	ulstr(char *s)
{
    char	c;
	int		i;

	i = 0;    
    while (s[i])
    {
        if (s[i] >= 'a' && s[i] <= 'z')
            c = s[i] - 32;
        else if (s[i] >= 'A' && s[i] <= 'Z')
            c = s[i] + 32;
        else
            c = s[i];
        write(1, &c, 1);
        s++;
    }
}

int	main(int argc, char **argv)
{
    if (argc == 2)
        ulstr(argv[1]);
    write(1, "\n", 1);
    return (0);
}
