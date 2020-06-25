/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohlee <yohlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:21:09 by yohlee            #+#    #+#             */
/*   Updated: 2020/04/15 23:45:01 by yohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nbrlen(long long n)
{
	int	len;

	len = 1;
	if (n < 0)
		n *= -1;
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int			len;
	char		*result;
	int			i;
	long long	temp;

	len = ft_nbrlen((long long)n);
	if (n < 0)
		len++;
	if (!(result = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	temp = (n >= 0) ? (long long)n : (long long)n * (-1);
	while (i < len)
	{
		if (i == len - 1 && n < 0)
		{
			result[0] = '-';
			break ;
		}
		result[len - i - 1] = temp % 10 + '0';
		temp /= 10;
		i++;
	}
	result[len] = 0;
	return (result);
}
