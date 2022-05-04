#include <stdio.h>
#include "ft_printf.h"

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

	return (0);
}