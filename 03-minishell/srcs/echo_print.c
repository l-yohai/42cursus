/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohlee <yohlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 12:32:43 by yohlee            #+#    #+#             */
/*   Updated: 2020/07/21 12:35:16 by yohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_env(t_arg *a, char *cmd, int *i, char c)
{
	char	*var;

	if ((var = ft_find_var(a, ft_strldup(&cmd[*i], a->len + 1), a->len)))
	{
		check_space(a, cmd, i, c);
		write(a->fd, var, ft_strlen(var));
		*i += a->len;
		a->check = 2;
	}
	else
	{
		check_space(a, cmd, i, c);
		*i += a->len;
		move_space(cmd, i, c);
		a->check = 1;
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
	if (a->check == 2 && cmd[*i + j] != '\0' && cmd[*i + j] != '$')
		write(a->fd, &cmd[*i], 1);
	else if (a->check == 1 && cmd[*i + j] != '\0' && cmd[*i + j] != '$')
		write(a->fd, &cmd[*i], 1);
	else if (a->check == 0 && cmd[*i + j] != '\0')
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
