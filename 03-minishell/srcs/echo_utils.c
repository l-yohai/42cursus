/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohlee <yohlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 22:54:31 by yohlee            #+#    #+#             */
/*   Updated: 2020/07/20 20:10:10 by yohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	move_space(char *cmd, int *i, char c)
{
	if (c == '$' && cmd[*i + 1] == ' ')
	{
		(*i)++;
		while (cmd[*i] == ' ')
			(*i)++;
		(*i)--;
	}
}

void	print_cmd(t_arg *a, char *cmd, int *i, char c)
{
	while (cmd[*i] != c)
	{
		write(a->fd, &cmd[*i], 1);
		(*i)++;
	}
}

void	print_space(t_arg *a, char *cmd, int *i)
{
	int	j;

	j = 0;

	while (cmd[*i + j] == ' ')
		j++;
	if (cmd[*i + j] != '\0' && cmd[*i + j] != '$')
		write(a->fd, &cmd[*i], 1);
	*i += j - 1;
}

void	print_quotes(t_arg *a, char *cmd, int *i)
{
	if (cmd[*i + 1] && cmd[*i + 2] && cmd[*i + 1] == '\\' && cmd[*i + 2] == '$')
	{
		*i += 2;
		print_cmd(a, cmd, i, '\"');
	}
	else if (ft_strchr(&cmd[*i], '$'))
		parse_env_quotes(a, cmd, i, '\"');
	else
	{
		(*i)++;
		print_cmd(a, cmd, i, '\"');
	}
}

void	print_no_special_char(t_arg *a, char *cmd, int *i)
{
	if (cmd[*i] == '$')
		parse_env(a, cmd, i, '$');
	else if (cmd[*i] == ' ')
		print_space(a, cmd, i);
	else
		write(a->fd, &cmd[*i], 1);
}
