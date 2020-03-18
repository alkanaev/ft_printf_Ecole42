#include "ft_printf.h"

static int				cnt_hex_p(unsigned long num)
{
	int	res;

	res = 1;
	while (num >= 16)
	{
		num = num / 16;
		res += 1;
	}
	return (res + 2);
}

static int				p_precision(t_flags flags, unsigned long num)
{
	int		len;
	int		res;
	int		to_print;

	len = (num == 0 ? 2 : cnt_hex_p(num));
	to_print = num == 0 ? flags.precision - 1 : flags.precision - len;
	res = len < flags.precision ? flags.precision : len;
	res += num == 0 ? 2 : 0;
	if (flags.precision == 0 && num == 0)
	{
		write(1, "0x", 2);
		return (2);
	}
	//if (num == 0)
	write(1, "0x", 2);
	while (to_print-- > 0)
		write(1, "0", 1);
	ft_print_lhex_p(num);
	return (res);
}

static int				p_width(t_flags flags, unsigned long num)
{
	int		len;
	int		res;
	int		to_print;
	char	width_char;

	width_char = ' ';
	if (flags.zero == 1 && flags.minus == 0)
		width_char = '0';
	len = cnt_hex_p(num);
	to_print = flags.width - len;
	res = to_print + len;
	while (flags.minus == 0 && to_print-- > 0)
		write(1, &width_char, 1);
	write(1, "0x", 2);
	ft_print_lhex_p(num);
	while (flags.minus == 1 && to_print-- > 0)
		write(1, &width_char, 1);
	if (flags.width < len)
		return (len);
	return (res);
}

static int				p_wid_pr(t_flags flags, unsigned long num, int len)
{
	int		res;
	int		pre;
	int		wid;

	if ((flags.precision == 0 && num == 0))
		len = 2;
	pre = flags.precision - len > 0 ? flags.precision - len : 0;
	pre += flags.precision > len ? 2 : 0;
	wid = flags.width - (len + pre) > 0 ? flags.width - (len + pre) : 0;
	res = pre + wid + len;
	while (flags.minus == 0 && wid-- > 0)
		write(1, " ", 1);
	write(1, "0x", 2);
	while (pre-- > 0)
		write(1, "0", 1);
	if (!(flags.precision == 0 && num == 0))
		ft_print_lhex_p(num);
	while (flags.minus == 1 && wid-- > 0)
		write(1, " ", 1);
	return (res);
}

int						print_case_p(va_list factor, t_flags flags)
{
	unsigned long	num;
	int				res;

	res = 0;
	num = va_arg(factor, unsigned long);
	if (flags.width > 0 && flags.dot == 0)
		res = p_width(flags, num);
	else if (flags.width == 0 && flags.dot == 1)
		res = p_precision(flags, num);
	else if (flags.width > 0 && flags.dot == 1)
		res = p_wid_pr(flags, num, cnt_hex_p(num));
	else
	{
		write(1, "0x", 2);
		ft_print_lhex_p(num);
		return (cnt_hex_p(num));
	}
	return (res);
}