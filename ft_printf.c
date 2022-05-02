#include "./libft/libft.h"
#include "./ft_printf.h"

static void	print_warning()
{
	write(1, "WARNING\n", 9);
}

static int	diverge_by_FD(va_list ap, char *adr)
{
	if (*adr == "c") // single character
		ft_write_c(ap);
	else if (*adr == "s") // string
		ft_write_s(ap);
	else if (*adr == "p") // void * pointer has to be printed in hex
		ft_write_p(ap);
	else if (*adr == "d") // decimal
		ft_write_d(ap);
	else if (*adr == "i") // interger in base 10
		ft_write_i(ap);
	else if (*adr == "u") // unsigned decimal in base 10
		ft_write_u(ap);
	else if (*adr == "x") // hex in base 16 lowercase
		ft_write_x(ap);
	else if (*adr == "X") // " uppercase
		ft_write_X(ap);
	else if (*adr == "%") // percent sign
		ft_write_per(ap);
	else
	{
		ft_write_c(ap);
		return (1);
	}
}

int	ft_printf(const char *str, ...)
{
	char			*adr;
	va_list			ap;

	while (1)
	{
		adr = ft_strchr(str, "%");
		if (adr == 0)
			break ;
		va_start(ap, adr);
		if (diverge_by_FD(ap, adr) == 1)
			print_warning();
	}
	return (0);
}