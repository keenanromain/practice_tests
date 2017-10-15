#include <stdio.h>

typedef struct	s_alpha
{
	int		num[26];
	char	let[26];
}				t_alpha;

char		*downcase(char *s)
{
	int i;

	i = -1;
	while (s[++i])
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] += 32;
	return (s);
}

void			init(t_alpha *a)
{
	int i;

	i = -1;
	while (++i < 26)
	{
		a->num[i] = 0;
		a->let[i] = 0;
	}
}

int				found_first(char c, t_alpha *a, int j)
{
	int	i;

	i = -1;
	while (++i < 26)
		if (a->let[i] == c && a->num[i]++)
			return (0);
	a->let[j] = c;
	a->num[j]++;
	return (1);
}

void		count_alpha(char *s)
{
	int		i;
	t_alpha	a;
	int		j;
	int		space;

	init(&a);
	i = -1;
	j = 0;
	while (s[++i])
		if (s[i] >= 'a' && s[i] <= 'z')
			if (found_first(s[i], &a, j))
				j++;
	space = 0;
	i = -1;
	while (++i < 26)
	{
		if (a.num[i] > 0)
		{
			if (space)
				printf(", ");
			printf("%d%c", a.num[i], a.let[i]);
			space = 1;
		}
	}
}

int			main(int ac, char **av)
{
		if (ac == 2)
			count_alpha(downcase(av[1]));
		printf("\n");
		return (0);
}
