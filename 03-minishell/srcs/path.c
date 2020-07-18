/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohlee <yohlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 18:44:31 by yohlee            #+#    #+#             */
/*   Updated: 2020/07/17 18:49:08 by yohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_findpath(char **envp, char *line, t_child c)
{
	c.i = -1;
	while (envp[++c.i])
	{
		if (!(ft_strncmp(envp[c.i], "PATH=", 5)))
			break ;
		else if (!envp[c.i])
			exit(-1); //PATH가 없는 경우
	}
	c.paths = ft_split(envp[c.i] + 5, ':');
	c.lines = ft_split(line, ' ');
	c.i = -1;
	while (c.paths[++c.i])
	{
		ft_memset(c.cmd, 0, 1024);
		ft_strcat(c.cmd, c.paths[c.i]);
		ft_strcat(c.cmd, "/");
		ft_strcat(c.cmd, c.tok);
		execve(c.cmd, c.lines, envp);
	}
	ft_free(c.lines);
	ft_free(c.paths);
	return (0);
}
