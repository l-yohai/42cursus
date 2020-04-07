/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohlee <yohlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 14:55:48 by yohlee            #+#    #+#             */
/*   Updated: 2020/04/07 11:03:05 by yohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	apply_flag_sharp(char **result, size_t *len, t_opt *opt, int is_zero)
{
	char	*temp;

	if (!result || !*result || !opt)
		return (-1);
	if (!opt->sharp)
		return (1);
	if (ft_strchr("xX", opt->specifier) && !is_zero)
	{
		if (!(temp = (char *)malloc(sizeof(char) * (*len + 3))))
			return (-1);
		ft_strlcpy(temp, opt->specifier == 'x' ? "0x" : "0X", 3);
		ft_strlcpy(temp + 2, *result, *len + 1);
		free(*result);
		*result = temp;
		*len += 2;
		return (1);
	}
	return (1);
}

int		apply_width(char **result, size_t *len, t_opt *opt)
{
	char	*temp;

	if (!result || !*result || !opt | !len)
		return (-1);
	if (*len >= (size_t)opt->width)
		return (1);
	if (!(temp = malloc(opt->width + 1)))
		return (-1);
	if (opt->minus)
	{
		ft_strlcpy(temp, *result, *len + 1);
		ft_memset(temp + *len, ' ', opt->width - *len);
		temp[opt->width] = '\0';
	}
	else
	{
		ft_memset(temp, opt->zero && (opt->precision < 0 ||
				ft_strchr("eE", opt->specifier)) ? '0' : ' ',
				opt->width - *len);
		ft_strlcpy(temp + opt->width - *len, *result, *len + 1);
	}
	free(*result);
	*result = temp;
	*len = opt->width;
	return (1);
}

 int	apply_precision2(char **result, size_t *len, t_opt *opt)
{
	char	*temp;

	if (ft_strchr("diuxX", opt->specifier))
	{
		if (*len < (size_t)opt->precision)
		{
			if (!(temp = malloc(opt->precision + 1)))
				return (-1);
			ft_memset(temp, '0', opt->precision - *len);
			ft_strlcpy(temp + opt->precision - *len, *result, *len + 1);
			free(*result);
			*result = temp;
			*len = opt->precision;
		}
		else if (opt->precision == 0)
		{
			if (!(temp = ft_strdup("")))
				return (-1);
			free(*result);
			*result = temp;
			*len = opt->precision;
		}
		return (1);
	}
	return (1);
}

int		apply_precision(char **result, size_t *len, t_opt *opt)
{
	char	*temp;

	if (!result || !*result || !opt)
		return (-1);
	if (opt->precision < 0)
		return (1);
	if (opt->specifier == 's')
	{
		if (*len > (size_t)opt->precision)
		{
			temp = 0;
			if (!(temp = ft_strndup(*result, opt->precision)))
				return (-1);
			free(*result);
			*result = temp;
			*len = opt->precision;
		}
		return (1);
	}
	return (apply_precision2(result, len, opt));
}
