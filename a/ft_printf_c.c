/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohlee <yohlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 17:02:36 by yohlee            #+#    #+#             */
/*   Updated: 2020/04/06 14:56:58 by yohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*apply_flags_c(char *result, t_opt *opt, int *ret)
{
	char	filler;

	if (!opt)
		return (NULL);
	if (opt->width <= 1)
		return (ft_strdup(""));
	else
		if (!(result = (char *)malloc(sizeof(char) * (opt->width))))
			return (NULL);
	*ret = opt->width;
	filler = (opt->zero) ? '0' : ' ';
	ft_memset(result, filler, opt->width - 1);
	result[opt->width - 1] = '\0';
	return (result);
}

int	apply_options_c(char c, t_data *data, t_opt *opt)
{
	char	*result;
	int		ret;

	if (!data || !opt)
		return (-1);
	result = 0;
	ret = 1;
	result = apply_flags_c(result, opt, &ret);
	data->ret += ret;
	if (opt->minus)
	{
		ft_putchar(c);
		ft_putstr(result);
	}
	else
	{
		ft_putstr(result);
		ft_putchar(c);
	}
	free(result);
	result = 0;
	return (ret);
}

int	ft_printf_wc(wint_t wc, t_data *data, t_opt *opt)
{
	char	*result;
	wchar_t	wstr[2];
	int		ret;

	if (!data || !opt)
		return (-1);
	wstr[0] = wc;
	wstr[1] = L'\0';
	result = ft_wchars_to_str(wstr);
	if (!result)
		return (-1);
	ret = print_s(&result, data, opt);
	free(result);
	result = 0;
	return (ret);
}

int	ft_printf_c(t_data *data, t_opt *opt)
{
	int		ret;
	int		c;
	wint_t	wc;

	if (!data || !opt || !check_flag(opt) || opt->sharp || opt->space\
		|| opt->plus || opt->precision || opt->precision_asterisk)
		return (-1);
	if (opt->length == LENGTH_L)
	{
		if ((wc = va_arg(data->args, wint_t)) != L'\0')
			return (ft_printf_wc(wc, data, opt));
		c = wc;
	}
	else
		c = va_arg(data->args, int);
	if (!(ret = apply_options_c(c, data, opt)))
		return (-1);
	return (ret);
}
