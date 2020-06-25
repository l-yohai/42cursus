/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohlee <yohlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 00:16:36 by yohlee            #+#    #+#             */
/*   Updated: 2020/05/08 05:14:56 by yohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		apply_tags_ux(t_data *data, unsigned int n, char *base)
{
	char	*nbr;
	char	*result;
	int		size;

	if (!(nbr = ft_uitoa_base(n, base)))
		return (-1);
	result = 0;
	size = 0;
	if (!(result = apply_precision_d(data, nbr, result)))
		return (-1);
	if ((size = apply_width(data, result)) == -1)
		return (-1);
	if (!(result = apply_flag_d(data, result, size)))
		return (-1);
	check_flag_d(data, result);
	ft_putstr(result);
	data->ret += ft_strlen(result);
	free(nbr);
	nbr = 0;
	free(result);
	result = 0;
	return (1);
}

int		ft_printf_ux(t_data *data, char *base)
{
	unsigned int	n;
	int				i;

	if (check_flags(data) == false)
		return (-1);
	n = va_arg(data->ap, unsigned int);
	i = -1;
	if (n == 0 && data->check_precision && data->precision == 0)
	{
		if (data->check_width)
		{
			while (++i < data->width)
				ft_putchar(' ');
			data->ret += i;
		}
		return (1);
	}
	if (apply_tags_ux(data, n, base) == -1)
		return (-1);
	return (1);
}
