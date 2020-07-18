/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeong <jujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 22:09:24 by jujeong           #+#    #+#             */
/*   Updated: 2020/03/04 00:23:35 by jujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char		*dest_c;
	const char	*src_c;
	size_t		i;

	if (!dest && !src)
		return (0);
	i = 0;
	dest_c = (char *)dest;
	src_c = (const char *)src;
	if (src < dest)
		while (len-- > 0)
			dest_c[len] = src_c[len];
	else
		while (i < len)
		{
			dest_c[i] = src_c[i];
			i++;
		}
	return (dest);
}
