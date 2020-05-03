/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohlee <yohlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 23:43:35 by yohlee            #+#    #+#             */
/*   Updated: 2020/05/03 00:14:00 by yohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_p(t_data *data)
{
	size_t	addr;
	char	*result;
	int		i;

	result = 0;
	i = 11;
	if ((addr = va_arg(data->ap, size_t)))
	{
		if (!(result = ft_calloc(12, sizeof(char))))
			return (-1);
		ft_strlcpy(result, "0x", 3);
		while (--i > 1)
		{
			result[i] = HEX_STR_LOWER[addr % 16];
			addr /= 16;
		}
		result[11] = '\0';
	}
	else
		result = ft_strdup("0x0");
	ft_putstr(result);
	data->ret += ft_strlen(result);
	free(result);
	result = 0;
	return (1);
}
