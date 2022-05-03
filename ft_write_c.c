#include "./ft_printf.h"

int	ft_write_c(va_list ap)
{
	char	c;

	c = va_arg(ap, int);
	write(1, &c, sizeof(char));
	return (1);
}