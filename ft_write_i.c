#include "./ft_printf.h"

char	*ft_write_i(va_list ap)
{
	char	*str;
	int		val;

	val = va_arg(ap, int);
	str = ft_itoa(val);
	if (str == 0)
		return (0);
	return (str);
}
