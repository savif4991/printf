#include "./ft_printf.h"

char	*ft_write_per(va_list ap)
{
	char	*str;

	str = (char *)malloc(2 * sizeof(char));
	if (str == 0)
		return (0);
	str[0] = va_arg(ap, int);
	str[1] = '\0';
	return (str);
}