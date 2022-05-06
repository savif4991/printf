#include "./ft_printf.h"

int	ft_write_s(va_list ap)
{
	char	*s;

	s = va_arg(ap, char *);
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}
