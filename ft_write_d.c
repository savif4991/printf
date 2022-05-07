#include "./ft_printf.h"

int	ft_write_d(va_list ap)
{
	char	*str;
	int		val;

	val = va_arg(ap, int);
	str = ft_itoa(val);
	if (str == 0)
		return (0);
	ft_putstr_fd(str, 1);
	val = ft_strlen(str);
	free(str);
	return (val);
}
