/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohlee <yohlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 22:54:31 by yohlee            #+#    #+#             */
/*   Updated: 2020/07/19 02:01:24 by yohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_env(t_arg *a, char *cmd, int *i, char c)
{
	int		len;
	char	*var;

	len = 0;
	if (c == '\"')
		(*i)++;
	while (ft_isalnum(cmd[*i + len + 1]) || cmd[*i + len + 1] == '?')
		len++;
	if ((var = ft_find_var(a,\
			(c == '\"') ? ft_strldup(&cmd[*i], len + 1) : &cmd[*i], len)))
		write(a->fd, var, ft_strlen(var));
	*i += (c == '\"') ? len + 2 : len;
}

void	print_cmd(t_arg *a, char *cmd, int *i, char c)
{
	while (cmd[++(*i)] != c)
		write(a->fd, &cmd[*i], 1);
}

void	print_space(t_arg *a, char *cmd, int *i)
{
	int	j;

	j = 0;

	while (cmd[*i + j] == ' ')
		j++;
	if (cmd[*i + j] != '\0')
		write(a->fd, &cmd[*i], 1);
	*i += j - 1;
}

void	print_quotes(t_arg *a, char *cmd, int *i)
{
	if (cmd[*i + 1] && cmd[*i + 1] == '$')
		print_env(a, cmd, i, '\"');
	else
		print_cmd(a, cmd, i, '\"');
}

void	print_no_special_char(t_arg *a, char *cmd, int *i)
{
	if (cmd[*i] == '$')
		print_env(a, cmd, i, '$');
	else if (cmd[*i] == ' ')
		print_space(a, cmd, i);
	else
		write(a->fd, &cmd[*i], 1);
}
