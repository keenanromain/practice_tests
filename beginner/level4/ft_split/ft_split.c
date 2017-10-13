#include <stdlib.h>

static char		*ft_strndup(char *str, int num)
{
	int i;
	char *res;

	i = -1;
	if (!(res = (char *)malloc(sizeof(char) * num + 1)))
		return (NULL);
	while (++i <= num)
		res[i] = str[i];
	res[i] = '\0';
	return (res);
}

static int		count_words(char *str)
{
    int		i;
    int		count;
    
    i = 0;
    count = 0;
    while (str && str[i])
    {
        while (str[i] && (str[i] == ' ' || str[i] == '\t'))
            i++;
        if (str[i])
        {
            count++;
            while (str[i] && str[i] != ' ' && str[i] != '\t')
                i++;
        }
    }
    return (count);
}

char			**ft_split(char *str)
{
    char	**split;
    int		i;
    int		j;
    
    i = 0;
    j = 0;
    if (!(split = (char **)malloc(sizeof(char *) * (count_words(str) + 1))))
        return (NULL);
    while (str && str[i])
    {
        while (*str && (*str == ' ' || *str == '\t'))
            str++;
        if (*str)
        {
            while (str[i] && str[i] != ' ' && str[i] != '\t')
                i++;
            split[j] = ft_strndup(str, i);
            j++;
            str += i;
            i = 0;
        }
    }
    split[j] = NULL;
    return (split);
}
