/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohlee <yohlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 14:56:31 by jujeong           #+#    #+#             */
/*   Updated: 2020/07/20 19:49:53 by yohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sig_handler(int signo)
{
	int		status;
	int		pid;

	pid = waitpid(-1, &status, WNOHANG);
	if (signo == SIGQUIT)
	{
		if (pid == 0)
			write(1, "quit\n", 5);
	}
	else
	{
		write(1, "\n", 1);
		if (pid != 0)
			get_prompt_design();
	}
}

int		main(int argc, char *argv[], char *envp[])
{
	t_arg	a;

	a.argc = argc;
	a.argv = argv;
	a.envp = envp;
	ft_init_var(&a);
	signal(SIGINT, (void *)sig_handler);
	signal(SIGQUIT, (void *)sig_handler);
	while (1)
	{
		ft_prompt(&a);
		if (ft_strchr(a.line, ';'))
			ft_exec_semi(&a);
		else
			ft_exec(&a);
		free(a.line);
		free(a.echo);
		a.line = 0;
	}
	return (0);
}
