#include "./ft_printf.h"

void	ft_write_i(va_list ap)
{
	write(1, va_arg(ap, int), sizeof(int));
}