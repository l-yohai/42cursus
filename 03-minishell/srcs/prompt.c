/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohlee <yohlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 18:49:10 by yohlee            #+#    #+#             */
/*   Updated: 2020/07/20 22:55:51 by yohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_child(t_arg *a)
{
	t_child	c;

	c.tok = ft_strtok(a->line, ' ');
	ft_rediretion(a);
	if (*a->line == '/' || *a->line == '.')
		execve(c.tok, ft_split(a->line, ' '), a->envp);
	else
		ft_findpath(a->envp, a->line, c);
	write(2, "minishell: command not found: ", 30);
	write(2, c.tok, ft_strlen(c.tok));
	write(2, "\n", 1);
	exit(127);
}

void	get_prompt_design(void)
{
	char	*cwd;

	cwd = getcwd(0, 1024);
	ft_putstr_fd("\033[32m\033[01m", 1);
	ft_putstr_fd("minishell", 1);
	ft_putstr_fd("\033[0m", 1);
	ft_putstr_fd(":", 1);
	ft_putstr_fd("\033[34m\033[01m", 1);
	ft_putstr_fd("~/", 1);
	ft_putstr_fd(ft_strrchr(cwd, '/') + 1, 1);
	ft_putstr_fd("\033[35m", 1);
	ft_putstr_fd(" $ ", 1);
	ft_putstr_fd("\033[0m", 1);
	free(cwd);
}

int		ft_prompt(t_arg *a)
{
	//get_prompt_design();
	if (!get_next_line(0, &(a->line)))
		exit(1);
	if (!(a->echo = ft_calloc(ft_strlen(a->line) + 1, sizeof(char))))
		exit(1);
	ft_strlcpy(a->echo, a->line, ft_strlen(a->line) + 1);
	a->fd = 1;
	// ft_redirection_out(a);
	return (0);
}
