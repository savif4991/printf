#include "./ft_printf.h"

int	ft_write_u(va_list ap)
{
	unsigned int	val;
	unsigned int	quo;
	int				dig;
	char			*str;

	val = va_arg(ap, unsigned int);
	dig = 1;
	quo = val;
	while (quo /= 10)
		dig++;
	str = (char *)malloc(sizeof(char) * (dig + 1));
	if (str == 0)
		return (0);
	str[dig] = 0;
	while (val)
	{
		str[--dig] = val % 10;
		val /= 10;
	}
	write(1, str, sizeof(char) * dig);
	return (dig);
}