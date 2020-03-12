#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

typedef struct		s_flags
{
	int				zero;
	int				minus;
	int				dot;
	int				width;
	int				precision;
}					t_flags;

int					ft_printf(const char *s, ...);
int					convert_flags(int *i, va_list factor, char *s);
//int					check_wid_prec(const char *str, int *i, va_list factors, t_flags *flags);
int					print_case_proc(t_flags flags);
//int					ft_isdigit(int c);
int					print_case_c(va_list factor, t_flags flags);
int					print_case_s(va_list factor, t_flags flags);
int					print_case_di(va_list factor, t_flags flags);
int					print_case_u(va_list factor, t_flags flags);
int					print_case_lhex(va_list factor, t_flags flags);
int					print_case_uhex(va_list factor, t_flags flags);
int					print_case_p(va_list factor, t_flags flags);
//size_t				ft_strlen(const char *s);
int					ft_strlen(char *s);
void				ft_putnbr(long num);
void				ft_putnbr_u(unsigned int num);
int 				cnt_lu_hex(unsigned long num);
void				ft_print_lhex_p(unsigned long num);
void				ft_print_lhex(unsigned int num);
void				ft_print_uhex(unsigned int num);

#endif