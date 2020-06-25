/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_di.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohlee <yohlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 01:57:25 by yohlee            #+#    #+#             */
/*   Updated: 2020/05/08 08:08:54 by yohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*apply_precision_d(t_data *data, char *nbr, char *result)
{
	int	i;
	int	len;

	i = -1;
	if (nbr[0] == '-' && data->precision != -1)
		(data->precision)++;
	len = ft_strlen(nbr);
	if (data->check_precision == true && data->precision > (int)ft_strlen(nbr))
	{
		if (!(result = ft_calloc(data->precision + 1, sizeof(char))))
			return (NULL);
		while (++i < data->precision - len)
			result[i] = '0';
		ft_strlcat(result, nbr, data->precision + 1);
	}
	else
	{
		if (!(result = ft_strdup(nbr)))
			return (NULL);
	}
	return (result);
}

char	*apply_flag_d(t_data *data, char *result, int size)
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
			temp[i] = (data->zero == true) ? '0' : ' ';
		ft_strlcat(temp, result, size + 1);
	}
	free(result);
	result = 0;
	return (temp);
}

int		move_sign(char *result)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (result[i] == ' ')
		i++;
	if (result[i] == '0')
		j = i;
	while (result[i] == '0')
		i++;
	if (result[i] == '-')
	{
		result[i] = result[j];
		result[j] = '-';
	}
	return (1);
}

int		apply_tags_d(t_data *data, int n)
{
	char	*nbr;
	char	*result;
	int		size;

	if (!(nbr = ft_itoa(n)))
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
	if (n < 0 && ft_strchr(result, '0'))
		move_sign(result);
	ft_putstr(result);
	data->ret += ft_strlen(result);
	free(nbr);
	nbr = 0;
	free(result);
	result = 0;
	return (1);
}

int		ft_printf_di(t_data *data)
{
	int	n;
	int	i;

	// if (check_flags(data) == false)
	// 	return (-1);
	n = va_arg(data->ap, int);
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
	if (apply_tags_d(data, n) == -1)
		return (-1);
	return (1);
}
