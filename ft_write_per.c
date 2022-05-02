#include "./ft_printf.h"

int	ft_write_per(va_list ap)
{
	write(1, va_arg(ap, char), sizeof(char));
	return (1);
}