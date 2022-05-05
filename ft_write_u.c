#include "./ft_printf.h"

int	ft_write_u(va_list ap)
{
	int				val;
	int				temp;
	int				dig;
	char			*str;

	val = va_arg(ap, int);
	dig = 1;
	temp = val;
	while (temp /= 10)
		dig++;
	str = (char *)malloc(sizeof(char) * (dig + 1));
	if (str == 0)
		return (0);
	str[dig] = '\0';
	temp = dig;
	while (val)
	{
		str[--temp] = val % 10 + '0';
		val /= 10;
	}
	write(1, str, sizeof(char) * (dig + 1));
	return (dig);
}