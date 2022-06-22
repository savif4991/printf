/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daejlee <daejlee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:20:45 by daejlee           #+#    #+#             */
/*   Updated: 2022/06/22 18:20:48 by daejlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

static char	*ft_uitoa(unsigned int val)
{
	unsigned int	dig;
	unsigned int	temp;
	char			*str;

	temp = val;
	dig = 1;
	while (temp /= 10)
		dig++;
	str = (char *)malloc(dig + 1);
	if (str == 0)
		return (0);
	str[dig] = '\0';
	while (dig--) //dig의 값으로 조건문이 작동해, 그리고 -1이 연산돼. 그 다음에 실행문이 작동한다. dig-1의 상태로.
	{
		str[dig] = val % 10 + '0';
		val /= 10;
	}
	return (str);
}

char	*ft_write_u(va_list ap)
{
	char				*str;
	unsigned int		val;

	val = va_arg(ap, unsigned int);
	str = ft_uitoa(val);
	return (str);
}
