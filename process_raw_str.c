/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_raw_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daejlee <daejlee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:20:54 by daejlee           #+#    #+#             */
/*   Updated: 2022/06/22 18:20:55 by daejlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

char	*get_res(struct s_info *p, int slots)
{
	char	*res;

	if ((ft_strchr(p->flag, '+') || ft_strchr(p->flag, ' '))
		&& p->raw_str[0] != '-')
		slots++;
	if (ft_strchr(p->flag, '#') && ft_strchr("xX", p->spc)
		&& p->raw_str[0] != '0')
		slots += 2;
	if (p->precision >= p->width && p->precision >= slots
		&& p->spc != 's')
	{
		p->padding = p->precision - slots;
		if (p->raw_str[0] == '-')
			p->padding++;
	}
	else if ((p->width > p->precision || (ft_strchr(p->flag, '-')
				&& p->spc == 's')) && p->width >= slots)
		p->padding = p->width - slots;
	res = (char *)malloc(sizeof(char) * (slots + p->padding + 1));
	if (res == 0)
		return (0);
	res[slots + p->padding] = '\0';
	return (res);
}

char	*get_null_res(struct s_info *p, int slots)
{
	char	*res;

	if (p->width >= slots)
		p->padding = p->width - slots;
	if (p->precision >= slots && ft_strchr("pdiuxX", p->spc))
	{
		if (p->precision > p->width)
			p->padding += (p->precision - slots);
	}
	res = (char *)malloc(sizeof(char) * (slots + p->padding + 1));
	if (res == 0)
		return (0);
	res[slots + p->padding] = '\0';
	return (res);
}

void	str_or_char(struct s_info *p, int raw_strlen)
{
	if (p->precision < raw_strlen && p->precision >= 0
		&& p->width > p->precision)
		p->padding = p->width - p->precision;
	if (p->precision < raw_strlen && p->precision >= 0
		&& ft_strchr(p->flag, '-'))
	{
		ft_strlcpy(p->res_str, p->raw_str, p->precision + 1);
		ft_memset(&p->res_str[p->precision], ' ', p->padding);
	}
	else if (p->precision < raw_strlen && p->precision >= 0)
	{
		ft_memset(p->res_str, ' ', p->padding);
		ft_strlcpy(&p->res_str[p->padding], p->raw_str, p->precision + 1);
	}
	else if (p->padding > 0 && ft_strchr(p->flag, '-'))
	{
		ft_strlcpy(p->res_str, p->raw_str, raw_strlen + 1);
		ft_memset(&p->res_str[raw_strlen], ' ', p->padding);
	}
	else if (p->padding > 0)
	{
		ft_memset(p->res_str, ' ', p->padding);
		ft_strlcpy(&p->res_str[p->padding], p->raw_str, raw_strlen + 1);
	}
	else
		ft_strlcpy(p->res_str, p->raw_str, raw_strlen + 1);
}

void	str_or_char_null(struct s_info *p, int raw_strlen)
{
	if (p->padding > 0 && ft_strchr(p->flag, '-'))
	{
		if (p->spc == 'c' || (p->spc == 's' && p->precision == -2))
			ft_strlcpy(p->res_str, "\0", raw_strlen + 1);
		else if (p->spc == 's')
			ft_strlcpy(p->res_str, "(null)", raw_strlen + 1);
		ft_memset(&p->res_str[raw_strlen], ' ', p->padding);
	}
	else if (p->padding > 0)
	{
		ft_memset(p->res_str, ' ', p->padding);
		if (p->spc == 'c' || (p->spc == 's' && p->precision == -2))
			ft_strlcpy(&p->res_str[p->padding], "\0", raw_strlen + 1);
		else if (p->spc == 's')
			ft_strlcpy(&p->res_str[p->padding], "(null)", raw_strlen + 1);
	}
	else
	{
		if (p->spc == 'c' || (p->spc == 's' && p->precision == -2))
			ft_strlcpy(p->res_str, "\0", raw_strlen + 1);
		else if (p->spc == 's')
			ft_strlcpy(p->res_str, "(null)", raw_strlen + 1);
	}
}

void	ptr_null(struct s_info *p, int raw_strlen)
{
	if (p->padding > 0 && ft_strchr(p->flag, '-'))
	{
		ft_strlcpy(p->res_str, "0x0", raw_strlen + 1);
		ft_memset(&p->res_str[raw_strlen], ' ', p->padding);
	}
	else if (p->padding > 0)
	{
		ft_memset(p->res_str, ' ', p->padding);
		ft_strlcpy(&p->res_str[p->padding], "0x0", raw_strlen + 1);
	}
	else
		ft_strlcpy(p->res_str, "0x0", raw_strlen + 1);
}

void	num_no_padding(struct s_info *p, int raw_strlen)
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
	{
		p->res_str[i] = '\0';
		if (ft_strchr(p->flag, '0'))
		{
			p->res_str[i++] = ' ';
			p->res_str[i] = '\0';
		}
	}
	else
		ft_strlcpy(&p->res_str[i], p->raw_str, raw_strlen + 1);
}

void	num_padding_noflag(struct s_info *p,
	unsigned int padding, int raw_strlen)
{
	unsigned int	i;

	i = 0;
	if (ft_strchr(p->flag, '0') || (p->raw_str[0] == '-'
			&& p->precision >= raw_strlen - 1 && p->precision >= p->width)
		|| (p->raw_str[0] != '-' && p->precision >= raw_strlen
			&& p->precision > p->width))
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
	{
		p->res_str[i++] = ' ';
		p->res_str[i] = '\0';
	}
	else
		ft_strlcpy(&p->res_str[i], p->raw_str, raw_strlen + 1);
	if (p->raw_str[0] == '-' && (p->precision >= raw_strlen
			|| ft_strchr(p->flag, '0')))
	{
		p->res_str[0] = '-';
		p->res_str[i] = '0';
	}
	if (ft_strchr(p->flag, '0') && p->width > p->precision
		&& p->precision >= 0 && p->spc != 's')
	{
		if (p->precision >= (int)ft_strlen(p->raw_str))
		{
			ft_memset(p->res_str, ' ', p->width - p->precision);
			if (p->raw_str[0] == '-')
				p->res_str[p->width - p->precision - 1] = '-';
		}
		else
		{
			ft_memset(p->res_str, ' ', p->width - (int)ft_strlen(p->raw_str));
			if (p->raw_str[0] == '-')
				p->res_str[p->width - (int)ft_strlen(p->raw_str)] = '-';
		}
	}
}

void	num_padding_flag(struct s_info *p, unsigned int padding, int slots)
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
	if (p->raw_str[0] != '-' && p->precision >= slots)
	{
		ft_memset(&p->res_str[i], '0', p->precision - slots);
		i += p->precision - slots;
		ft_strlcpy(&p->res_str[i], p->raw_str, slots + 1);
		i += slots;
		if (p->width > (int)ft_strlen(p->res_str))
			ft_memset(&p->res_str[i], ' ', p->width - ft_strlen(p->res_str));
	}
	else if (p->raw_str[0] == '-' && p->precision >= slots - 1)
	{
		p->res_str[i++] = '-';
		ft_memset(&p->res_str[i], '0', p->precision - slots + 1);
		i += p->precision - slots + 1;
		ft_strlcpy(&p->res_str[i], p->raw_str + 1, slots);
		i += slots - 1;
		if (p->width > (int)ft_strlen(p->res_str))
			ft_memset(&p->res_str[i], ' ', p->width - ft_strlen(p->res_str));
	}
	else
	{
		if ((p->precision != -2 && p->precision != 0) || p->raw_str[0] != '0')
		{
			ft_strlcpy(&p->res_str[i], p->raw_str, slots + 1);
			i += slots;
		}
		if (ft_strchr(p->flag, '0'))
			ft_memset(&p->res_str[i], '0', padding);
		else
			ft_memset(&p->res_str[i], ' ', padding);
		if ((p->precision == -2 || p->precision == 0) && p->raw_str[0] == '0')
		{
			i += padding;
			if (ft_strchr(p->flag, '0'))
				p->res_str[i++] = '0';
			else
				p->res_str[i++] = ' ';
			p->res_str[i] = '\0';
		}
	}
}

int	get_null_strlen(struct s_info *p)
{
	if (p->spc == 's' && p->precision == -2)
		return (0);
	else if (p->spc == 's')
	{
		p->raw_str = "(null)";
		return (6);
	}
	else if (p->spc == 'p')
		return (3);
	else
		return (1);
}

char	*process_raw_str(struct s_info *p)
{
	int				slots;
	int				raw_strlen;

	if (!p->raw_str || (!p->raw_str[0] && p->spc == 'c')
		|| (p->precision == -2 && p->spc == 's'))
		raw_strlen = get_null_strlen(p);
	else
		raw_strlen = ft_strlen(p->raw_str);
	slots = raw_strlen;
	p->padding = 0;
	if (!p->raw_str || (!p->raw_str[0] && p->spc == 'c')
		|| (p->precision == -2 && p->spc == 's'))
		p->res_str = get_null_res(p, slots);
	else
		p->res_str = get_res(p, slots);
	if (ft_strchr("cs\%", p->spc))
	{
		if (!p->raw_str || (!p->raw_str[0] && p->spc == 'c')
			|| (p->precision == -2 && p->spc == 's'))
			str_or_char_null(p, slots);
		else if (p->raw_str[0])
			str_or_char(p, slots);
	}
	else
	{
		if (p->spc == 'p' && !p->raw_str)
			ptr_null(p, slots);
		else if (p->padding > 0 && ft_strchr(p->flag, '-'))
			num_padding_flag(p, p->padding, slots);
		else if (p->padding > 0)
			num_padding_noflag(p, p->padding, slots);
		else
			num_no_padding(p, slots);
	}
	return (p->res_str);
}
