#include <unistd.h>

void	mem_char(const unsigned char *s)
{
	*s >= 32 && *s <= 126 ? write(1, s, 1) : write(1, ".", 1);
}

void	print_char(const unsigned char *s, size_t j, size_t size)
{
	size_t i;

	i = 0;
	while (i < 16 && (j + i) < size)
	{
		mem_char(s + i + j);
		i++;
	}
}

void	mem_num(int octet, int num)
{
	char *base = "0123456789abcdef";

	if (num > 1)
		mem_num(octet >> 4, --num);
	write(1, base + (octet % 16), 1);
}

void	print_num(const unsigned char *s, size_t j, size_t size)
{
	size_t i;

	i = 0;
	while (i < 16 && (j + i) < size)
	{
		mem_num(*(s + i + j), 2);
		if (i % 2)
			write(1, " ", 1);
		i++;
	}
	while (i < 16)
	{
		write(1, "  ", 2);
		if (i % 2)
			write(1, " ", 1);
		i++;
	}
}

void	print_memory(const void *addr, size_t size)
{
	size_t j;

	j = 0;
	while (j < size)
	{
		print_num((const unsigned char *)addr, j, size);
		print_char((const unsigned char *)addr, j, size);
		write(1, "\n", 1);
		j += 16;
	}
}

int		main(void)
{
	int tab[10] = {0, 23, 150, 255, 12, 16, 21 ,42};
	print_memory(tab, sizeof(tab));
	return (0);
}
