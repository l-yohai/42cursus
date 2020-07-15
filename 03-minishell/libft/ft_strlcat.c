/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeong <jujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 13:51:48 by jujeong           #+#    #+#             */
/*   Updated: 2020/03/04 00:26:40 by jujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t len)
{
	int		i;
	size_t	dest_len;

	i = -1;
	dest_len = 0;
	if (!len)
		return (ft_strlen(src));
	while (dest[dest_len])
		dest_len++;
	while (src[++i] && i + dest_len < len - 1)
		dest[dest_len + i] = src[i];
	dest[dest_len + i] = '\0';
	while (src[i])
		i++;
	if (dest_len > len)
		return (len + i);
	return (dest_len + i);
}
