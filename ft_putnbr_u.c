#include "ft_printf.h"

void				ft_putnbr_u(unsigned int num)
{
	char	tmp;

	if (num >= 10)
		ft_putnbr_u(num / 10);
	tmp = '0' + num % 10;
	write(1, &tmp, 1);
}