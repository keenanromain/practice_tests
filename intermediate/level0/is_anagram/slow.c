int		ft_strlen(char *s)
{
	int i;

	i = -1;
	while (s[++i])
		;
	return (i);
}

int		cant_find_a_in_b(char a, char *b)
{
	int i;

	i = -1;
	while (b[++i])
		if (a == b[i] && (b[i] = 9))
			return (0);
	return (1);
}

int		is_anagram(char *a, char *b)
{
	int i;

	if (ft_strlen(a) != ft_strlen(b))
		return (0);
	i = -1;
	while (a[++i])
		if (cant_find_a_in_b(a[i], b))
			return (0);
	return (1);
}
