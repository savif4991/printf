#include "./ft_printf.h"

int	ft_write_d(va_list ap)
{
	int	val;
	int	quo;
	int	dig;

	val = va_arg(ap, int);
	dig = 0;
	quo = val;
	while (quo != 0)
	{
		quo /= 10;
		dig++;
	}
	write(1, &val, sizeof(int));
	return (dig);
}