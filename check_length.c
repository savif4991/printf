#include "ft_printf.h"

int	check_length(const char *str)
{
	if (*str == 'h')
		return (1);
	else if (*str == 'l')
		return (2);
	else if (*str == 'L')
		return (3);
	else
		return (-1);
}
