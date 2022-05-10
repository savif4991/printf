#include "ft_printf.h"

char	*process_raw_str(char *raw_str, char spc, char *flag, int width, int precision, int length)
{
	unsigned int	i;
	int				slots;
	unsigned int	padding;
	char			*res;
	int				raw_strlen;
//!! length 는 보류 !!
	raw_strlen = ft_strlen(raw_str);
	slots = raw_strlen;
	padding = 0;
	if ((ft_strchr(flag, '+') || ft_strchr(flag, ' ')) && raw_str[0] != '-')
		slots++; // +, - ' ' 중 하나가 삽입됨
	if (ft_strchr(flag, '#') && ft_strchr("xX", spc) && raw_str[0] != '0')
		slots += 2;
	if (width >= slots) // width와 precision이 충돌할 때 -> 더 큰 값이 작동.
		padding = width - raw_strlen;
	if (raw_str[0] == '-' && precision >= raw_strlen - 1 
	&& ft_strchr("pdiuxX", spc))
	{
		if (precision >= width)
			padding += (precision - raw_strlen + 1);
	}
	else if (raw_str[0] != '-' && precision >= raw_strlen 
	&& ft_strchr("pdiuxX", spc))
	{
		if (precision > width)
			padding += (precision - raw_strlen);
	}
	res = (char *)malloc(sizeof(char) * (slots + padding + 1));
	if (res == 0)
		return (0);
	res[slots + padding + 1] = '\0';
	i = 0;
	if (ft_strchr("cs\%", spc))
	{
		if (padding > 0 && ft_strchr(flag, '-'))
		{
			ft_strlcpy(res, raw_str, raw_strlen + 1);
			ft_memset(&res[raw_strlen], ' ', padding);
		}
		else if (padding > 0)
		{
			ft_memset(res, ' ', padding);
			ft_strlcpy(&res[padding], raw_str, raw_strlen + 1);
		}
		else
			ft_strlcpy(res, raw_str, raw_strlen + 1);
	}
	else if (ft_strchr("pdiuxX", spc))
	{
		if (padding > 0 && ft_strchr(flag, '-'))
		{
			if (ft_strchr(flag, '+') && !ft_strchr("+-", raw_str[0]))
				res[i++] = '+';
			else if (ft_strchr(flag, ' ') && !ft_strchr("+-", raw_str[0]))
				res[i++] = ' ';
			if (ft_strchr(flag, '#') && spc == 'x' && raw_str[0] != '0')
			{
				ft_strlcpy(&res[i], "0x", 3);
				i += 2;
			}
			else if (ft_strchr(flag, '#') && spc == 'X' && raw_str[0] != '0')
			{
				ft_strlcpy(&res[i], "0X", 3);
				i += 2;
			}
			if ((precision == -2 || precision == 0) && raw_str[0] == '0')
				res[i] = '\0';
			else
				ft_strlcpy(&res[i], raw_str, raw_strlen + 1);
			i += raw_strlen;
			if (ft_strchr(flag, '0') ||
			(raw_str[0] == '-' && precision >= raw_strlen - 1 && precision >= width) ||
			(raw_str[0] != '-' && precision >= raw_strlen && precision > width))
				ft_memset(&res[i], '0', padding);
			else
				ft_memset(&res[i], ' ', padding);
		}
		else if (padding > 0)
		{
			if (ft_strchr(flag, '0') ||
			(raw_str[0] == '-' && precision >= raw_strlen - 1 && precision >= width) ||
			(raw_str[0] != '-' && precision >= raw_strlen && precision > width))
				ft_memset(&res[i], '0', padding);
			else
				ft_memset(&res[i], ' ', padding);
			i += padding;
			if (ft_strchr(flag, '+') && !ft_strchr("+-", raw_str[0]))
				res[i++] = '+';
			else if (ft_strchr(flag, ' ') && !ft_strchr("+-", raw_str[0]))
				res[i++] = ' ';
			if (ft_strchr(flag, '#') && spc == 'x' && raw_str[0] != '0')
			{
				ft_strlcpy(&res[i], "0x", 3);
				i += 2;
			}
			else if (ft_strchr(flag, '#') && spc == 'X' && raw_str[0] != '0')
			{
				ft_strlcpy(&res[i], "0X", 3);
				i += 2;
			}
			if ((precision == -2 || precision == 0) && raw_str[0] == '0')
				res[i] = '\0';
			else
				ft_strlcpy(&res[i], raw_str, raw_strlen + 1);
		}
		else
		{
			if (ft_strchr(flag, '+') && !ft_strchr("+-", raw_str[0]))
				res[i++] = '+';
			else if (ft_strchr(flag, ' ') && !ft_strchr("+-", raw_str[0]))
				res[i++] = ' ';
			if (ft_strchr(flag, '#') && spc == 'x' && raw_str[0] != '0')
			{
				ft_strlcpy(&res[i], "0x", 3);
				i += 2;
			}
			else if (ft_strchr(flag, '#') && spc == 'X' && raw_str[0] != '0')
			{
				ft_strlcpy(&res[i], "0X", 3);
				i += 2;
			}
			if ((precision == -2 || precision == 0) && raw_str[0] == '0')
				res[i] = '\0';
			else
				ft_strlcpy(&res[i], raw_str, raw_strlen + 1);
		}
	}
	return (res);
}