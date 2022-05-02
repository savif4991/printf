#include "./ft_printf.h"

int	ft_write_p(va_list ap)
{
	write(1, va_arg(ap, void *), sizeof(void *));
	return (14);
}