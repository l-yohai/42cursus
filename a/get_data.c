/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohlee <yohlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 23:46:59 by yohlee            #+#    #+#             */
/*   Updated: 2020/05/02 17:29:12 by yohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	init_data(t_data *data)
{
	data->format = 0;
	data->options = 0;
	data->ret = 0;
	data->minus = false;
	data->zero = false;
	data->check_width = false;
	data->width = 0;
	data->check_precision = false;
	data->precision = 0;
	data->specifier = 0;
	return (0);
}

int		is_specifier(int c)
{
	if (c == 'c' || c == 's' || c == 'p'\
		|| c == 'd' || c == 'i' || c == 'u'\
		|| c == 'x' || c == 'X')
		return (1);
	return (0);
}

int	parse_options(t_data *data, char *percent_next)
{
	int	i;

	i = 0;
	if (percent_next[i] == '%')
	{
		if (!(data->options = ft_strndup(percent_next, 1)))
			return (-1);
		return (1);
	}
	while (percent_next[i])
	{
		if (is_specifier(percent_next[i]))
			if (!(data->options = ft_strndup(percent_next, i + 1)))
				return (-1);
		i++;
	}
	return (0);
}

int	get_argument(t_data *data)
{
	int	ret;

	ret = 0;
	if (data->specifier == 'c')
		ret = ft_printf_c(data);
	else if (data->specifier == 's')
		ret = ft_printf_s(data);
	else if (data->specifier == 'd' || data->specifier == 'i')
		ret = ft_printf_di(data);
	// else if (data->specifier == 'p')
	// 	ret = ft_printf_p(data);
	// else if (data->specifier == 'u')
	// 	ret = ft_printf_ux(data);
	// else if (data->specifier == 'x')
	// 	ret = ft_printf_ux(data);
	// else if (data->specifier == 'X')
	// 	ret = ft_printf_ux(data);
	else
		ret = -1;
	return (ret);
}

int	get_data(t_data *data)
{
	int	i;

	i = 0;
	if (data->options[i] == '%')
	{
		ft_putchar('%');
		data->ret++;
		return (1);
	}
	if (!(get_tags(data)))
		return (-1);
	if ((get_argument(data)) < 0)
		return (-1);
	return (1);
}