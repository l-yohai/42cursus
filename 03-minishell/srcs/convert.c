/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohlee <yohlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 18:43:55 by yohlee            #+#    #+#             */
/*   Updated: 2020/07/20 22:39:34 by yohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	convert_single_quotes(t_arg *a, int *i)
{
	int	save;
	int	j;

	save = 0;
	j = 1;
	while (a->line[*i + j] && a->line[*i + j] != '\'')
		j++;
	if (a->line[*i + j] == '\'')
	{
		j = 1;
		while (a->line[*i] && a->line[*i + j])
		{
			if (a->line[*i + j] == '\'')
			{
				save = *i;
				j = 2;
			}
			a->line[*i] = a->line[*i + j];
			(*i)++;
		}
		a->line[*i] = a->line[*i + j];
	}
	*i = save > 0 ? save - 1 : *i;
}

void	convert_double_quotes(t_arg *a, int *i)
{
	int	save;
	int	j;

	save = *i;
	j = 1;
	while (a->line[*i + j] && a->line[*i + j] != '\"')
		j++;
	if (a->line[*i + j] && a->line[*i + j] == '\"')
	{
		j = 1;
		while (a->line[*i + j] && a->line[*i + j])
		{
			if (a->line[*i + j] == '\"')
				j = 2;
			a->line[*i] = a->line[*i + j];
			(*i)++;
		}
		a->line[*i] = a->line[*i + j];
	}
	*i = save;
}

void	convert_env(t_arg *a, int *i)
{
	int		j;
	char	*str;
	char	*tmp;

	j = 1;
	while (ft_isalnum(a->line[*i + j]) || a->line[*i + j] == '?')
		j++;
	if (!ft_find_var(a, a->line + *i, j - 1))
		str = ft_strdup("");
	else
		str = ft_strdup(ft_find_var(a, a->line + *i, j - 1));
	tmp = a->line;
	a->line = (char *)malloc(ft_strlen(str) + *i + ft_strlen(tmp + *i + j) + 2);
	ft_strlcpy(a->line, tmp, *i + 1);
	ft_strcat(a->line, str);
	ft_strcat(a->line, tmp + *i + j);
	*i += j;
	free(tmp);
	free(str);
}

void	ft_convert(t_arg *a)
{
	int		i;

	i = 0;
	while (a->line[i])
	{
		if (a->line[i] == '\'')
			convert_single_quotes(a, &i);
		if (a->line[i] == '\"')
			convert_double_quotes(a, &i);
		if (a->line[i] == '$')
			convert_env(a, &i);
		i++;
	}
}
