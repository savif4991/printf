#include "ft_printf.h"
#include <stdio.h>

static unsigned int	count_per(const char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] == '\%')
		i++;
	return (i);
}

static void	purge(struct s_info *p)
{
	if (p->flag)
		free(p->flag);
	if (p->spc != 's')
		free(p->raw_str);
	if (p->res_str)
		free(p->res_str);
	free(p);
}

int	ft_printf(const char *str, ...)
{
	va_list			ap;
	unsigned int	i;
	int				res;
	unsigned int	per_count;

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
			per_count = (count_per(&str[i]) / 2);
			while (per_count)
			{
				i += 2;
				ft_putchar_fd('\%', 1);
				res++;
				per_count--;
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
			struct s_info *p = (struct s_info *)malloc(sizeof(struct s_info));
			if (p == 0)
				return (0);
			p->flag = check_flag(&str[i]);
			if (p->flag != 0)
				i += ft_strlen(p->flag);
			p->width = check_width(&str[i], ap);
			if (p->width != -1)
				i += ft_strlen(ft_itoa(p->width));
			p->precision = check_precision(&str[i], ap);
			if (p->precision != -1 && p->precision != -2)
				i += ft_strlen(ft_itoa(p->precision)) + 1;
			else if (p->precision == -2)
				i++;
			p->length = check_length(&str[i]);
			if (p->length != -1)
				i++;
			p->raw_str = check_specifier(ap, &str[i]);
			if (p->raw_str == 0)
				return (0);
			p->spc = str[i++];
			p->res_str = process_raw_str(p);
			ft_putstr_fd(p->res_str, 1);
			res += ft_strlen(p->res_str);
			purge(p);
		}
	}
	return (res);
}
