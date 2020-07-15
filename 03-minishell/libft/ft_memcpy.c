/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeong <jujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 21:05:07 by jujeong           #+#    #+#             */
/*   Updated: 2020/04/06 13:49:10 by jujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	size_t		i;
	char		*dest_c;
	const char	*src_c;

	if (!dest && !src)
		return (0);
	i = 0;
	dest_c = (char *)dest;
	src_c = (const char *)src;
	while (i < len)
	{
		dest_c[i] = src_c[i];
		i++;
	}
	return (dest);
}
