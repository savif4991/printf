#include "ft_printf.h"

static void	print_warning()
{
	write(1, "WARNING\n", 9);
}

static int	diverge_by_FS(va_list ap, int *res)
{
	if (*(char *)ap == "c") // single character
		*res += ft_write_c(ap);
	else if (*(char *)ap == "s") // string
		*res += ft_write_s(ap);
	else if (*(char *)ap == "p") // void * pointer has to be printed in hex
		*res += ft_write_p(ap);
	else if (*(char *)ap == "d") // decimal
		*res += ft_write_d(ap);
	else if (*(char *)ap == "i") // interger in base 10
		*res += ft_write_i(ap);
	else if (*(char *)ap == "u") // unsigned decimal in base 10
		*res += ft_write_u(ap);
	else if (*(char *)ap == "x") // hex in base 16 lowercase
		*res += ft_write_x(ap);
	else if (*(char *)ap == "X") // " uppercase
		*res += ft_write_X(ap);
	else if (*(char *)ap == "%") // percent sign
		*res += ft_write_per(ap);
	else
	{
		ft_write_c(ap);
		return (1);
	}
}

int	ft_printf(const char *str, ...)
{
	va_list			ap;
	unsigned int	i;
	int				res;

	i = 0;
	res = 0;
	while (1)
	{
		while (str[i] != "%")
		{
			ft_putchar_fd(str[i], 1);
			res++;
			i++;
			if (str[i] == '\0')
				return (0);
		}
		va_start(ap, &str[i]);
		if (diverge_by_FS(ap, &res) == 1)
			print_warning();
		i = i + 2;
	}
	return (0);
}