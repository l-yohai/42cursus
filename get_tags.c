/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohlee <yohlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 23:45:59 by yohlee            #+#    #+#             */
/*   Updated: 2020/05/01 02:10:59 by yohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_opt_flags(t_data *data, int *i)
{
	if (data->options[*i] == '-')
		data->minus = true;
	else if (data->options[*i] == '0')
		data->zero = true;
	else
		return (0);
	return (1);
}

int	get_opt_width(t_data *data, int *i)
{
	if (data->options[*i] == '*')
	{
		data->check_width = true;
		data->width = va_arg(data->ap, int);
	}
	else if (data->options[*i] >= '1' && data->options[*i] <= '9')
	{
		data->check_width = true;
		data->width = ft_atoi(&data->options[*i]);
		(*i) += ft_nbrlen(data->width) - 1;
	}
	else
		return (0);
	return (1);
}

int	get_opt_precision(t_data *data, int *i)
{
	if (data->options[*i] == '.')
	{
		if (data->options[*i + 1] >= '0' && data->options[*i + 1] <= '9')
		{
			data->check_precision = true;
			data->precision = ft_atoi(&data->options[*i + 1]);
			(*i) += ft_nbrlen(data->precision);
		}
		else if (data->options[++(*i)] == '*')
		{
			data->check_precision = true;
			data->precision = va_arg(data->ap, int);
		}
	}
	else
		return (0);
	return (1);
}

int	get_opt_specifier(t_data *data, int *i)
{
	if (is_specifier(data->options[*i]))
		data->specifier = data->options[*i];
	else
		return (0);
	return (1);
}

int	get_tags(t_data *data)
{
	int	i;

	i = 0;
	while (data->options[i])
	{
		if (get_opt_flags(data, &i))
			i++;
		else if (get_opt_width(data, &i))
			i++;
		else if (get_opt_precision(data, &i))
			i++;
		else if (get_opt_specifier(data, &i))
			i++;
		else
			return (-1);
	}
	return (1);
}
