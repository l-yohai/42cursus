/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohlee <yohlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 14:56:31 by jujeong           #+#    #+#             */
/*   Updated: 2020/07/18 23:09:04 by yohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sig_handler(int signo)
{
	char	pwd[1024];
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
		{
			getcwd(pwd, 1024);
			write(1, pwd, ft_strlen(pwd));
			write(1, " $ ", 3);
		}
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
			a.ret = ft_exec_semi(&a);
		else
			a.ret = ft_exec(&a);
		free(a.line);
		a.line = 0;
	}
	return (0);
}
