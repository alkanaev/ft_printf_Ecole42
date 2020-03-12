#include "ft_printf.h"

static int				uhex_precision(t_flags flags, unsigned long num)
{
	int		len;
	int		res;
	int		to_print;

	len = cnt_lu_hex(num);
	to_print = flags.precision - len;
	res = len < flags.precision ? flags.precision : len;
	if (flags.precision == 0 && num == 0)
		return (0);
	while (to_print-- > 0)
		write(1, "0", 1);
	ft_print_uhex(num);
	return (res);
}

static int				uhex_width(t_flags flags, unsigned long num)
{
	int		len;
	int		res;
	int		to_print;
	char	width_char;

	width_char = ' ';
	if (flags.zero == 1 && flags.minus == 0)
		width_char = '0';
	len = cnt_lu_hex(num);
	to_print = flags.width - len;
	res = to_print + len;
	if (flags.minus == 1)
		ft_print_uhex(num);
	while (to_print-- > 0)
		write(1, &width_char, 1);
	if (flags.minus == 0)
		ft_print_uhex(num);
	if (flags.width < len)
		return (len);
	return (res);
}

static int				uhex_wid_pr(t_flags flags, unsigned long num, int len)
{
	int		res;
	int		pre;
	int		wid;

	pre = flags.precision - len > 0 ? flags.precision - len : 0;
	wid = flags.width - (len + pre) > 0 ? flags.width - (len + pre) : 0;
	res = pre + wid + len;
	if (flags.precision == 0 && num == 0)
		wid += 1;
	if (flags.minus == 0)
	{
		while (wid-- > 0)
			write(1, " ", 1);
	}
	while (pre-- > 0)
		write(1, "0", 1);
	if (!(flags.precision == 0 && num == 0))
		ft_print_uhex(num);
	if (flags.minus == 1)
	{
		while (wid-- > 0)
			write(1, " ", 1);
	}
	return (res);
}

int						print_case_uhex(va_list factor, t_flags flags)
{
	int		num;
	int		res;

	res = 0;
	num = (unsigned long)va_arg(factor, unsigned long);
	if (flags.width > 0 && flags.dot == 0)
		res = uhex_width(flags, num);
	else if (flags.width == 0 && flags.dot == 1)
		res = uhex_precision(flags, num);
	else if (flags.width > 0 && flags.dot == 1)
		res = uhex_wid_pr(flags, num, cnt_lu_hex(num));
	else
	{
		ft_print_uhex(num);
		return (cnt_lu_hex(num));
	}
	return (res);
}