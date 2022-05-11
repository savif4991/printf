#include "ft_printf.h"

static char	*get_res(struct s_info *p, unsigned int padding, int raw_strlen, int slots)
{
	char	*res;

	if ((ft_strchr(p->flag, '+') || ft_strchr(p->flag, ' ')) && p->raw_str[0] != '-')
		slots++; // +, - ' ' 중 하나가 삽입됨
	if (ft_strchr(p->flag, '#') && ft_strchr("xX", p->spc) && p->raw_str[0] != '0')
		slots += 2;
	if (p->width >= slots) // width와 precision이 충돌할 때 -> 더 큰 값이 작동.
		padding = p->width - raw_strlen;
	if (p->raw_str[0] == '-' && p->precision >= raw_strlen - 1 
	&& ft_strchr("pdiuxX", p->spc))
	{
		if (p->precision >= p->width)
			padding += (p->precision - raw_strlen + 1);
	}
	else if (p->raw_str[0] != '-' && p->precision >= raw_strlen 
	&& ft_strchr("pdiuxX", p->spc))
	{
		if (p->precision > p->width)
			padding += (p->precision - raw_strlen);
	}
	res = (char *)malloc(sizeof(char) * (slots + padding + 1));
	if (res == 0)
		return (0);
	res[slots + padding + 1] = '\0';
	return (res);
}

static void	str_or_char(struct s_info *p, unsigned int padding, int raw_strlen)
{
	if (padding > 0 && ft_strchr(p->flag, '-'))
	{
		ft_strlcpy(p->res_str, p->raw_str, raw_strlen + 1);
		ft_memset(&p->res_str[raw_strlen], ' ', padding);
	}
	else if (padding > 0)
	{
		ft_memset(p->res_str, ' ', padding);
		ft_strlcpy(&p->res_str[padding], p->raw_str, raw_strlen + 1);
	}
	else
		ft_strlcpy(p->res_str, p->raw_str, raw_strlen + 1);
}

static void	num_no_padding(struct s_info *p, int raw_strlen)
{
	unsigned int	i;

	i = 0;
	if (ft_strchr(p->flag, '+') && !ft_strchr("+-", p->raw_str[0]))
		p->res_str[i++] = '+';
	else if (ft_strchr(p->flag, ' ') && !ft_strchr("+-", p->raw_str[0]))
		p->res_str[i++] = ' ';
	if (ft_strchr(p->flag, '#') && p->spc == 'x' && p->raw_str[0] != '0')
	{
		ft_strlcpy(&p->res_str[i], "0x", 3);
		i += 2;
	}
	else if (ft_strchr(p->flag, '#') && p->spc == 'X' && p->raw_str[0] != '0')
	{
		ft_strlcpy(&p->res_str[i], "0X", 3);
		i += 2;
	}
	if ((p->precision == -2 || p->precision == 0) && p->raw_str[0] == '0')
		p->res_str[i] = '\0';
	else
		ft_strlcpy(&p->res_str[i], p->raw_str, raw_strlen + 1);
}

void	num_padding_noflag(struct s_info *p, unsigned int padding, int raw_strlen)
{
	unsigned int	i;

	i = 0;
	if (ft_strchr(p->flag, '0') ||
	(p->raw_str[0] == '-' && p->precision >= raw_strlen - 1 && p->precision >= p->width) ||
	(p->raw_str[0] != '-' && p->precision >= raw_strlen && p->precision > p->width))
		ft_memset(&p->res_str[i], '0', padding);
	else
		ft_memset(&p->res_str[i], ' ', padding);
	i += padding;
	if (ft_strchr(p->flag, '+') && !ft_strchr("+-", p->raw_str[0]))
		p->res_str[i++] = '+';
	else if (ft_strchr(p->flag, ' ') && !ft_strchr("+-", p->raw_str[0]))
		p->res_str[i++] = ' ';
	if (ft_strchr(p->flag, '#') && p->spc == 'x' && p->raw_str[0] != '0')
	{
		ft_strlcpy(&p->res_str[i], "0x", 3);
		i += 2;
	}
	else if (ft_strchr(p->flag, '#') && p->spc == 'X' && p->raw_str[0] != '0')
	{
		ft_strlcpy(&p->res_str[i], "0X", 3);
		i += 2;
	}
	if ((p->precision == -2 || p->precision == 0) && p->raw_str[0] == '0')
		p->res_str[i] = '\0';
	else
		ft_strlcpy(&p->res_str[i], p->raw_str, raw_strlen + 1);
}

void	num_padding_flag(struct s_info *p, unsigned int padding, int raw_strlen)
{
	unsigned int	i;

	i = 0;
	if (ft_strchr(p->flag, '+') && !ft_strchr("+-", p->raw_str[0]))
		p->res_str[i++] = '+';
	else if (ft_strchr(p->flag, ' ') && !ft_strchr("+-", p->raw_str[0]))
		p->res_str[i++] = ' ';
	if (ft_strchr(p->flag, '#') && p->spc == 'x' && p->raw_str[0] != '0')
	{
		ft_strlcpy(&p->res_str[i], "0x", 3);
		i += 2;
	}
	else if (ft_strchr(p->flag, '#') && p->spc == 'X' && p->raw_str[0] != '0')
	{
		ft_strlcpy(&p->res_str[i], "0X", 3);
		i += 2;
	}
	if ((p->precision == -2 || p->precision == 0) && p->raw_str[0] == '0')
		p->res_str[i] = '\0';
	else
		ft_strlcpy(&p->res_str[i], p->raw_str, raw_strlen + 1);
	i += raw_strlen;
	if (ft_strchr(p->flag, '0') ||
	(p->raw_str[0] == '-' && p->precision >= raw_strlen - 1 && p->precision >= p->width) ||
	(p->raw_str[0] != '-' && p->precision >= raw_strlen && p->precision > p->width))
		ft_memset(&p->res_str[i], '0', padding);
	else
		ft_memset(&p->res_str[i], ' ', padding);
}

char	*process_raw_str(struct s_info *p)
{
	int				slots;
	unsigned int	padding;
	int				raw_strlen;
//!! length 는 보류 !!
	raw_strlen = ft_strlen(p->raw_str);
	slots = raw_strlen;
	padding = 0;
	p->res_str = get_res(p, padding, raw_strlen, slots);
	if (ft_strchr("cs\%", p->spc))
		str_or_char(p, padding, raw_strlen);
	else if (ft_strchr("pdiuxX", p->spc))
	{
		if (padding > 0 && ft_strchr(p->flag, '-'))
			num_padding_flag(p, padding, raw_strlen);
		else if (padding > 0)
			num_padding_noflag(p, padding, raw_strlen);
		else
			num_no_padding(p, raw_strlen);
	}
	return (p->res_str);
}