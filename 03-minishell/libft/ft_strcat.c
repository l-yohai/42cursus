/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohlee <yohlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 23:05:15 by yohlee            #+#    #+#             */
/*   Updated: 2020/07/18 23:05:24 by yohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *src, char *dst)
{
	char	*str;

	str = src;
	while (*src)
		src++;
	while (*dst)
		*src++ = *dst++;
	*src = '\0';
	return (str);
}
