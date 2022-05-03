#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "./libft/libft.h"
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_write_c(va_list ap);
int	ft_write_s(va_list ap);
int	ft_write_p(va_list ap);
int	ft_write_d(va_list ap);
int	ft_write_i(va_list ap);
int	ft_write_u(va_list ap);
int	ft_write_x(va_list ap);
int	ft_write_X(va_list ap);
int	ft_write_per(va_list ap);

#endif
