/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_upperx.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daejlee <daejlee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:20:50 by daejlee           #+#    #+#             */
/*   Updated: 2022/06/22 18:20:51 by daejlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

static char	*convert_to_hex(unsigned long long val)
{
	char					*res;
	unsigned int			rem;
	unsigned long long int	quo;
	unsigned int			i;
	unsigned int			dig;

	quo = val;
	dig = 1;
	while (quo / 16)
	{
		quo /= 16;
		dig++;
	}
	res = (char *)malloc((dig + 1) * sizeof(char));
	if (res == 0)
		return (0);
	res[dig] = '\0';
	if (!val)
		res[0] = '0';
	i = 1;
	while (val)
	{
		rem = val % 16;
		val /= 16;
		res[dig - i++] = "0123456789ABCDEF"[rem];
	}
	return (res);
}

char	*ft_write_upperx(va_list ap)
{
	unsigned long long	val;
	char				*str;

	val = va_arg(ap, unsigned long long);
	str = convert_to_hex(val);
	if (str == 0)
		return (0);
	return (str);
}
