#include <unistd.h>

char	ft_change(char c)
{
    char	*s1;
    char	*s2;
    int		i;
    
    i = 0;
    s1 = "abcdefghijklmnopqrstuvwxyz";
    s2 = "nopqrstuvwxyzabcdefghijklm";
    while (s1[i])
    {
        if (s1[i] == c)
            return (s2[i]);
        i++;
    }
    return (0);
}

/*void	ft_putstr(char *str)
{
    int i;
    
    i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}
*/
int	main(int argc, char **argv)
{
    int		i;
    char	*str;
    
    if (argc == 2)
    {
        i = 0;
        str = argv[1];
        while(str[i])
        {
            if (str[i] >= 'a' && str[i] <= 'z')
                str[i] = ft_change(str[i]);
            else if (str[i] >= 'A' && str[i] <= 'Z')
                str[i] = ft_change(str[i] + 32) - 32;
            i++;
        }
		i = 0;
		while (str[i])
		{
			write(1, &str[i], 1);
			i++;
		}
    }
	write(1, "\n", 1);
    return (0);
}
