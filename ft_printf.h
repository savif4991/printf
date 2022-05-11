#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "./libft/libft.h"
# include <stdarg.h>

typedef struct s_info
{
	char			spc;
	char			*flag;
	int				width;
	int				precision;
	int				length;
	char			*raw_str;
	char			*res_str;
}	p;

int		ft_printf(const char *str, ...);
char	*process_raw_str(struct s_info *p);
char	*check_specifier(va_list ap, const char *str);
int		check_precision(const char *str, va_list ap);
int		check_length(const char *str);
int		check_width(const char *str, va_list ap);
char	*check_flag(const char *str);
char	*ft_write_c(va_list ap);
char	*ft_write_s(va_list ap);
char	*ft_write_p(va_list ap);
char	*ft_write_d(va_list ap);
char	*ft_write_i(va_list ap);
char	*ft_write_u(va_list ap);
char	*ft_write_lowerx(va_list ap);
char	*ft_write_upperX(va_list ap);
char	*ft_write_per(va_list ap);

#endif
