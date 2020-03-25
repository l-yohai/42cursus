/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohlee <yohlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:21:09 by yohlee            #+#    #+#             */
/*   Updated: 2020/03/01 17:02:33 by yohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*sort_minus(char *str)
{
	int		len;
	int		i;
	char	c;

	len = ft_strlen(str);
	i = 0;
	c = str[len - 1];
	while (i < len - 1)
	{
		str[len - i - 1] = str[len - i - 2];
		i++;
	}
	str[len] = c;
	str[len + 1] = '\0';
	str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	int			len;
	char		*str;
	int			i;
	long long	temp;

	temp = (n >= 0) ? n : (long long)n * (-1);
	len = ft_nbrlen(temp);
	if (!(str = (char *)malloc(sizeof(char) * (len + 2))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = temp % 10 + '0';
		temp /= 10;
		i++;
	}
	str[i] = '\0';
	str = ft_rev_arr(str);
	if (n < 0)
		str = sort_minus(str);
	return (str);
}
