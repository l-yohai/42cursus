/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeong <jujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 21:40:48 by jujeong           #+#    #+#             */
/*   Updated: 2020/03/04 00:25:11 by jujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char		num[20];
	long long	l;
	int			len;

	l = (long long)n;
	len = (l > 0) ? 0 : 1;
	l = (l > 0) ? l : l * -1;
	while (n)
		n = len++ ? n / 10 : n / 10;
	num[len] = '\0';
	while (l)
	{
		num[--len] = l % 10 + '0';
		l = l / 10;
	}
	if (len != 0 && num[1] == '\0')
		num[0] = '0';
	if (len != 0 && num[1] != '\0')
		num[0] = '-';
	write(fd, num, ft_strlen(num));
}
