#include <unistd.h>

void	print_memchar(const unsigned char *ptr)
{
	*ptr >= 32 && *ptr <= 126 ? write(1, ptr, 1) : write(1, ".", 1);
}
void	print_char(const unsigned char *addr, size_t i, size_t size)
{
	size_t j;

	j = 0;
	while (j < 16 && (j + i) < size)
	{
		print_memchar(addr + j + i);
		j++;
	}
}

void	print_memnum(int octet, int num)
{
	const char *base = "0123456789abcdef";

	if (num > 1)
		print_memnum(octet >> 4, num - 1);
	write(1, base + (octet % 16), 1);
}

void	print_num(const unsigned char *addr,size_t i, size_t size)
{
	size_t j;

	j = 0;
	while (j < 16 && (j + i) < size)
	{
		print_memnum(*(addr + j + i), 2);
		if (j % 2)
			write(1, " ", 1);
		j++;
	}
	while (j < 16)
	{
		write(1, "  ", 2);
		if (j % 2)
			write(1, " ", 1);
		j++;
	}
}

void	print_memory(const void *addr, size_t size)
{
	size_t i;

	i = 0;
	while (i < size)
	{
		print_num((const unsigned char *)addr, i, size);
		print_char((const unsigned char *)addr, i, size);
		write(1, "\n", 1);
		i+= 16;
	}
}

int		main(void)
{
	int tab[10] = {0, 23, 150, 255, 12, 16, 21, 42};
	print_memory(tab, sizeof(tab));
}
