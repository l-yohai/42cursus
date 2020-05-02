/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_di.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohlee <yohlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 01:57:25 by yohlee            #+#    #+#             */
/*   Updated: 2020/05/02 21:12:43 by yohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*apply_precision(t_data *data, char *nbr, char *result)
{
	int	i;
	int	len;

	i = -1;
	len = ft_strlen(nbr);
	if (data->check_precision == true)
	{
		if (nbr[0] == '-')
			(data->precision)++;
		if (data->precision > ft_strlen(nbr))
		{
			if (!(result = ft_calloc(data->precision + 1, sizeof(char))))
				return (NULL);
			while (++i < data->precision - len)
				result[i] = '0';
			ft_strlcat(result, nbr, data->precision + 1);
		}
	}
	else
	{
		if (!(result = ft_strdup(nbr)))
			return (NULL);
	}
	return (result);
}

int	apply_width(t_data *data, char *result)
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

char	*apply_flag(t_data *data, char *result, int size)
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
			temp[i] = (!data->precision && data->zero) ? '0' : ' ';
		ft_strlcat(temp, result, size + 1);
	}
	free(result);
	result = 0;
	return (temp);
}

int	move_sign(char *result)
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

int	apply_tags(t_data *data, int n)
{
	char	*result;
	char	*nbr;
	int		size;

	result = 0;
	nbr = ft_itoa(n);
	size = 0;
	if (!(result = apply_precision(data, nbr, result)))
		return (-1);
	if ((size = apply_width(data, result)) == -1)
		return (-1);
	if (!(result = apply_flag(data, result, size)))
		return (-1);
	if (n < 0 && (data->zero == true || data->check_precision == true))
		move_sign(result);
	ft_putstr(result);
	data->ret += ft_strlen(result);
	free(nbr);
	nbr = 0;
	free(result);
	result = 0;
	return (1);
}

int	ft_printf_di(t_data *data)
{
	int	n;

	if (check_flags(data) == false)
		return (-1);
	n = va_arg(data->ap, int);
	if (apply_tags(data, n) == -1)
		return (-1);
	return (1);
}