/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohlee <yohlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 18:35:50 by yohlee            #+#    #+#             */
/*   Updated: 2020/07/20 22:50:18 by yohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	make_pipeline(t_arg *a, t_pipe *p)
{
	char	*tmp;

	p->line1 = ft_strldup(a->line, ft_strchr(a->line, '|') - a->line);
	p->line2 = ft_strdup(ft_strchr(a->line, '|') + 1);
	tmp = p->line1;
	p->line1 = ft_strtrim(tmp, " ");
	free(tmp);
	tmp = p->line2;
	p->line2 = ft_strtrim(tmp, " ");
	free(tmp);
}

void	get_process(t_arg *a, t_pipe *p, char *line, int n)
{
	dup2(p->fd[n], (n == 1) ? STDOUT_FILENO : STDIN_FILENO);
	close(p->fd[1]);
	close(p->fd[0]);
	free(a->line);
	a->line = line;
	ft_exec(a);
	exit(0);
}

void	close_process(t_pipe *p)
{
	int		status1;
	int		status2;

	close(p->fd[1]);
	close(p->fd[0]);
	waitpid(p->pid2, &status2, 0);
	waitpid(p->pid1, &status1, WNOHANG);
	free(p->line1);
	free(p->line2);
}

int		ft_pipe(t_arg *a)
{
	t_pipe	p;

	if (ft_strchr(a->line, '|'))
	{
		make_pipeline(a, &p);
		pipe(p.fd);
		p.pid1 = fork();
		if (p.pid1 == -1)
			write(2, "fork error\n", 11);
		if (p.pid1 == 0)
			get_process(a, &p, p.line1, 1);
		p.pid2 = fork();
		if (p.pid2 == -1)
			write(2, "fork error\n", 11);
		if (p.pid2 == 0)
			get_process(a, &p, p.line2, 0);
		close_process(&p);
		return (1);
	}
	return (0);
}
