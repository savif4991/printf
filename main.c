#include <stdio.h>
#include "ft_printf.h"

int main()
{
	char	c1 = 'a';
	char	c2 = 'b';
	
	int		i1 = 1;
	int		i2 = -2;
	int		ret_val;
	
	ret_val = printf("___printf result is %c, %c ", c1, c2);
	printf("and ret val is %d\n", ret_val);
	ret_val = ft_printf("ft_printf result is %c, %c ", c1, c2);
	printf("and ret val is %d\n", ret_val);
	ret_val = printf("___printf result is %d, %d ", i1, i2);
	printf("and ret val is %d\n", ret_val);
	ret_val = ft_printf("ft_printf result is %d, %d ", i1, i2);
	printf("and ret val is %d\n", ret_val);
	//printf("There are %k fruits.\n", 10);
	return (0);
}