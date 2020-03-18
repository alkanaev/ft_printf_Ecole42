#include "ft_printf.h"

static int			ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int			check_wid_prec(const char *str, int *i, va_list factors, t_flags *flags)
{
	int		res;

	res = 0;
	if (str[*i] == '*')
	{
		res = va_arg(factors, int);
		if (res < 0 && str[*i-1] == '.')
			flags->dot = 0;
		if (res < 0 && str[*i-1] != '.')
		{
			res = res * -1;
			flags->minus = 1;
		}
	}
	else
	{
		while (str[*i] >= '0' && str[*i] <= '9')
		{
			res = res * 10 + str[*i] - '0';
			(*i)++;
		}
		(*i)--;
	}
	return (res);
}

static int		check_cases(char c)
{
	if (c == 'c' || c == 's' || c == 'd' ||
		c == 'i' || c == 'u' || c == 'x' ||
		c == 'X' || c == 'p' || c == '%')
		return (1);
	return (0);
}

static t_flags	active_flags(char *s, int i, va_list factor)
{
	t_flags flags;

	flags.zero = 0;
	flags.dot = 0;
	flags.width = 0;
	flags.minus = 0;
	while (s[i] && !(check_cases(s[i])))
	{
		if (s[i] == '0')
			flags.zero = 1;
		else if ((ft_isdigit(s[i]) || s[i] == '*'))
			flags.width = check_wid_prec(s, &i, factor, &flags);
		else if (s[i] == '-')
			flags.minus = 1;
		else if (s[i] == '.')
		{
			i++;
			flags.dot = 1;
			flags.precision = check_wid_prec(s, &i, factor, &flags);
		}
		i++;
	}
	return (flags);
}

int		convert_flags(int *i, va_list factor, char *s)
{
	int			res;
	t_flags		flags;

	res = 0;
	(*i)++;
	flags = active_flags(s, *i, factor);
	while (!(check_cases(s[*i])) && s[*i])
		(*i)++;
	if (s[*i] == 'c')
		res = print_case_c(factor, flags);
	if (s[*i] == 's')
		res = print_case_s(factor, flags);
	if (s[*i] == 'p')
		res = print_case_p(factor, flags);
	if (s[*i] == 'd' || s[*i] == 'i')
		res = print_case_di(factor, flags);
	if (s[*i] == 'u')
		res = print_case_u(factor, flags);
	if (s[*i] == 'x' || s[*i] == 'X')
		res = s[*i] == 'x' ? print_case_lhex(factor, flags) : print_case_uhex(factor, flags);
	if (s[*i] == '%')
		res = print_case_proc(flags);
	if (s[*i])
		(*i)++;
	return (res);
}