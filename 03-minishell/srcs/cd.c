/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohlee <yohlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 18:38:18 by yohlee            #+#    #+#             */
/*   Updated: 2020/07/21 08:36:56 by yohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_cd_home(char **envp)
{
	int		i;

	i = 0;
	while (envp[i])
	{
		if (!(ft_strncmp(envp[i], "HOME=", 5)))
			break ;
		i++;
		if (!envp[i])
			return (-1);
	}
	if ((chdir(envp[i] + 5) == -1))
	{
		write(2, "cd: no such file or directory: ", 31);
		write(2, envp[i] + 5, ft_strlen(envp[i] + 5));
		write(2, "\n", 1);
		return (1);
	}
	return (0);
}

int		ft_cd(t_arg *a)
{
	char	**lines;

	lines = ft_split(a->line, ' ');
	if (!lines[1])
	{
		ft_free(lines);
		return (ft_cd_home(a->envp));
	}
	else if ((chdir(lines[1]) == -1))
	{
		write(2, "cd: no such file or directory: ", 31);
		write(2, lines[1], ft_strlen(lines[1]));
		write(2, "\n", 1);
		ft_free(lines);
		return (1);
	}
	ft_free(lines);
	return (0);
}
