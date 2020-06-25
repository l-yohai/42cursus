/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohlee <yohlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 23:43:35 by yohlee            #+#    #+#             */
/*   Updated: 2020/05/08 09:23:26 by yohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** flag '0' and precision result in undefined behavior
** with 'p' conversion specifier.
*/

int		apply_tags_p(t_data *data, char *s)
{
	char	*result;
	int		size;

	result = 0;
	size = 0;
	if ((size = apply_width(data, s)) == -1)
		return (-1);
	if (!(result = apply_flag_s(data, s, size)))
		return (-1);
	ft_putstr(result);
	data->ret += ft_strlen(result);
	free(result);
	result = 0;
	return (1);
}

char	*remove_zero_address(char *s)
{
	int		i;
	int		j;
	int		size;
	char	*temp;

	i = 2;
	j = 2;
	size = 0;
	temp = 0;
	while (s[i] && s[i] == '0')
		i++;
	size = (int)ft_strlen(s) - i + 2;
	if (!(temp = ft_calloc(size + 1, sizeof(char))))
		return (NULL);
	ft_strlcpy(temp, "0x", 3);
	while (s[i])
	{
		temp[j] = s[i];
		i++;
		j++;
	}
	free(s);
	s = 0;
	return (temp);
}

char	*get_address(t_data *data, char *s)
{
	size_t	addr;
	int		i;

	if ((addr = va_arg(data->ap, size_t)))
	{
		i = 14;
		if (!(s = ft_calloc(15, sizeof(char))))
			return (NULL);
		ft_strlcpy(s, "0x", 3);
		while (--i > 1)
		{
			s[i] = HEX_STR_LOWER[addr % 16];
			addr /= 16;
		}
		s[14] = '\0';
	}
	else
	{
		if (data->check_precision == true && data->precision == 0)
			s = ft_strdup("0x");
		else
			s = ft_strdup("0x0");
	}
	return (s);
}

int		ft_printf_p(t_data *data)
{
	char	*s;

	if (data->zero == true\
		|| (data->check_precision == true && data->precision != 0))
		return (-1);
	s = 0;
	if (!(s = get_address(data, s)))
		return (-1);
	if (ft_strncmp(s, "0x0", ft_strlen(s))\
			&& !(s = remove_zero_address(s)))
		return (-1);
	if (apply_tags_p(data, s) == -1)
		return (-1);
	return (1);
}
