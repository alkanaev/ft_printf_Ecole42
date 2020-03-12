cmake_minimum_required(VERSION 3.15)
project(ft_printf_detailed C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(ft_printf_detailed
        case_cperc.c
        case_di.c
        case_lhex.c
        case_p.c
        case_s.c
        case_u.c
        case_uhex.c
        cnt_hex_lup.c
        ft_printf.c
        ft_printf.h
        ft_putnbr.c
        ft_putnbr_u.c
        ft_strlen.c
        main.c)
