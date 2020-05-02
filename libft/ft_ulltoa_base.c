/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohlee <yohlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 15:05:09 by yohlee            #+#    #+#             */
/*   Updated: 2020/04/08 16:59:47 by yohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ulltoa_base(unsigned long long n, char *base)
{
	size_t	len;
	size_t	base_len;
	size_t	i;
	char	*result;

	if (!base)
		base = ft_strdup("0123456789");
	base_len = ft_strlen(base);
	if (base_len < 2)
		return (0);
	len = ft_nbrlen_base(n, base_len);
	if (!(result = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	result[len] = '\0';
	i = 0;
	while (i < len)
	{
		result[len - i - 1] = base[n % base_len];
		n /= base_len;
		i++;
	}
	free(base);
	base = 0;
	return (result);
}
