/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohlee <yohlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 13:22:13 by yohlee            #+#    #+#             */
/*   Updated: 2020/04/07 11:04:27 by yohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_s(char **result, t_data *data, t_opt *opt)
{
	size_t	len;

	if (!result || !data || !opt)
		return (-1);
	if (*result == 0 && !(*result = ft_strdup("(null)")))
		return (-1);
	len = ft_strlen(*result);

	if (opt->precision_check)
		if (!apply_precision(result, &len, opt))
			return (-1);
	if (opt->width_check)
		if (!apply_width(result, &len, opt))
			return (-1);
	data->ret += len;
	return (write(1, *result, ft_strlen(*result)));
}

int	ft_printf_s(t_data *data, t_opt *opt)
{
	char	*result;
	wchar_t	*wstr;
	int		ret;

	if (!data || !opt)
		return (-1);
	result = 0;
	wstr = 0;
	ret = 0;
	if (opt->length == LENGTH_L)
	{
		wstr = va_arg(data->args, wchar_t *);
		result = ft_wchars_to_str(wstr);
	}
	else
		if ((result = va_arg(data->args, char *)))
			result = ft_strdup(result);
	ret = print_s(&result, data, opt);
	free(result);
	result = 0;
	return (ret);
}
