#include "ft_printf.h"

int main(void)
{   
    int a = 10 ;
	int *p = &a ;

    printf("%d", ft_printf("{%-.12u}\n", -20));
    printf("\n");
    printf("%d", printf("{%-.12u}\n", -20));

    //printf("%d", ft_printf("-->|%-4.x|<--\n", -11));
    //printf("\n");
    //printf("%d", printf("-->|%-4.x|<--\n", -11));



	//ft_printf("d - check zero:[%06d] \t i:[%06i]\n", 28, -70);
	//ft_printf("u-pos:[%u]\n", 445);
	//ft_printf("u-neg:[%u]\n", -445);
    //ft_printf("s - check minus:[%-7s]\n", "Lo");
    //ft_printf("x - check dot: [%10.5x]\n", 11);
    //ft_printf("X: [%X]\n", 11);
    //ft_printf("p:[%-10p]\n", ptr);
	//ft_printf("[%-*c]\n", 15, '5');
	//ft_printf("ft proc - check star: [%*%]\n", 3);
	//ft_printf("my proc: [%%b]\n");


    //printf("\n");
    //ft_printf("%-*.2s> hello >%4.6d\n", 10, "Hello", 5);
    //printf("%-*.2s> hello >%4.6d\n", 10, "Hello", 5);
    //printf("\n");


    //printf("d - check zero:[%06d] \t i:[%06i]\n", 28, -70);
	//printf("u-pos:[%u]\n", 445);
	//printf("u-neg:[%u]\n", -445);
    //printf("s - check minus:[%-7s]\n", "Lo");
    //printf("x - check dot: [%10.5x]\n", 11);
    //printf("X: [%X]\n", 11);
    //printf("p:[%-10p]\n", ptr);
	//printf("[%-*c]\n", 15, '5');
	//printf("rl proc - check star: [%*%]\n", 3);
	//printf("real proc: [%%b]\n");
    return 0;
}
