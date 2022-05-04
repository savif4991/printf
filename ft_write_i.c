#include "./ft_printf.h"

int	ft_write_i(va_list ap)
{
	int				val;
	int				temp;
	int				dig;
	int				sign;
	char			*str;

	sign = 1;
	val = va_arg(ap, int);
	if (val < 0)
	{
		val *= -1;
		sign = -1;
	}
	dig = 1;
	temp = val;
	while (temp /= 10)
		dig++;
	if (sign == -1)
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
	if (sign == -1)
		str[0] = '-';
	write(1, str, sizeof(char) * (dig + 1));
	return (dig);
}