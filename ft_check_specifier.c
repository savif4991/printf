#include "ft_printf.h"

char	*check_specifier(va_list ap, const char *str)
{
	char	*res;

	if (*str == 'c')
		res = ft_write_c(ap);
	else if (*str == 's')
		res = ft_write_s(ap);
	else if (*str == 'p')
		res = ft_write_p(ap);
	else if (*str == 'd')
		res = ft_write_d(ap);
	else if (*str == 'i')
		res = ft_write_i(ap);
	else if (*str == 'u')
		res = ft_write_u(ap);
	else if (*str == 'x')
		res = ft_write_lowerx(ap);
	else if (*str == 'X')
		res = ft_write_upperX(ap);
	else if (*str == '\%')
		res = ft_write_per(ap);
	else
		return (0);
	return (res);
}