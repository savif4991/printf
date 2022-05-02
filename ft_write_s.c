#include "./ft_printf.h"

void	ft_write_s(va_list ap)
{
	char	*s;

	s = va_arg(ap, char *);
	write(1, s, ft_strlen(s));
}