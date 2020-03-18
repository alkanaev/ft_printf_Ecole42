#include "ft_printf.h"

static unsigned int		len_num(unsigned int num)
{
	unsigned int		len;

	len = 1;
	while (num >= 10)
	{
		num /= 10;
		len++;
	}
	return (len);
}

static int				u_precision(t_flags flags, int num)
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
	while (to_print-- > 0)
	{
		res++;
		write(1, "0", 1);
	}
	if (!(num == 0))
		ft_putnbr_u(num);
	return (res);
}

static int				u_width(t_flags flags, int num)
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
	if (flags.minus == 1)
		ft_putnbr_u(num);
	while (to_print-- > 0)
		write(1, &width_char, 1);
	if (flags.minus == 0)
		ft_putnbr_u(num);
	if (flags.width < len)
		return (len);
	return (res);
}

static int				u_wid_pr(t_flags flags, int num, int len)
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
		ft_putnbr_u(num);
	if (flags.minus == 1)
	{
		while (wid-- > 0)
			write(1, " ", 1);
	}
	return (res);
}

int						print_case_u(va_list factor, t_flags flags)
{
	int		num;
	int		res;

	res = 0;
	num = va_arg(factor, int);
	if (flags.width > 0 && flags.dot == 0)
		res = u_width(flags, num);
	else if (flags.width == 0 && flags.dot == 1)
		res = u_precision(flags, num);
	else if (flags.width > 0 && flags.dot == 1)
		res = u_wid_pr(flags, num, len_num(num));
	else
	{
		ft_putnbr_u(num);
		return (len_num(num));
	}
	return (res);
}