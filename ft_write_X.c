#include "./ft_printf.h"

static char	*convert_to_hex(unsigned long long val)
{
	char			*hexbase;
	char			*res;
	unsigned int	rem;
	unsigned int	quo;
	unsigned int	i;

	res = (char *)malloc(15 * sizeof(char));
	if (res == 0)
		return (0);
	ft_memset(res, '0', 15);
	res[14] = '\0';
	hexbase = "0123456789ABCDEF";
	quo = val;
	i = 0;
	while (quo != 0)
	{
		rem = quo % 16;
		quo /= 16;
		res[14 - i] = hexbase[rem];
		i++;
	}
	return (res);
}

void	ft_write_X(va_list ap)
{
	ft_putstr_fd(convert_to_hex(va_arg(ap, void *)), 1);
}