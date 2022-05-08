#include "ft_printf.h"
#include <stdio.h>

//gcc -o test.a main.c -L. -l ftprintf
//%[flags][width][.precision][length]specifier

static unsigned int	count_per(const char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] == '\%')
		i++;
	return (i);
}

char	*process(char *str, int flag, int width, int precision, int length)
{
	unsigned int	i;

	i = 0;
	
}

char	*check_specifier(va_list ap, const char *str)
{
	char	*res;

	if (*str == 'c')
		res = ft_write_c(ap);
	else if (*str == 's')
		res = ft_write_s(ap);
	else if (*str == 'p')
		res = ft_write_p(ap);
	else if (*str == 'd')
		res = ft_write_d(ap);
	else if (*str == 'i')
		res = ft_write_i(ap);
	else if (*str == 'u')
		res = ft_write_u(ap);
	else if (*str == 'x')
		res = ft_write_lowerx(ap);
	else if (*str == 'X')
		res = ft_write_upperX(ap);
	else if (*str == '\%')
		res = ft_write_per(ap);
	else
		return (0);
	return (res);
}

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

int	check_precision(const char *str)
{
	unsigned int	i;
	int				res;

	i = 0;
	if (str[i] == '.')
	{
		if (str[1] >= '0' && str[1] <= '9')
			res = ft_atoi(&str[1]);
		else if (str[1] == '*')
			res = 0;
		else
			res = -1;
	}
	else
		res = -1;
	return (res);
}

int	check_width(const char *str)
{
	int	res;

	if (*str >= '0' && *str <= '9')
		res = ft_atoi(str);
	else if (*str == '*')
		res = 0;
	else
		res = -1;
	return (res);
}

int	check_flag(const char *str)
{
	if (*str == '-')
		return (1);
	else if (*str == '+')
		return (2);
	else if (*str == ' ')
		return (3);
	else if (*str == '#')
		return (4);
	else if (*str == '0')
		return (5);
	else
		return (-1);
}

int	ft_printf(const char *str, ...)
{
	va_list			ap;
	unsigned int	i;
	int				res;
	unsigned int	count;
	int				flag;
	int				width;
	int				precision;
	int				length;
	char			*str;

	i = 0;
	res = 0;
	va_start(ap, str);
	while (str[i])
	{
		while (str[i] != '\%')
		{
			ft_putchar_fd(str[i], 1);
			res++;
			i++;
			if (str[i] == '\0')
				return (res);
		}
		if ((count_per(&str[i]) % 2) == 0) //printf 작동 X
		{
			count = (count_per(&str[i]) / 2);
			while (count)
			{
				i += 2;
				ft_putchar_fd('\%', 1);
				res++;
				count--;
			}
		}
		else //printf 작동 O
		{
			while (str[i] == '\%' && str[i + 1] == '\%')
			{
				ft_putchar_fd(str[i], 1);
				res++;
				i++;
			} //마지막 %에서 빠져나옴
			i++;
			flag = check_flag(&str[i]);
			if (flag != -1)
				i++;
			width = check_width(&str[i]);
			if (width != -1)
				i += ft_strlen(ft_itoa(width));
			precision = check_precision(&str[i]);
			if (precision != -1)
				i += ft_strlen(ft_itoa(width));
			length = check_length(&str[i]);
			if (length != -1)
				i++;
			str = check_specifier(ap, &str[i++]);
			if (str == 0)
				return (0);
			str = process(str, flag, width, precision, length);
			ft_putstr_fd(str, 1);
			res += ft_strlen(str);
		}
	}
	return (res);
}
