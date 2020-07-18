/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohlee <yohlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 18:40:13 by yohlee            #+#    #+#             */
/*   Updated: 2020/07/19 02:57:25 by yohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_built_in(t_arg *a, int ret)
{
	char	**lines;

	lines = ft_split(a->line, ' ');
	a->fd = ft_redirection_out(a);
	if (!ft_redirection_in(a))
		return (1); // 수정필요
	if (!(ft_strcmp(lines[0], "echo")))
		ret = ft_echo(a);
	else if (!(ft_strcmp(lines[0], "cd")))
		ret = ft_cd(a);
	else if (!(ft_strcmp(lines[0], "pwd")))
		ret = ft_pwd(a, 1);
	else if (!(ft_strcmp(lines[0], "export")))
		ret = ft_export(a);//필요
	else if (!(ft_strcmp(lines[0], "unset")))
		ret = ft_unset(a);
	else if (!(ft_strcmp(lines[0], "env")))
		ret = ft_env(a);
	else if (!(ft_strcmp(lines[0], "exit")))
		ret = ft_exit(a);
	// else if (!(ft_strcmp(lines[0], "set")))
	// 	ret = ft_print_var(a); // set.c
	else if (ft_strchr(lines[0], '='))
		ret = ft_set_var(a);
	ft_free(lines);
	return (ret);
}

int		ft_exec_semi(t_arg *a)
{
	char	*multi;
	char	*tmp;
	int		len;

	len = 0;
	multi = a->line;
	tmp = multi;
	while (ft_strchr(multi, ';'))
	{
		a->line = ft_strtok_s(multi, ";", &len);
		if (!(a->echo = ft_calloc(len + 1, sizeof(char))))
			return (-1);
		ft_strlcpy(a->echo, a->line, len + 1);
		multi += len;
		ft_exec(a);
		free(a->line);
	}
	a->line = ft_strdup(multi);
	if (!(a->echo = ft_calloc(len + 1, sizeof(char))))
		return (-1);
	ft_strlcpy(a->echo, a->line, ft_strlen(a->line) + 1);
	ft_exec(a);
	free(tmp);
	return (0);
}

int		ft_exec(t_arg *a)
{
	char	*tmp;
	int		status;
	int		ret;

	ft_convert(a);
	tmp = a->line;
	a->line = ft_strtrim(tmp, " ");
	free(tmp);
	a->fd = 1;
	if (!*a->line)
		return (0);
	if (ft_pipe(a))
		return (0);
	if ((ret = ft_built_in(a, -1)) != -1)
		return (ret);
	a->pid = fork();
	if (!a->pid)
		ft_child(a);
	else if (a->pid > 0)
		waitpid(a->pid, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		return (WTERMSIG(status));
	return (0);
}
