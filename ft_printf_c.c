/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohlee <yohlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 23:48:33 by yohlee            #+#    #+#             */
/*   Updated: 2020/05/06 22:55:56 by yohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Precision and flag '0'
** result in undefined behavior with 'c' conversion specifier.
*/

int	apply_tags_c(t_data *data, int c)
{
	int	ret;
	int	filler;

	ret = 0;
	filler = ' ';
	if (data->minus == true)
		data->ret += ((ret = write(1, &c, 1)) != -1) ? ret : 0;
	if (data->check_width == true)
	{
		while (--(data->width) > 0)
		{
			ret = write(1, &filler, 1);
			data->ret += (ret != -1) ? ret : 0;
		}
	}
	if (data->minus == false)
		data->ret += ((ret = write(1, &c, 1)) != -1) ? ret : 0;
	return (1);
}

int	ft_printf_c(t_data *data)
{
	int	c;

	if (data->zero == true\
		|| (data->check_precision == true && data->precision != 0))
		return (-1);
	c = va_arg(data->ap, int);
	if (apply_tags_c(data, c) == -1)
		return (-1);
	return (1);
}
