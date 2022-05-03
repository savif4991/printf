#include "./ft_printf.h"

int	ft_write_p(va_list ap)
{
	void	*ptr;

	ptr = va_arg(ap, void *);
	write(1, ptr, sizeof(void *));
	return (14);
}