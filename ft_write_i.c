#include "./ft_printf.h"

static void	alloc_num(int val, char *str, int dig, int sign)
{
	str[dig] = '\0';
	while (val)
	{
		str[--dig] = val % 10 + '0';
		val /= 10;
	}
	if (sign == -1)
		str[0] = '-';
}

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
	alloc_num(val, str, dig, sign);
	ft_putstr_fd(str, 1);
	return (dig);
}
