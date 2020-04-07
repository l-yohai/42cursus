/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohlee <yohlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 06:49:50 by yohlee            #+#    #+#             */
/*   Updated: 2020/04/06 15:06:35 by yohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *, ...);

int	putstr_before_percent(t_data *data, size_t len)
{
	int	ret;

	if (!(ret = write(1, data->format, len)))
		return (-1);
	data->format += ret;
	data->ret += ret;
	return (1);
}

int		check_flag(t_opt *opt)
{
	if ((opt->minus && opt->zero) || (opt->space && opt->plus))
		return (-1);
	return (1);
}

t_opt	*make_new_opt(t_opt *opt)
{
	if (!(opt = (t_opt *)malloc(sizeof(t_opt))))
		return (NULL);
	opt->minus = 0;
	opt->zero = 0;
	opt->sharp = 0;
	opt->space = 0;
	opt->plus = 0;
	opt->width_check = 0;
	opt->width = 0;
	opt->precision_check = 0;
	opt->precision = 0;
	opt->length = 0;
	opt->specifier = 0;
	return (opt);
}

int		is_specifier(int c)
{
	if (c == 'c' || c == 's' || c == 'p'\
		|| c == 'd' || c == 'i' || c == 'u'\
		|| c == 'x' || c == 'X')
		return (1);
	return (0);
}

char	*parse_options(char *percent_next)
{
	int	i;

	i = 0;
	if (percent_next[i] == '%')
		return (ft_strndup(percent_next, 1));
	while (percent_next[i])
	{
		if (is_specifier(percent_next[i]))
			return (ft_strndup(percent_next, i + 1));
		i++;
	}
	return (NULL);
}

t_opt	*get_opt(t_data *data, t_opt *opt)
{
	int	i;

	if (!(opt = make_new_opt(opt)))
		return (NULL);
	i = 0;
	while (data->options[i])
	{
		if (get_opt_flags(data, &opt, &i))
			i++;
		else if (get_opt_width(data, &opt, &i))
			i++;
		else if (get_opt_precision(data, &opt, &i))
			i++;
		else if (get_opt_length(data, &opt, &i))
			i++;
		else if (get_opt_specifier(data, &opt, &i))
			i++;
		else
			return (NULL);
	}
	return (opt);
}

int	get_argument(t_data *data, t_opt *opt)
{
	int	ret;

	ret = -1;
	if (opt->specifier == 'c')
		ret = ft_printf_c(data, opt);
	if (opt->specifier == 's')
		ret = ft_printf_s(data, opt);
	return (ret);
}

int		get_data(t_data *data)
{
	int		i;
	int		ret;
	t_opt	*opt;

	i = 0;
	if (data->options[i] == '%')
	{
		ft_putchar('%');
		data->ret++;
		return (1);
	}
	ret = 0;
	opt = 0;
	if (!(opt = get_opt(data, opt)))
		return (-1);
	ret = get_argument(data, opt);
	free(opt);
	opt = 0;
	return (ret);
}

int	ft_print(t_data	*data)
{
	char	*temp;
	char	*percent;
	int		ret;

	temp = (char *)data->format;
	percent = 0;
	ret = 0;
	while (*temp)
	{
		if ((percent = ft_strchr(temp, '%')))
		{
			data->ret += write(1, temp, percent - temp);
			if (!(data->options = parse_options(percent + 1))\
					|| !(ret = get_data(data)))
				return (-1);
			temp = percent + ft_strlen(data->options) + 1;
			free(data->options);
			data->options = 0;
		}
		else
		{
			data->ret += write(1, temp, ft_strlen(temp));
			break ;
		}
	}
	return (data->ret);
}

int	ft_printf(const char *format, ...)
{
	t_data	data;

	va_start(data.args, format);
	data.format = format;
	data.ret = 0;
	data.options = 0;
	if (!ft_print(&data))
		data.ret = -1;
	va_end(data.args);
	return (data.ret);
}

int		main()
{
	ft_printf("|%10c|\n", 'A');
	ft_printf("|%10s|\n", "ABCDE");
}
