/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohlee <yohlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 23:06:27 by yohlee            #+#    #+#             */
/*   Updated: 2020/07/18 23:06:32 by yohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtok(char *str, char sep)
{
	int		i;
	char	*ret;

	i = 0;
	while (str[i] && str[i] != sep)
	{
		i++;
	}
	ret = (char *)malloc(i + 1);
	ft_strlcpy(ret, str, i + 1);
	return (ret);
}
