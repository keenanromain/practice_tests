#include <unistd.h>
#include <stdlib.h>

int		count_spaces(char *s)
{
	int i;
	int ret;

	i = -1;
	ret = 0;
	while (s[++i])
		if (s[i] == 32)
			ret++;
	return (ret);
}

void	ft_putstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

int		ft_strlen(char *s)
{
	int i = -1;
	while (s[++i])
		;
	return (i);
}

char	*ft_strjoinnewline(char *s1, char *s2)
{
	int i;
	char *str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	// each +1 below is for the new line and null terminator respectively
	str = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1 + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	while (*s1)
		str[++i] = *s1++;
	str[++i] = '\n';
	while (*s2)
		str[++i] = *s2++;
	str[++i] = '\0';
	return (str);
}

void	fix_up(char **tab, char *s, int n)
{
	do_length(&tab, s, n);
	do_alpha(&tab, s, n);
	int i;
	char *ret;

	i = 0;
	ret = tab[i];
	while (++i < n)
		ret = ft_strjoinnewline(ret, tab[i]);
	ft_putstr(ret);
}

void	ord_alphlong(char *s)
{ //splits string into array of strings
	char **tab;
	int i;
	int j;
	int num_of_words;
	char *tmp;

	num_of_words = count_spaces(s) + 1;
	tab = (char **)malloc(sizeof(char **) * num_of_words);
	i = -1;
	j = 0;
	while (++i < num_of_words)
	{
		while (s[j] && s[j] != ' ')
			++j;
		tab[i] = (char *)malloc(sizeof(char) * j + 1);
		while (s[j] && s[j] == ' ')
			j++;
	}
	i = -1;
	j = -1;
	while (++i < num_of_words)
	{
		while (s[++j] && s[j] != ' ')
			tab[i][j] = s[j];
		tab[i][j] = '\0';
		while (s[j] && s[j] == ' ')
			j++;
	}
	fix_up(tab, s, num_of_words);
}

char	*only_spaces(char *s)
{ //converts tabs to spaces
	int i;

	i = -1;
	while (s[++i])
		if (s[i] == 9)
			s[i] = 32;
	return (s);
}

int		main(int ac, char **av)
{
	if (ac == 2 && av[1])
		ord_alphlong(only_spaces(av[1])); //convert all tabs to spaces before proceeding
	write(1, "\n", 1);
	return (0);
}

/* 
 * 1. takes one string as parameter
 * 2. print it's words sorted by length FIRST then in alphabetical order then order by appearing in string
 * 3. Ignore case for alphabetical order (aA & Aa are the same, but aA goes first cuz it showed up first)
 * 4. Duplicates remain
 * 5. only spaces, tabs, and alphanumeric characters in string
 * */
