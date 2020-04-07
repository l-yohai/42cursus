/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchars_to_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohlee <yohlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 13:20:18 by yohlee            #+#    #+#             */
/*   Updated: 2020/04/06 13:27:36 by yohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_utf8_2byte(char *dst, wint_t c)
{
	dst[0] = (c >> 6) | 0b11000000;
	dst[1] = (c & 0b111111) | 0b10000000;
	return (2);
}

int	print_utf8_3byte(char *dst, wint_t c)
{
	dst[0] = (c >> 12) | 0b11100000;
	dst[1] = ((c >> 6) & 0b111111) | 0b10000000;
	dst[2] = (c & 0b111111) | 0b10000000;
	return (3);
}

int	print_utf8_4byte(char *dst, wint_t c)
{
	dst[0] = (c >> 18) | 0b11110000;
	dst[1] = ((c >> 12) & 0b111111) | 0b10000000;
	dst[2] = ((c >> 6) & 0b111111) | 0b10000000;
	dst[3] = (c & 0b111111) | 0b10000000;
	return (4);
}

int	wchar_to_str(char *dst, wint_t c)
{
	if (c < 128)
	{
		dst[0] = c;
		return (1);
	}
	if (c < 2048)
		return (print_utf8_2byte(dst, c));
	if (c < 65536)
		return (print_utf8_3byte(dst, c));
	if (c < 2097152)
		return (print_utf8_4byte(dst, c));
	return (-1);
}

char	*ft_wchars_to_str(const wchar_t *wstr)
{
	char	*str;
	size_t	len;
	size_t	i;
	size_t	j;
	int		temp;

	if (!wstr)
		return (NULL);
	len = ft_wstr_utf8_len(wstr);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (wstr[i] != L'\0')
	{
		if ((temp = wchar_to_str(str + j, wstr[i])) == -1)
		{
			free(str);
			return (NULL);
		}
		j += temp;
		i++;
	}
	str[len] = '\0';
	return (str);
}
