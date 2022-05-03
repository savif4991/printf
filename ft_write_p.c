#include "./ft_printf.h"

static char	*convert_to_hex(unsigned long long val)
{
	char			*res;
	unsigned int	rem;
	unsigned int	i;

	res = (char *)malloc(15 * sizeof(char));
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

int	ft_write_p(va_list ap)
{
	int					dig;
	unsigned long long	val;
	void				*ptr;

	ptr = va_arg(ap, void *);
	val = (unsigned long long)ptr;
	ft_putstr_fd(convert_to_hex(val), 1);
	return (14);
}