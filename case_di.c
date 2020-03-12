#include "ft_printf.h"

static int				len_num(int num)
{
	int		len;

	len = 1;
	if (num < 0)
	{
		len++;
		if (num == -2147483648)
			return (11);
		else
			num *= -1;
	}
	while (num >= 10)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

static int				di_precision(t_flags flags, int num)
{
	int		len;
	int		res;
	int		to_print;

	len = len_num(num);
	to_print = num > 0 ? flags.precision - len : flags.precision - (len - 1);
	if (num == 0)
		len = 0;
	res = len;
	if (flags.precision == 0 && num == 0)
		return (0);
	if (num < 0)
		write(1, "-", 1);
	while (to_print-- > 0)
	{
		res++;
		write(1, "0", 1);
	}
	if (!(num == 0))
		ft_putnbr(num);
	return (res);
}

static int				di_width(t_flags flags, int num)
{
	int		len;
	int		res;
	int		to_print;
	char	width_char;

	width_char = ' ';
	if (flags.zero == 1 && flags.minus == 0)
		width_char = '0';
	len = len_num(num);
	to_print = flags.width - len;
	res = to_print + len;
	if (num < 0 && flags.zero == 1)
		write(1, "-", 1);
	while (flags.minus == 0 && to_print-- > 0)
		write(1, &width_char, 1);
	if (num < 0 && flags.zero == 0)
		write(1, "-", 1);
	ft_putnbr(num);
	while (flags.minus == 1 && to_print-- > 0)
		write(1, &width_char, 1);
	if (flags.width < len)
		return (len);
	return (res);
}

static int				di_prewidth(t_flags flags, int num, int len)
{
	int		res;
	int		pre;
	int		wid;

	pre = num > 0 ? flags.precision - len : flags.precision - (len - 1);
	pre = flags.precision - len >= 0 ? pre : 0;
	wid = flags.width - (len + pre) > 0 ? flags.width - (len + pre) : 0;
	res = pre + wid + len;
	if (num == 0)
		wid += 1;
	while (flags.minus == 0 && wid-- > 0)
		write(1, " ", 1);
	if (num < 0)
		write(1, "-", 1);
	while (pre-- > 0)
		write(1, "0", 1);
	if (!(num == 0))
		ft_putnbr(num);
	while (flags.minus == 1 && wid-- > 0)
		write(1, " ", 1);
	return (res);
}

int						print_case_di(va_list factor, t_flags flags)
{
	int		num;
	int		res;

	res = 0;
	num = va_arg(factor, int);
	if (flags.width > 0 && flags.dot == 0)
		res = di_width(flags, num);
	else if (flags.width == 0 && flags.dot == 1)
		res = di_precision(flags, num);
	else if (flags.width > 0 && flags.dot == 1)
		res = di_prewidth(flags, num, len_num(num));
	else
	{
		if (num < 0)
			write(1, "-", 1);
		ft_putnbr(num);
		return (len_num(num));
	}
	return (res);
}