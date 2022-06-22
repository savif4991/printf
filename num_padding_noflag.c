/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_padding_noflag.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daejlee <daejlee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 22:21:17 by daejlee           #+#    #+#             */
/*   Updated: 2022/06/22 22:21:18 by daejlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

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
