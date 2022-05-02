#include "./ft_printf.h"

void	ft_write_d(va_list ap)
{
	write(1, va_arg(ap, int), sizeof(int));
}