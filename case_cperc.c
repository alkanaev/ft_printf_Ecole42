#include "ft_printf.h"

static int		width_flags(t_flags flags, char c)
{
	int		i;

	i = 0;
	while (i++ < (flags.width - 1))
		write(1, &c, 1);
	return (i - 1);
}

int				print_case_c(va_list factor, t_flags flags)
{
	char	c;
	char	zero;
	int		i;

	zero = ' ';
	if (flags.zero == 1 && flags.minus == 0)
		zero = '0';
	i = 0;
	if (flags.width > 0 && flags.minus == 0)
		i += width_flags(flags, zero);
	c = va_arg(factor, int);
	write(1, &c, 1);
	if (flags.minus > 0)
		i += width_flags(flags, zero);
	return (1 + i);
}

int				print_case_proc(t_flags flags)
{
	char	zero;
	int		i;

	zero = ' ';
	if (flags.zero == 1 && flags.minus == 0)
		zero = '0';
	i = 0;
	if (flags.width > 0 && flags.minus == 0)
		i = width_flags(flags, zero);
	write(1, "%", 1);
	if (flags.minus > 0)
		i = width_flags(flags, zero);
	return (1 + i);
}