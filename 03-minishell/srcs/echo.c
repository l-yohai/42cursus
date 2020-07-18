/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohlee <yohlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 18:37:22 by yohlee            #+#    #+#             */
/*   Updated: 2020/07/19 03:07:30 by yohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		find_echo_newline(char **cmd)
{
	int	newline;

	newline = 0;
	while (**cmd)
	{
		if (ft_strnstr(*cmd, "-n", 2))
		{
			if (*(*cmd + 2) && *(*cmd + 2) == ' ')
			{
				newline++;
				*cmd = *cmd + 3;
			}
			else if (!*(*cmd + 2))
			{
				newline++;
				*cmd = *cmd + 2;
				break ;
			}
			else
				break ;
		}
		else
			break ;
	}
	return (newline);
}

void	print_echo(t_arg *a, char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '\'' &&\
			(ft_strchr(cmd + i, '\'') != ft_strrchr(cmd + i, '\'')))
			print_cmd(a, cmd, &i, '\'');
		else if (cmd[i] == '\"' &&\
			(ft_strchr(cmd + i, '\"') != ft_strrchr(cmd + i, '\"')))
			print_quotes(a, cmd, &i);
		else if (cmd[i] == '\\')
		{
			write(a->fd, &cmd[++i], 1);
			i++;
		}
		else
			print_no_special_char(a, cmd, &i);
		i++;
	}
}

int		ft_echo(t_arg *a)
{
	char	*cmd;
	int		newline;

	if (ft_strchr(a->echo, '>'))
		*(ft_strchr(a->echo, '>')) = '\0';
	if (ft_strchr(a->echo, '<'))
		*(ft_strchr(a->echo, '<')) = '\0';
	if (ft_strchr(a->echo, '|'))
		*(ft_strchr(a->echo, '|')) = '\0';
	while (*(a->echo) == ' ')
		a->echo += 1;
	if (!(cmd = ft_strchr(a->echo, ' ')))
		return (write(1, "\n", 1) && 1);
	while (*cmd == ' ')
		cmd++;
	newline = find_echo_newline(&cmd);
	print_echo(a, cmd);
	if (!newline)
		write(a->fd, "\n", 1);
	// free(cmd);
	// cmd = 0;
	return (1);
}