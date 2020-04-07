/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_len.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohlee <yohlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 13:21:32 by yohlee            #+#    #+#             */
/*   Updated: 2020/04/06 13:21:50 by yohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_wchar_utf8_len(wint_t c)
{
	if (c < 128)
		return (1);
	if (c < 2048)
		return (2);
	if (c < 65536)
		return (3);
	if (c < 2097152)
		return (4);
	return (0);
}

size_t	ft_wstr_utf8_len(const wchar_t *s)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (s[i] != L'\0')
	{
		len += ft_wchar_utf8_len(s[i]);
		i++;
	}
	return (len);
}
