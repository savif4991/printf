#include "./ft_printf.h"

static char	*convert_to_hex(unsigned long long val)
{
	char			*res;
	unsigned int	rem;
	unsigned int	quo;
	unsigned int	i;
	unsigned int	dig;

	quo = val;
	dig = 1;
	while (quo /= 16)
		dig++;
	res = (char *)malloc((dig + 1) * sizeof(char));
	if (res == 0)
		return (0);
	res[dig] = '\0';
	i = 1;
	while (val)
	{
		rem = val % 16;
		val /= 16;
		res[dig - i++] = "0123456789abcdef"[rem];
	}
	return (res);
}

int	ft_write_lowerx(va_list ap)
{
	int					res;
	unsigned long long	val;
	char				*str;

	val = va_arg(ap, unsigned long long);
	str = convert_to_hex(val);
	if (str == 0)
		return (0);
	ft_putstr_fd(str, 1);
	res = ft_strlen(str);
	free(str);
	return (res);
}
