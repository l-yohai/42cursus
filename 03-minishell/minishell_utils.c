/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeong <jujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 23:32:36 by jujeong           #+#    #+#             */
/*   Updated: 2020/07/15 12:37:26 by jujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

char	*ft_strcat(char *src, char *dst)
{
	char	*str;

	str = src;
	while (*src)
		src++;
	while (*dst)
		*src++ = *dst++;
	*src = '\0';
	return (str);
}

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
			s1++;
			s2++;
	}
	return (*s1 - *s2);
}

char	*ft_strtok_s(char *str, char *sep, int *size)
{
	int		i;
	int		j;
	int		tmp;
	char	*cpy;

	i = 0;
	while (str[i])
	{
		j = 0;
		tmp = i;
		while (sep[j] && str[i] && str[i++] == sep[j++])
			if (!sep[j])
			{
				*size = i;
				cpy = (char *)malloc(tmp+ 1);
				cpy[tmp] = '\0';
				while (--tmp > -1)
					cpy[tmp] = str[tmp];
				return (cpy);
			}
		i = tmp + 1;
	}
	return (0);
}

int		ft_free(char **strs)
{
	int		i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
	return (0);
}

char	*ft_strldup(char *src, int len)
{
	int		i;
	char	*str;

	i = 0;
	if (!(str = (char *)malloc(len + 1)))
		return (0);
	while (i < len)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
