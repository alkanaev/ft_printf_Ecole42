NAME		= libftprintf.a

HEADER		= ft_printf.h

CC			= gcc

SRCS		= ft_printf.c \
				conversion.c \
				ft_strlen.c \
				case_di.c \
				case_u.c \
				case_cperc.c \
				case_s.c \
				case_p.c \
				case_lhex.c \
				case_uhex.c \
				ft_putnbr_u.c \
				ft_putnbr.c \
				cnt_hex_lup.c

OBJS		= $(SRCS:%.c=%.o)

RM			= rm -f
CFLAGS		= -Wall -Werror -Wextra -I. -c

%.c%.o:		@gcc -g ${CFLAGS} -c ${SRCS} -include ${HEADER} -o $@ -c $<

$(NAME):	${OBJS}
		ar rc ${NAME} ${OBJS}
		ranlib ${NAME}

all:		${NAME}

clean:		
			${RM} ${OBJS} ${OBJS_BONUS}

fclean:		clean
			${RM} ${NAME}

re:		fclean all

.PHONY:		all re clean fclean