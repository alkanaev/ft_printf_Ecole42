#include "ft_printf.h"

void				ft_putnbr(long num)
{
	char	tmp;

	if (num < 0)
	{
		num = num * -1;
	}
	if (num >= 10)
		ft_putnbr(num / 10);
	tmp = '0' + num % 10;
	write(1, &tmp, 1);
}