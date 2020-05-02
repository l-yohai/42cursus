/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohlee <yohlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 21:23:57 by yohlee            #+#    #+#             */
/*   Updated: 2020/05/02 18:12:31 by yohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdbool.h>
# include "./libft/libft.h"

# define DIGIT_STR "0123456789"
# define HEX_STR_LOWER "0123456789abcdef"
# define HEX_STR_UPPER "0123456789ABCDEF"

typedef struct	s_data
{
	va_list		ap;
	char		*format;
	char		*options;
	int			ret;
	bool		minus;
	bool		zero;
	bool		check_width;
	int			width;
	bool		check_precision;
	int			precision;
	int			specifier;
}				t_data;

/*
** ft_printf.c
*/

int	ft_printf(const char *format, ...);

/*
** get_data.c
*/

int	init_data(t_data *data);
int		is_specifier(int c);
int	parse_options(t_data *data, char *percent_next);
int	get_argument(t_data *data);
int	get_data(t_data *data);

/*
** get_tags.c
*/

int	get_opt_flags(t_data *data, int *i);
int	get_opt_precision(t_data *data, int *i);
int	get_opt_specifier(t_data *data, int *i);
int	get_tags(t_data *data);

/*
** apply_tags.c
*/

bool	check_flags(t_data *data);

/*
** ft_printf_c.c
*/

int		apply_tags_c(t_data *data, int c);
int		ft_printf_c(t_data *data);

/*
** ft_printf_s.c
*/

char	*apply_precision_s(t_data *data, char *s, char *result);
int	apply_width_s(t_data *data, char *result);
char	*apply_flag_s(t_data *data, char *result, int size);
int	apply_tags_s(t_data *data, char *s);
int	ft_printf_s(t_data *data);

/*
** ft_printf_di.c
*/
char	*apply_precision(t_data *data, char *nbr, char *result);
int	apply_width(t_data *data, char *result);
char	*apply_flag(t_data *data, char *result, int size);
int	apply_tags(t_data *data, int n);
int	move_sign(char *result);
int	ft_printf_di(t_data *data);


#endif
