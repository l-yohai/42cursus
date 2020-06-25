/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohlee <yohlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 21:17:30 by yohlee            #+#    #+#             */
/*   Updated: 2020/05/08 08:05:24 by yohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print(t_data *data)
{
	char	*percent;
	int		ret;

	ret = 0;
	while (*(data->format))
	{
		if ((percent = ft_strchr(data->format, '%')))
		{
			data->ret += ((ret = write(1, data->format,\
									percent - data->format)) != -1) ? ret : 0;
			if (parse_options(data, percent + 1) == -1 || get_data(data) == -1)
				return (-1);
		}
		else
		{
			data->ret += ((ret = write(1, data->format,\
									ft_strlen(data->format))) != -1) ? ret : 0;
			break ;
		}
		data->format = percent + ft_strlen(data->options) + 1;
		free(data->options);
		init_data(data);
	}
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	t_data	data;

	if (!format)
		return (-1);
	va_start(data.ap, format);
	init_data(&data);
	data.format = (char *)format;
	data.ret = 0;
	if (ft_print(&data) == -1)
		data.ret = -1;
	va_end(data.ap);
	return (data.ret);
}
