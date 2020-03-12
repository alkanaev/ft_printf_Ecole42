#include "ft_printf.h"

int				ft_printf(const char *s, ...)
{
	va_list		factor;
	int			res;
	int			i;

	res = 0;
	i = 0;
	va_start(factor, s);
	while (s[i])
	{
		if (s[i] == '%')
			res += convert_flags(&i, factor, (char*)s);
		else
		{
			write(1, &s[i], 1);
			res++;
			i++;
		}
	}
	va_end(factor);
	return (res);
}