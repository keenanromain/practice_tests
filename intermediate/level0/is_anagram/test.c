int		ft_strlen(char *s)
{
	int i;

	i = -1;
	while (s[++i])
		;
	return (i);
}

int		a_in_b(char c, char *s)
{
	int i;

	i = -1;
	while (s[++i])
		if (s[i] == c && (s[i] = 9))
			return (1);
	return (0);
}

int		is_anagram(char *a, char *b)
{
	if (ft_strlen(a) != ft_strlen(b))
		return (0);
	int i;

	i = -1;
	while (a[++i])
		if (!a_in_b(a[i], b))
			return (0);
	return (1);
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char*ft_strdup(char *str)
{
	char *new = (char *)malloc(strlen(str) + 1);
	new = strcpy(new, str);
	return (new);
}

int main()
{
	char *s1;
	char *s2;

	s1 = ft_strdup("abcdef");
	s2 = ft_strdup("fabcde");
	printf("Output: %d, answer: %d\n", is_anagram(s1, s2), 1);
	s1 = ft_strdup("basiparachromatin");
	s2 = ft_strdup("marsipobranchiata");
	printf("Output: %d, answer: %d\n", is_anagram(s1, s2), 1);
	s1 = ft_strdup("abca");
	s2 = ft_strdup("bcab");
	printf("Output: %d, answer: %d\n", is_anagram(s1, s2), 0);
	return (0);
}

