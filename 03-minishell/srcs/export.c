/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohlee <yohlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 18:38:35 by yohlee            #+#    #+#             */
/*   Updated: 2020/07/20 20:57:39 by yohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**sort_envp(char **tmp)
{
	int		i;
	int		j;
	char	*change;

	i = 0;
	while (tmp[i])
	{
		j = i + 1;
		while (tmp[j])
		{
			if (ft_strcmp(tmp[i], tmp[j]) > 0)
			{
				change = tmp[i];
				tmp[i] = tmp[j];
				tmp[j] = change;
			}
			j++;
		}
		i++;
	}
	return (tmp);
}

char	**init_envp(t_arg *a)
{
	int		i;
	char	**tmp;

	i = 0;
	while (a->envp[i])
		i++;
	tmp = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (a->envp[i])
	{
		tmp[i] = a->envp[i];
		i++;
	}
	tmp[i] = 0;
	return (tmp);
}

int		ft_export_only(t_arg *a)
{
	char	**tmp;
	int		i;

	tmp = init_envp(a);
	tmp = sort_envp(tmp);
	i = 0;
	while (tmp[i])
	{
		if (ft_strncmp(tmp[i], "_=", 2))
		{
			write(a->fd, tmp[i], ft_strlen(tmp[i]));
			write(a->fd, "\n", 1);
		}
		i++;
	}
	free(tmp);
	return (1);
}

int		ft_export(t_arg *a)
{
	char	**lines;
	char	**tmp;

	lines = ft_split(a->line, ' ');
	if (!lines[1])
	{
		ft_free(lines);
		ft_export_only(a);
		return (1);
	}
	tmp = 0;
	start_export(a, lines, tmp);
	ft_free(lines);
	return (1);
}
