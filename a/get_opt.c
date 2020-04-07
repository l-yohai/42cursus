/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohlee <yohlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 16:54:02 by yohlee            #+#    #+#             */
/*   Updated: 2020/04/04 17:10:42 by yohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_opt_flags(t_data *data, t_opt **opt, int *i)
{
	if (data->options[*i] == '-')
		(*opt)->minus++;
	else if (data->options[*i] == '0')
		(*opt)->zero++;
	else if (data->options[*i] == '#')
		(*opt)->sharp++;
	else if (data->options[*i] == ' ')
		(*opt)->space++;
	else if (data->options[*i] == '+')
		(*opt)->plus++;
	else
		return (0);
	return (1);
}

int	get_opt_width(t_data *data, t_opt **opt, int *i)
{
	if (data->options[*i] == '*')
	{
		(*opt)->width_check++;
		(*opt)->width = va_arg(data->args, int);
	}
	else if (data->options[*i] >= '1' && data->options[*i] <= '9')
	{
		(*opt)->width_check++;
		(*opt)->width = ft_atoi(&data->options[*i]);
		(*i) += ft_nbrlen((*opt)->width) - 1;
	}
	else
		return (0);
	return (1);
}

int	get_opt_precision(t_data *data, t_opt **opt, int *i)
{
	if (data->options[*i] == '.')
	{
		if (data->options[*i + 1] >= '0' && data->options[*i + 1] <= '9')
		{
			(*opt)->precision_check++;
			(*opt)->precision = ft_atoi(&data->options[*i + 1]);
			(*i) += ft_nbrlen((*opt)->precision);
		}
		else if (data->options[++(*i)] == '*')
		{
			(*opt)->precision_check++;
			(*opt)->precision = va_arg(data->args, int);
		}
	}
	else
		return (0);
	return (1);
}

int	get_opt_length(t_data *data, t_opt **opt, int *i)
{
	if (data->options[*i] == 'l' && data->options[*i + 1] != 'l')
		(*opt)->length = LENGTH_L;
	else if (data->options[*i] == 'l' && data->options[*i + 1] == 'l')
		(*opt)->length = LENGTH_LL;
	else if (data->options[*i] == 'h' && data->options[*i + 1] != 'h')
		(*opt)->length = LENGTH_H;
	else if (data->options[*i] == 'h' && data->options[*i + 1] == 'h')
		(*opt)->length = LENGTH_HH;
	else
		return (0);
	return (1);
}

int	get_opt_specifier(t_data *data, t_opt **opt, int *i)
{
	if (is_specifier(data->options[*i]))
		(*opt)->specifier = data->options[*i];
	else
		return (0);
	return (1);
}
