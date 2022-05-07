#include "ft_printf.h"
#include <stdio.h>

//gcc -o test.a main.c -L. -l ftprintf

static int	diverge_by_FS(va_list ap, int *res, const char *str)
{
	if (*str == 'c') // single character
		*res += ft_write_c(ap);
	else if (*str == 's') // string
		*res += ft_write_s(ap);
	else if (*str == 'p') // void * pointer has to be printed in hex
		*res += ft_write_p(ap);
	else if (*str == 'd') // decimal
		*res += ft_write_d(ap);
	else if (*str == 'i') // interger in base 10
		*res += ft_write_i(ap);
	else if (*str == 'u') // unsigned decimal in base 10
		*res += ft_write_u(ap);
	else if (*str == 'x') // hex in base 16 lowercase
		*res += ft_write_lowerx(ap);
	else if (*str == 'X') // " uppercase
		*res += ft_write_upperX(ap);
	else if (*str == '\%') // percent sign
		*res += ft_write_per(ap);
	else
		return (1);
	return (0);
}

static unsigned int	count_per(const char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] == '\%')
		i++;
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list			ap;
	unsigned int	i;
	int				res;
	unsigned int	count;

	i = 0;
	res = 0;
	va_start(ap, str);
	while (str[i])
	{
		while (str[i] != '\%')
		{
			ft_putchar_fd(str[i], 1);
			res++;
			i++;
			if (str[i] == '\0')
				return (res);
		}
		if ((count_per(&str[i]) % 2) == 0) //printf 작동 X
		{
			count = (count_per(&str[i]) / 2);
			while (count)
			{
				i += 2;
				ft_putchar_fd('\%', 1);
				res++;
				count--;
			}
		}
		else //printf 작동 O
		{
			while (str[i] == '\%' && str[i + 1] == '\%')
			{
				ft_putchar_fd(str[i], 1);
				res++;
				i++;
			} //마지막 %에서 빠져나옴
			i++;
			diverge_by_FS(ap, &res, &str[i++]);
		}
	}
	return (res);
}
