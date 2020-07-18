/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohlee <yohlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 18:39:03 by yohlee            #+#    #+#             */
/*   Updated: 2020/07/19 02:39:43 by yohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	unset_vars(t_arg *a, char **lines, int *i)
{
	int	j;

	j = 0;
	while (j < a->vars)
	{
		if (!ft_strncmp(a->var[j], lines[*i], ft_strlen(lines[*i])))
		{
			free(a->var[j]);
			while (++j < a->vars)
				a->var[j - 1] = a->var[j];
			a->var[j - 1] = a->var[j];
			a->vars--;
			break ;
		}
		j++;
	}
}

void	unset_envp(t_arg *a, char **lines, int *i)
{
	int	j;

	j = 0;
	while (a->envp[j])
	{
		if (!ft_strncmp(a->envp[j], lines[*i], ft_strlen(lines[*i])))
		{
			free(a->envp[j]);
			while (a->envp[++j])
				a->envp[j - 1] = a->envp[j];
			a->envp[j - 1] = a->envp[j];
			break ;
		}
		j++;
	}
}

int		ft_unset(t_arg *a)
{
	char	**lines;
	int		i;

	lines = ft_split(a->line, ' ');
	if (!lines[1])
	{
		write(2, "unset: not enough arguments\n", 28);
		ft_free(lines);
		return (1);
	}
	i = 0;
	while (lines[++i])
	{
		unset_vars(a, lines, &i);
		unset_envp(a, lines, &i);
	}
	ft_free(lines);
	return (1);
}
