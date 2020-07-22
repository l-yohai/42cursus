/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohlee <yohlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 14:56:31 by jujeong           #+#    #+#             */
/*   Updated: 2020/07/21 17:19:53 by yohlee           ###   ########.fr       */
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

void	print_design(void)
{
	int		fd;
	char	*line;

	fd = open("born2code", O_RDONLY);
	write(1, "\n", 1);
	while (get_next_line(fd, &line))
	{
		ft_putstr_fd("\033[0m", 1);
		ft_putendl_fd(line, 1);
		free(line);
	}
	ft_putstr_fd("\033[31m", 1);
	ft_putendl_fd(line, 1);
	write(1, "\n", 1);
	ft_putstr_fd("\033[0m", 1);
	ft_putstr_fd("By Jujeong & Yohlee", 1);
	write(1, "\n", 1);
	write(1, "\n", 1);
	free(line);
	close(fd);
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
	print_design();
	while (1)
	{
		a.check = 0;
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
