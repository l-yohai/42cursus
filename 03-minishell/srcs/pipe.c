/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohlee <yohlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 18:35:50 by yohlee            #+#    #+#             */
/*   Updated: 2020/07/18 23:29:30 by yohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	make_pipeline(t_arg *a, char **line1, char **line2)
{
	char	*tmp;

	*line1 = ft_strldup(a->line, ft_strchr(a->line, '|') - a->line);
	*line2 = ft_strdup(ft_strchr(a->line, '|') + 1);
	tmp = *line1;
	*line1 = ft_strtrim(tmp, " ");
	free(tmp);
	tmp = *line2;
	*line2 = ft_strtrim(tmp, " ");
	free(tmp);
}

void	get_process(t_arg *a, int fd[2], char *line, int n)
{
	dup2(fd[n], (n == 1) ? STDOUT_FILENO : STDIN_FILENO);
	close(fd[1]);
	close(fd[0]);
	free(a->line);
	a->line = line;
	ft_exec(a);
	exit(0);
}

void	close_process(int fd[2], int pid1, int pid2, char *line1, char *line2)
{
	int		status1;
	int		status2;

	close(fd[1]);
	close(fd[0]);
	waitpid(pid2, &status2, 0);
	waitpid(pid1, &status1, WNOHANG);
	free(line1);
	free(line2);
}

int		ft_pipe(t_arg *a)
{
	int		pid1;
	int		pid2;
	char	*line1;
	char	*line2;
	int		fd[2];

	if (ft_strchr(a->line, '|'))
	{
		make_pipeline(a, &line1, &line2);
		pipe(fd);
		pid1 = fork();
		if (pid1 == -1)
			write(2, "fork error\n", 11);
		if (pid1 == 0)
			get_process(a, fd, line1, 1);
		pid2 = fork();
		if (pid2 == -1)
			write(2, "fork error\n", 11);
		if (pid2 == 0)
			get_process(a, fd, line2, 0);
		close_process(fd, pid1, pid2, line1, line2);
		return (1);
	}
	return (0);
}
