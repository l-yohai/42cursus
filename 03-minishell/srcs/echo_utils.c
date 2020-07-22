/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohlee <yohlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 22:54:31 by yohlee            #+#    #+#             */
/*   Updated: 2020/07/21 12:33:38 by yohlee           ###   ########.fr       */
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

void	check_space(t_arg *a, char *cmd, int *i, char c)
{
	if (a->check == 2 && c == '$' && *i > 0 && cmd[*i - 1] == ' ')
		write(a->fd, " ", 1);
}

void	parse_env(t_arg *a, char *cmd, int *i, char c)
{
	a->len = 0;
	while (ft_isalnum(cmd[*i + a->len + 1]))
		a->len++;
	if (cmd[*i + 1] == '?' || ft_isdigit(cmd[*i + 1]))
		a->len = 1;
	if (a->len == 0)
	{
		check_space(a, cmd, i, c);
		write(1, &cmd[*i], 1);
		a->check = 0;
	}
	else
		print_env(a, cmd, i, c);
}

void	parse_env_quotes(t_arg *a, char *cmd, int *i, char c)
{
	while (ft_strchr(&cmd[*i], '$'))
	{
		while (cmd[*i] != '$')
		{
			if (cmd[*i] != c)
				write(a->fd, &cmd[*i], 1);
			(*i)++;
		}
		parse_env(a, cmd, i, c);
		(*i)++;
	}
	if (cmd[*i] != c)
		print_cmd(a, cmd, i, c);
}
