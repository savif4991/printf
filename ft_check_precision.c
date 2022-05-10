#include "ft_printf.h"

int	check_precision(const char *str, va_list ap)
{
	unsigned int	i;
	int				res;

	i = 0;
	if (str[i] == '.')
	{
		if (str[1] >= '0' && str[1] <= '9')
			res = ft_atoi(&str[1]);
		else if (str[1] == '*')
			res = va_arg(ap, int);
		else
			res = -1;
	}
	else
		res = -1;
	return (res);
}
