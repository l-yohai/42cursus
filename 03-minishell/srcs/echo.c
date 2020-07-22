/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohlee <yohlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 18:37:22 by yohlee            #+#    #+#             */
/*   Updated: 2020/07/21 12:33:42 by yohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_echo(t_arg *a, char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '\'' &&\
			(ft_strchr(cmd + i, '\'') != ft_strrchr(cmd + i, '\'')))
		{
			i++;
			print_cmd(a, cmd, &i, '\'');
		}
		else if (cmd[i] == '\"' &&\
			(ft_strchr(cmd + i, '\"') != ft_strrchr(cmd + i, '\"')))
			print_quotes(a, cmd, &i);
		else if (cmd[i] == '\\')
			write(a->fd, &cmd[++i], 1);
		else
			print_no_special_char(a, cmd, &i);
		i++;
	}
}

int		ft_echo(t_arg *a)
{
	char	*cmd;
	char	*tmp;
	int		newline;

	tmp = a->echo;
	if (ft_strchr(tmp, '>'))
		*(ft_strchr(tmp, '>')) = '\0';
	if (ft_strchr(tmp, '<'))
		*(ft_strchr(tmp, '<')) = '\0';
	if (ft_strchr(tmp, '|'))
		*(ft_strchr(tmp, '|')) = '\0';
	while (*tmp == ' ')
		tmp += 1;
	if (!(cmd = ft_strchr(tmp, ' ')))
		return (write(1, "\n", 1) && 1);
	while (*cmd == ' ')
		cmd++;
	newline = find_echo_newline(&cmd);
	print_echo(a, cmd);
	if (!newline)
		write(a->fd, "\n", 1);
	return (0);
}
