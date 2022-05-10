#include "ft_printf.h"
#include <stdio.h>

//%[flags][width][.precision][length]specifier

static unsigned int	count_per(const char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] == '\%')
		i++;
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list			ap;
	unsigned int	i;
	int				res;
	unsigned int	count;
	char			*flag;
	int				width;
	int				precision;
	int				length;
	char			*raw_str;
	char			*res_str;

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
			if (flag != 0)
				i += ft_strlen(flag);
			width = check_width(&str[i], ap);
			if (width != -1)
				i += ft_strlen(ft_itoa(width));
			precision = check_precision(&str[i], ap);
			if (precision != -1 && precision != -2)
				i += ft_strlen(ft_itoa(precision)) + 1;
			else if (precision == -2)
				i++;
			length = check_length(&str[i]);
			if (length != -1)
				i++;
			raw_str = check_specifier(ap, &str[i]);
			if (raw_str == 0)
				return (0);
			res_str = process_raw_str(raw_str, str[i++], flag, width, precision, length);
			ft_putstr_fd(res_str, 1);
			res += ft_strlen(res_str);
		}
	}
	return (res);
}
