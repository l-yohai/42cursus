/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeong <jujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 12:46:08 by jujeong           #+#    #+#             */
/*   Updated: 2020/03/04 00:21:51 by jujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int c, size_t len)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	u_c;

	i = 0;
	str = (unsigned char *)ptr;
	u_c = (unsigned char)c;
	while (i < len)
	{
		if (str[i] == u_c)
			return (str + i);
		i++;
	}
	return (0);
}
