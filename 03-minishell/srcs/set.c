/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohlee <yohlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 02:46:21 by yohlee            #+#    #+#             */
/*   Updated: 2020/07/19 02:56:20 by yohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_print_var(t_arg *a)
{
	int		i;

	i = 0;
	while (a->var && a->var[i])
	{
		write(1, a->var[i], ft_strlen(a->var[i]));
		write(1, "\n", 1);
		i++;
	}
	return (1);
}

void	set_var(t_arg *a, int len)
{
	int		i;
	char	**tmp;

	i = -1;
	while (++i < a->vars)
	{
		if (!ft_strncmp(a->var[i], a->line, len + 1))
		{
			free(a->var[i]);
			a->var[i] = ft_strdup(a->line);
			break ;
		}
	}
	if (i == a->vars)
	{
		a->vars++;
		tmp = (char **)malloc(sizeof(char *) * (a->vars + 2));
		i = -1;
		while (++i < a->vars - 1)
			tmp[i] = a->var[i];
		tmp[i] = ft_strdup(a->line);
		tmp[++i] = 0;
		free(a->var);
		a->var = tmp;
	}
}

int		ft_set_var(t_arg *a)
{
	int		j;
	int		len;
	char	**lines;

	lines = ft_split(a->line, ' ');
	j = 0;
	while (lines[j])
	{
		free(a->line);
		a->line = ft_strdup(lines[j]);
		len = ft_strchr(a->line, '=') - a->line;
		set_var(a, len);
		j++;
	}
	ft_free(lines);
	return (1);
}
