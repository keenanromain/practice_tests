#include <unistd.h>

int		mem_putchar(const unsigned char *ptr)
{
	return (*ptr >= 32 && *ptr <= 126 ? write(1, ptr, 1) : write(1, ".", 1));
}

void	print_char(const unsigned char *addr, size_t size, size_t i)
{
	size_t j;

	j = 0;
	while (j < 16 && j + i < size)
	{
		mem_putchar(addr + j + i);
		j++;
	}
}

void	mem_putnbr(int octet, int remain)
{
	const char *refer = "0123456789abcdef";

	if (remain > 1)
		mem_putnbr(octet>>4, remain - 1);
	write(1, refer + (octet % 16), 1);
}

void	print_num(const unsigned char *addr, size_t size, size_t i)
{
	size_t j;

	j = 0;
	while (j < 16 && j + i < size)
	{
		mem_putnbr(*(addr + j + i), 2);
		if (j % 2 == 1)
			write(1," ", 1);
		j++;
	}
	while (j < 16)
	{
		write(1, "  ", 2);
		if (j % 2 == 1)
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
		print_num((const unsigned char *)addr, size, i);
		print_char((const unsigned char *)addr,size, i);
		write(1, "\n", 1);
		i += 16;
	}
}

int		main(void)
{
	int tab[10] = {0, 23, 150, 255, 12, 16, 21, 42};
	print_memory(tab, sizeof(tab));
}
