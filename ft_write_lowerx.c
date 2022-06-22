/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_lowerx.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daejlee <daejlee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:20:28 by daejlee           #+#    #+#             */
/*   Updated: 2022/06/22 18:20:29 by daejlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./ft_printf.h"

static char	*get_res(unsigned long long int quo,
	unsigned int dig, unsigned long long val)
{
	char			*res;
	unsigned int	rem;
	unsigned int	i;

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
		res[dig - i++] = "0123456789abcdef"[rem];
	}
	return (res);
}

char	*ft_write_lowerx(va_list ap)
{
	unsigned long long		val;
	char					*str;
	unsigned long long int	quo;
	unsigned int			i;
	unsigned int			dig;

	val = va_arg(ap, unsigned long long);
	quo = val;
	dig = 1;
	while (quo / 16)
	{
		quo /= 16;
		dig++;
	}
	return (get_res(quo, dig, val));
}
