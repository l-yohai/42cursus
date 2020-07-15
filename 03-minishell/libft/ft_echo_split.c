/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeong <jujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 20:00:07 by jujeong           #+#    #+#             */
/*   Updated: 2020/07/15 13:48:49 by jujeong          ###   ########.fr       */
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
	int		i;
	int		j;
	int		k;
	int		n;
	int		size;
	int		quote;

	i = 0;
	j = 0;
	n = 0;
	size = 0;
	quote = 0;
	while (s[i] || n > 0)
	{
		if (s[i] == '\'' && quote == 0)
			quote = 1;
		if (s[i] == '\"' && quote == 0)
			quote = 2;
		if (s[i] == '\'' && quote == 1)
			quote = 3;
		if (s[i] == '\"' && quote == 2)
			quote = 3;
		if ((s[i] && s[i++] != c) || (quote == 1 || quote == 2))
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
	}
	return (j);
}

static char	**ft_split_malloc(const char *s, char c)
{
	char	**str;
	int		len;
	int		i;
	int		j;
	int		quote;

	len = 0;
	i = 0;
	j = 0;
	quote = 0;
	while (s[i])
	{
		if (s[i] == '\'' && quote == 0)
			quote = 1;
		if (s[i] == '\"' && quote == 0)
			quote = 2;
		if (s[i] == '\'' && quote == 1)
			quote = 3;
		if (s[i] == '\"' && quote == 2)
			quote = 3;
		if (s[i++] != c || (quote == 1 || quote == 2))
		{
			//printf("s[i] = %c, quote = %d, len = %d\n", s[i], quote, len);
			j++;
		}
		else if (j > 0)
		{
			quote = 0;
			j = 0;
			len++;
		}
	}
	if (j > 0)
		len++;
	//printf("len : %d\n", len);
	if (!(str = malloc(sizeof(char *) * (len + 1))))
		return (0);
	return (str);
}

char		**ft_echo_split(char const *s)
{
	char	**str;
	int		len;
	int		i;
	int		j;

	if (!s)
		return (0);
	i = 0;
	j = 0;
	if (!(str = ft_split_malloc(s, ' ')))
		return (0);
	if ((len = ft_split_save(str, s, ' ')) == -1)
		return (0);
	str[len] = 0;
	return (str);
}
