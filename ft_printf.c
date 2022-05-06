#include "ft_printf.h"
#include <stdio.h>

//gcc -o test.a main.c -L. -l ftprintf

static int	diverge_by_FS(va_list ap, int *res, const char *str)
{
	if (*str == 'c') // single character
		*res += ft_write_c(ap);
	else if (*str == 's') // string
		*res += ft_write_s(ap);
	else if (*str == 'p') // void * pointer has to be printed in hex
		*res += ft_write_p(ap);
	else if (*str == 'd') // decimal
		*res += ft_write_d(ap);
	else if (*str == 'i') // interger in base 10
		*res += ft_write_i(ap);
	else if (*str == 'u') // unsigned decimal in base 10
		*res += ft_write_u(ap);
	else if (*str == 'x') // hex in base 16 lowercase
		*res += ft_write_x(ap);
	else if (*str == 'X') // " uppercase
		*res += ft_write_X(ap);
	else if (*str == '\%') // percent sign
		*res += ft_write_per(ap);
	else
		return (1);
	return (0);
}

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
				i = i + 2;
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
			diverge_by_FS(ap, &res, &str[i++]);
		}
	}
	return (res);
}

int main()
{
	int		ret_val;

	char	c1 = 'a';
	char	c2 = 'b';
	ret_val = printf("___printf result is %c, %c ", c1, c2);
	printf("and ret val is %d\n", ret_val);
	ret_val = ft_printf("ft_printf result is %c, %c ", c1, c2);
	printf("and ret val is %d\n", ret_val);

	int		i1 = 1;
	int		i2 = -2;
	ret_val = printf("___printf result is %d, %d ", i1, i2);
	printf("and ret val is %d\n", ret_val);
	ret_val = ft_printf("ft_printf result is %d, %d ", i1, i2);
	printf("and ret val is %d\n", ret_val);

	ret_val = printf("___printf result is %i, %i ", i1, i2);
	printf("and ret val is %d\n", ret_val);
	ret_val = ft_printf("ft_printf result is %i, %i ", i1, i2);
	printf("and ret val is %d\n", ret_val);

	void	*ptr1 = &i1;
	void	*ptr2 = &i2;
	ret_val = printf("___printf result is %p, %p ", ptr1, ptr2);
	printf("and ret val is %d\n", ret_val);
	ret_val = ft_printf("ft_printf result is %p, %p ", ptr1, ptr2);
	printf("and ret val is %d\n", ret_val);

	char	per = '%';
	ret_val = printf("___printf result is %c ", per);
	printf("and ret val is %d\n", ret_val);
	ret_val = ft_printf("ft_printf result is %c ", per);
	printf("and ret val is %d\n", ret_val);

	char	*str1 = "this is the string.";
	char	*str2 = "this is the string";
	ret_val = printf("___printf result is %s, %s ", str1, str2);
	printf("and ret val is %d\n", ret_val);
	ret_val = ft_printf("ft_printf result is %s, %s ", str1, str2);
	printf("and ret val is %d\n", ret_val);

	unsigned int		u1 = 1;
	unsigned int		u2 = 2;
	ret_val = printf("___printf result is %u, %u ", u1, u2);
	printf("and ret val is %d\n", ret_val);
	ret_val = ft_printf("ft_printf result is %u, %u ", u1, u2);
	printf("and ret val is %d\n", ret_val);

	ret_val = printf("___printf result is %%%%u, %u ", u2);
	printf("and ret val is %d\n", ret_val);
	ret_val = ft_printf("ft_printf result is %%%%u, %u ", u2);
	printf("and ret val is %d\n", ret_val);

	return (0);
}