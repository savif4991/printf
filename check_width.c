#include "ft_printf.h"

int	check_width(const char *str, va_list ap)
{
	int	res;

	if (*str >= '0' && *str <= '9')
		res = ft_atoi(str);
	else if (*str == '*')
		res = va_arg(ap, int);
	else
		res = -1;
	return (res);
}
