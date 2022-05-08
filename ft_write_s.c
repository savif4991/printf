#include "./ft_printf.h"

char	*ft_write_s(va_list ap)
{
	char	*s;

	s = va_arg(ap, char *);
	return (s);
}
