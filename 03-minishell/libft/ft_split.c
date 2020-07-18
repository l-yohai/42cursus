/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohlee <yohlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 20:00:07 by jujeong           #+#    #+#             */
/*   Updated: 2020/07/18 03:33:48 by yohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_split_free(char **str, int i)
{
	while (i > -1)
		free(str[i--]);
	free(str);
	return (-1);
}

static int	ft_split_save(char **str, char const *s, char c)
{
	int i;
	int j;
	int k;
	int n;
	int size;

	i = 0;
	j = 0;
	n = 0;
	size = 0;
	while (s[i] || n > 0)
		if (s[i] && s[i++] != c)
			size = (n++ > 0) ? size : i - 1;
		else if (n > 0)
		{
			k = 0;
			if (!(str[j] = malloc(sizeof(char) * (n + 1))))
				return (ft_split_free(str, j));
			while (k++ <= n)
				str[j][k - 1] = (k - 1 == n) ? '\0' + (n *= 0) : s[size++];
			j++;
		}
	return (j);
}

static char	**ft_split_malloc(const char *s, char c)
{
	char	**str;
	int		len;
	int		i;
	int		j;

	len = 0;
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i++] != c)
			j++;
		else if (j > 0)
		{
			j = 0;
			len++;
		}
	}
	if (j > 0)
		len++;
	if (!(str = malloc(sizeof(char *) * (len + 1))))
		return (0);
	return (str);
}

char		**ft_split(char const *s, char c)
{
	char	**str;
	int		len;

	if (!s)
		return (0);
	if (!(str = ft_split_malloc(s, c)))
		return (0);
	if ((len = ft_split_save(str, s, c)) == -1)
		return (0);
	str[len] = 0;
	return (str);
}
