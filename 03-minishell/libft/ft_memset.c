/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeong <jujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 20:27:28 by jujeong           #+#    #+#             */
/*   Updated: 2020/03/04 00:23:48 by jujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memset(void *ptr, int value, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)ptr;
	while (i < len)
		str[i++] = value;
	return (ptr);
}
