/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohlee <yohlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 04:17:18 by yohlee            #+#    #+#             */
/*   Updated: 2020/05/04 05:09:31 by yohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	apply_tags_percent(t_data *data)
{
	int	i;

	i = 0;
	if (data->minus == true)
	{
		ft_putchar('%');
		while (++i < data->width)
			ft_putchar(' ');
	}
	else
	{
		while (++i < data->width)
			ft_putchar((data->zero == true) ? '0' : ' ');
		ft_putchar('%');
	}
	data->ret += data->width;
	return (1);
}

int	ft_printf_percent(t_data *data)
{
	if (data->check_width && data->width > 1)
	{
		apply_tags_percent(data);
	}
	else
	{
		ft_putchar('%');
		data->ret += 1;
	}
	return (1);
}
