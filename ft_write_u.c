#include "./ft_printf.h"

int	ft_write_u(va_list ap)
{
	unsigned int	val;
	unsigned int	quo;
	int				dig;

	val = va_arg(ap, unsigned int);
	dig = 0;
	quo = val;
	while (quo != 0)
	{
		quo /= 10;
		dig++;
	}
	write(1, &val, sizeof(unsigned int));
	return (dig);
}