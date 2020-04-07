/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohlee <yohlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 06:50:31 by yohlee            #+#    #+#             */
/*   Updated: 2020/04/06 15:05:12 by yohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <wchar.h>
# include "libft/libft.h"

////
#include <stdio.h>
////

# define LENGTH_L 1
# define LENGTH_LL 2
# define LENGTH_H 3
# define LENGTH_HH 4

typedef struct	s_data
{
	va_list		args;
	const char	*format;
	char		*options;
	int			ret;
}				t_data;

typedef struct	s_opt
{
	int			minus;
	int			zero;
	int			sharp;
	int			space;
	int			plus;
	int			width_check;
	int			width_asterisk;
	int			width;
	int			precision_check;
	int			precision;
	int			precision_asterisk;
	int			length;
	int			specifier;
}				t_opt;


int		check_flag(t_opt *opt);
int		is_specifier(int c);



/*
** get_opt.c
*/

int				get_opt_flags(t_data *data, t_opt **opt, int *i);
int				get_opt_width(t_data *data, t_opt **opt, int *i);
int				get_opt_precision(t_data *data, t_opt **opt, int *i);
int				get_opt_length(t_data *data, t_opt **opt, int *i);
int				get_opt_specifier(t_data *data, t_opt **opt, int *i);

/*
** ft_printf_c.c
*/

char			*apply_flags_c(char *result, t_opt *opt, int *ret);
int				apply_options_c(char c, t_data *data, t_opt *opt);
int				ft_printf_wc(wint_t wc, t_data *data, t_opt *opt);
int				ft_printf_c(t_data *data, t_opt *opt);

/*
** wchars_to_str.c
*/

int				print_utf8_2byte(char *dst, wint_t c);
int				print_utf8_3byte(char *dst, wint_t c);
int				print_utf8_4byte(char *dst, wint_t c);
int				wchar_to_str(char *dst, wint_t c);
char			*ft_wchars_to_str(const wchar_t *wstr);


/*
** w_len.c
*/

size_t			ft_wchar_utf8_len(wint_t c);
size_t			ft_wstr_utf8_len(const wchar_t *s);

/*
** apply_options.c
*/

int				apply_flag_sharp(char **result, size_t *len, t_opt *opt, int is_zero);
int				apply_width(char **result, size_t *len, t_opt *opt);
int				apply_precision2(char **result, size_t *len, t_opt *opt);
int				apply_precision(char **result, size_t *len, t_opt *opt);

/*
** ft_printf_s.c
*/

int				print_s(char **result, t_data *data, t_opt *opt);
int				ft_printf_s(t_data *data, t_opt *opt);

/*
** ft_printf_d.c
*/

/*
** ft_printf_p.c
*/

/*
** ft_printf_u.c
*/

/*
** ft_printf_x.c
*/

/*
** ft_printf_X.c
*/

#endif
