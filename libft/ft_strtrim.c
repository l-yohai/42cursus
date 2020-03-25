/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohlee <yohlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:20:56 by yohlee            #+#    #+#             */
/*   Updated: 2020/03/01 23:16:23 by yohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** s1: str to be trimmed.
** s2: ref set of chars to trim.
**
** allocate and return a copy of 's1'
** with 'set' removed from beginnig and the end of str.
*/

int		is_set(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	len;

	if (!s1)
		return (NULL);
	if (!set)
		return ((char *)s1);
	i = 0;
	while (is_set(set, s1[i]))
		i++;
	len = ft_strlen(s1);
	while (is_set(set, s1[--len]))
		;
	if (!(str = (char *)malloc(sizeof(char) * (len - i + 2))))
		return (NULL);
	ft_strlcpy(str, s1 + i, len - i + 2);
	return (str);
}
