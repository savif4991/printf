#include "./ft_printf.h"

static char	*convert_to_hex(unsigned long long val)
{
	char			*res;
	unsigned int	rem;
	unsigned int	i;

	res = (char *)malloc(15 * sizeof(char));
	ft_memset (res, '0', 15);
	if (res == 0)
		return (0);
	res[14] = '\0';
	i = 0;
	while (val != 0)
	{
		rem = val % 16;
		val /= 16;
		res[13 - i] = "0123456789abcdef"[rem];
		i++;
	}
	return (res);
}

char	*ft_write_p(va_list ap)
{
	unsigned long long	val;
	void				*ptr;
	char				*str;

	ptr = va_arg(ap, void *);
	val = (unsigned long long)ptr;
	str = convert_to_hex(val);
	return (str);
}