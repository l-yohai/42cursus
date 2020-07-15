/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeong <jujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 21:53:51 by jujeong           #+#    #+#             */
/*   Updated: 2020/03/04 00:21:30 by jujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t len)
{
	unsigned char		*dest_c;
	const unsigned char	*src_c;
	size_t				i;

	i = 0;
	dest_c = (unsigned char *)dest;
	src_c = (const unsigned char *)src;
	while (i < len)
	{
		dest_c[i] = src_c[i];
		i++;
		if (src_c[i - 1] == (unsigned char)c)
			return (dest + i);
	}
	return (0);
}
