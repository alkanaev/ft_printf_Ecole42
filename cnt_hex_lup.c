#include "ft_printf.h"

void			ft_print_lhex_p(unsigned long num)
{
	char			*hexa_base;

	hexa_base = "0123456789abcdef";
	if (num >= 16)
		ft_print_lhex(num / 16);
	write(1, &hexa_base[num % 16], 1);
}

void			ft_print_lhex(unsigned int num)
{
	char			*hexa_base;

	hexa_base = "0123456789abcdef";
	if (num >= 16)
		ft_print_lhex(num / 16);
	write(1, &hexa_base[num % 16], 1);
}

void			ft_print_uhex(unsigned int num)
{
	char			*hexa_base;

	hexa_base = "0123456789ABCDEF";
	if (num >= 16)
		ft_print_uhex(num / 16);
	write(1, &hexa_base[num % 16], 1);
}

int cnt_lu_hex(unsigned long num)
{
	int	h;

	h = 1;
	while (num >= 16)
	{
		num = num / 16;
		h += 1;
	}
	return (h);
}