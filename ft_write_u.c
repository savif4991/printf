#include "./ft_printf.h"

void	ft_write_u(va_list ap)
{
	write(1, va_arg(ap, unsigned int), sizeof(unsigned int));
}