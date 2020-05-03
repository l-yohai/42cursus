/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_tags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohlee <yohlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 13:08:11 by yohlee            #+#    #+#             */
/*   Updated: 2020/05/03 22:43:00 by yohlee           ###   ########.fr       */
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
