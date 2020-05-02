/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_plus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohlee <yohlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 02:06:20 by yohlee            #+#    #+#             */
/*   Updated: 2020/03/29 02:11:42 by yohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*sort_mark(long long n, char *str)
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
	str[0] = (n >= 0) ? '+' : '-';
	return (str);
}

char	*ft_itoa_plus(int n)
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
	str = sort_mark((long long)n, str);
	return (str);
}
