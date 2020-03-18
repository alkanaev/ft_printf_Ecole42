#include "ft_printf.h"

static int		s_width(t_flags flags, int size)
{
	char	zero;
	int		res;

	res = 0;
	zero = ' ';
	if (flags.zero == 1 && flags.minus == 0)
		zero = '0';
	while (size++ < flags.width)
	{
		write(1, &zero, 1);
		res++;
	}
	return (res);
}

static int		s_precision(t_flags flags, char *s)
{
	int		i;

	i = 0;
	if (flags.dot == 1 && ft_strlen(s) > flags.precision)
	{
		while (i < flags.precision)
			i++;
	}
	else
	{
		if (s)
		{
			while (s[i])
				i++;
		}
	}
	write(1, s, i);
	return (i);
}

int				print_case_s(va_list factor, t_flags flags)
{
	char	*s;
	int		i;
	int		size_s;
	int		res;

	res = 0;
	i = 0;
	s = va_arg(factor, char*);
	if (s == NULL)
		s = "(null)";
	size_s = ft_strlen(s);
	if (flags.dot == 1 && size_s > flags.precision)
	{
		if (flags.precision < size_s)
			size_s = flags.precision;
	}
	if (flags.width > 0 && flags.minus == 0)
		res = s_width(flags, size_s);
	i = s_precision(flags, s);
	if (flags.minus == 1)
		res = s_width(flags, size_s);
	return (i + res);
}