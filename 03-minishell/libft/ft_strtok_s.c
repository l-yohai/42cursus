/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohlee <yohlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 23:07:01 by yohlee            #+#    #+#             */
/*   Updated: 2020/07/18 23:07:06 by yohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtok_s(char *str, char *sep, int *size)
{
	int		i;
	int		j;
	int		tmp;
	char	*cpy;

	i = 0;
	while (str[i])
	{
		j = 0;
		tmp = i;
		while (sep[j] && str[i] && str[i++] == sep[j++])
			if (!sep[j])
			{
				*size = i;
				cpy = (char *)malloc(tmp+ 1);
				cpy[tmp] = '\0';
				while (--tmp > -1)
					cpy[tmp] = str[tmp];
				return (cpy);
			}
		i = tmp + 1;
	}
	return (0);
}
