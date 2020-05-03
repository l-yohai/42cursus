/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohlee <yohlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 22:17:07 by yohlee            #+#    #+#             */
/*   Updated: 2020/05/03 22:45:45 by yohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** flag '0' results in undefined behavior with 's' conversion specifier.
*/

char	*apply_precision_s(t_data *data, char *s, char *result)
{
	if (data->check_precision == true)
	{
		if (data->precision < (int)ft_strlen(s))
		{
			if (!(result = ft_strndup(s, data->precision)))
				return (NULL);
		}
		else
		{
			if (!(result = ft_strdup(s)))
				return (NULL);
		}
	}
	else
	{
		if (!(result = ft_strdup(s)))
			return (NULL);
	}
	return (result);
}

char	*apply_flag_s(t_data *data, char *result, int size)
{
	int		len;
	int		i;
	char	*temp;

	len = ft_strlen(result);
	i = -1;
	if (!(temp = ft_calloc(size + 1, sizeof(char))))
		return (NULL);
	if (data->minus == true)
	{
		ft_strlcpy(temp, result, len + 1);
		i = len - 1;
		while (++i < size)
			temp[i] = ' ';
		temp[i] = '\0';
	}
	else
	{
		while (++i < size - len)
			temp[i] = ' ';
		ft_strlcat(temp, result, size + 1);
	}
	free(result);
	result = 0;
	return (temp);
}

int		apply_tags_s(t_data *data, char *s)
{
	char	*result;
	int		size;

	result = 0;
	size = 0;
	if (!(result = apply_precision_s(data, s, result)))
		return (-1);
	if ((size = apply_width(data, result)) == -1)
		return (-1);
	if (!(result = apply_flag_s(data, result, size)))
		return (-1);
	ft_putstr(result);
	data->ret += ft_strlen(result);
	free(result);
	result = 0;
	return (1);
}

int		ft_printf_s(t_data *data)
{
	char	*s;

	if (data->zero == true)
		return (-1);
	if ((s = va_arg(data->ap, char *)))
		s = ft_strdup(s);
	else
		s = ft_strdup("(null)");
	if (apply_tags_s(data, s) == -1)
		return (-1);
	free(s);
	s = 0;
	return (1);
}
