/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeong <jujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 00:14:22 by jujeong           #+#    #+#             */
/*   Updated: 2020/04/08 13:00:56 by jujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	check_over_range(unsigned long long num, int m)
{
	if (num > LLONG_MAX - 1 && m == -1)
		return (0);
	if (num > LLONG_MAX && m == 1)
		return (-1);
	return (num * m);
}

int			ft_atoi(const char *str)
{
	int					m;
	unsigned long long	num;

	m = 1;
	num = 0;
	while (*str && (*str == ' ' || *str == '\t' || *str == '\n' || \
		*str == '\v' || *str == '\f' || *str == '\r'))
		str++;
	if (*str == '-')
		m = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && *str >= '0' && *str <= '9')
	{
		num = num * 10 + *str - '0';
		str++;
	}
	return (check_over_range(num, m));
}
