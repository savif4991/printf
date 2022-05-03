#include "./ft_printf.h"

static char	*convert_to_hex(unsigned long long val, int *dig)
{
	char			*res;
	unsigned int	rem;
	unsigned int	quo;
	unsigned int	i;

	quo = val;
	while (quo != 0)
	{
		quo /= 16;
		*dig++;
	}
	res = (char *)malloc((*dig + 1) * sizeof(char));
	if (res == 0)
		return (0);
	res[*dig] = '\0';
	i = 1;
	while (val != 0)
	{
		rem = val % 16;
		val /= 16;
		res[*dig - i] = "0123456789abcdef"[rem];
		i++;
	}
	return (res);
}

int	ft_write_x(va_list ap)
{
	int					dig;
	unsigned long long	val;

	dig = 0;
	val = va_arg(ap, unsigned long long);
	ft_putstr_fd(convert_to_hex(val, &dig), 1);
	return (dig);
}