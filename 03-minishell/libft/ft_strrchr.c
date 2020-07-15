/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeong <jujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:27:19 by jujeong           #+#    #+#             */
/*   Updated: 2020/03/04 00:28:08 by jujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*s;

	i = 0;
	s = (char *)str;
	while (s[i])
		i++;
	if (c == 0)
		return (&s[i]);
	while (i-- > 0)
	{
		if (s[i] == c)
			return (&s[i]);
	}
	return (0);
}
