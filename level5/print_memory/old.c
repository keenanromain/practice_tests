#include <unistd.h>

static void		ft_putnbr_hex(int octet, int rem)
{
	char const *base = "0123456789abcdef";

	if (rem > 1)
		ft_putnbr_hex(octet >> 4, rem - 1);
	write(1, base + (octet % 16), 1);
}

static void		sp_putchar(unsigned char const *ptr)
{
	char const c = *ptr;

	if (' ' <= c && c <= '~')
		write(1, ptr, 1);
	else
		write(1, ".", 1);
}

static void		print_number(const unsigned char *addr,
		size_t size, size_t i)
{
	int a;

	a = 0;
	while (a < 16 && a + i < size)
	{
		ft_putnbr_hex(*(addr + i + a), 2);
		if (a % 2)
			write(1, " ", 1);
		a++;
	}
	while (a < 16)
	{
		write(1, "  ", 2);
		if (a % 2)
			write(1, " ", 1);
		a++;
	}
}

static void		print_characters(const unsigned char *addr,
		size_t size, size_t i)
{
	int a;

	a = 0;
	while (a < 16 && a + i < size)
	{
		sp_putchar(addr + a + i);
		a++;
	}
}

void			print_memory(const void *addr, size_t size)
{
	size_t i;

	i = 0;
	while (i < size)
	{
		print_number((const unsigned char *)addr, size, i);
		print_characters((const unsigned char *)addr, size, i);
		write(1, "\n", 1);
		i += 16;
	}
}

int		main(void)
{
	int tab[10] = {0, 23, 150, 255, 12, 16, 21, 42};
	print_memory(tab, sizeof(tab));
	return (0);
}
