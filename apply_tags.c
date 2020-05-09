/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_tags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohlee <yohlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 13:08:11 by yohlee            #+#    #+#             */
/*   Updated: 2020/05/08 07:25:44 by yohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	check_flags(t_data *data)
{
	if (data->minus == true && data->zero == true)
		return (false);
	return (true);
}

int		apply_width(t_data *data, char *result)
{
	int	size;
	int	len;

	if (!result)
		return (-1);
	size = 0;
	len = ft_strlen(result);
	if (data->check_width == true)
		size = (len > data->width) ? len : data->width;
	else
		size = len;
	return (size);
}

int		check_flag_d(t_data *data, char *result)
{
	int	i;

	i = 0;
	if (data->zero == true)
	{
		if (data->check_precision == true && data->precision >= 0\
				&& data->precision < (int)ft_strlen(result))
		{
			while (result[i] &&\
					i < (int)ft_strlen(result) - data->precision)
			{
				if (result[i] >= '1' && result[i] <= '9')
					break ;
				if (result[i] == '0')
					result[i] = ' ';
				i++;
			}
		}
	}
	return (1);
}
