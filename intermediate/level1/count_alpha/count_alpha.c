#include <unistd.h>
#include <stdio.h>

char	*ft_downcase(char *s)
{
	int i;

	i = -1;
	while (s[++i])
		if (s[i] >= 65 && s[i] <= 90)
			s[i] += 32;
	return (s);
}

void	count_alpha(char *s)
{
	int letters[26];
	int i;
	char *alphabet;
	int space;

	i = -1;
	while (++i < 26)
		letters[i] = 0;
	i = -1;
	while (s[++i])
	{
		if (s[i] == 'a')
			letters[0] += 1;
		else if (s[i] == 'b')
			letters[1] += 1;
		else if (s[i] == 'c')
			letters[2] += 1;
		else if (s[i] == 'd')
			letters[3] += 1;
		else if (s[i] == 'e')
			letters[4] += 1;
		else if (s[i] == 'f')
			letters[5] += 1;
		else if (s[i] == 'g')
			letters[6] += 1;
		else if (s[i] == 'h')
			letters[7] += 1;
		else if (s[i] == 'i')
			letters[8] += 1;
		else if (s[i] == 'j')
			letters[9] += 1;
		else if (s[i] == 'k')
			letters[10] += 1;
		else if (s[i] == 'l')
			letters[11] += 1;
		else if (s[i] == 'm')
			letters[12] += 1;
		else if (s[i] == 'n')
			letters[13] += 1;
		else if (s[i] == 'o')
			letters[14] += 1;
		else if (s[i] == 'p')
			letters[15] += 1;
		else if (s[i] == 'q')
			letters[16] += 1;
		else if (s[i] == 'r')
			letters[17] += 1;
		else if (s[i] == 's')
			letters[18] += 1;
		else if (s[i] == 't')
			letters[19] += 1;
		else if (s[i] == 'u')
			letters[20] += 1;
		else if (s[i] == 'v')
			letters[21] += 1;
		else if (s[i] == 'w')
			letters[22] += 1;
		else if (s[i] == 'x')
			letters[23] += 1;
		else if (s[i] == 'y')
			letters[24] += 1;
		else if (s[i] == 'z')
			letters[25] += 1;
	}
	alphabet = "abcdefghijklmnopqrstuvwxyz\0";
	space = 0;
	i = -1;
	while (++i < 26)
	{
		if (letters[i] && alphabet[i])
		{
			if (space)
				printf(", ");
			printf("%d%c", letters[i], alphabet[i]);
			space = 1;
		}
	}
	printf("\n");
}

int		main(int ac, char **av)
{
	if (ac == 2)
		count_alpha(ft_downcase(av[1]));
	else
		write (1, "\n", 1);
}
