#include "./ft_printf.h"

void	ft_write_c(va_list ap)
{
	write(1, va_arg(ap, char), sizeof(char));
}