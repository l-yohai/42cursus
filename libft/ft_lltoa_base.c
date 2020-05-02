/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohlee <yohlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 15:58:19 by yohlee            #+#    #+#             */
/*   Updated: 2020/04/08 19:42:45 by yohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*convert_base(long long n, size_t len, char *base, size_t base_len)
{
	size_t		i;
	char		*result;
	long long	temp;

	if (!(result = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	result[len] = '\0';
	i = 0;
	temp = (n >= 0) ? n : (n * (-1));
	while (i < len)
	{
		if (i + 1 == len && n < 0)
		{
			result[0] = '-';
			break ;
		}
		result[len - i - 1] = base[temp % base_len];
		temp /= base_len;
		i++;
	}
	return (result);
}

char	*ft_lltoa_base(long long n, char *base)
{
	size_t	len;
	size_t	base_len;
	char	*result;

	if (!base)
	{
		free(base);
		base = 0;
		base = ft_strdup("0123456789");
	}
	if (n == LONG_MIN\
		&& ft_strncmp(base, "0123456789", ft_strlen("0123456789")))
		return (ft_strdup("-9223372036854775808"));
	if ((base_len = ft_strlen(base)) < 2)
		return (NULL);
	len = ft_nbrlen_base(n, base_len);
	if (n < 0)
		len++;
	result = convert_base(n, len, base, base_len);
	free(base);
	base = 0;
	return (result);
}
