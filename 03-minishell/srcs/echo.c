/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohlee <yohlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 18:37:22 by yohlee            #+#    #+#             */
/*   Updated: 2020/07/20 19:49:55 by yohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_env(t_arg *a, char *cmd, int *i, char c)
{
	int		len;

	len = 0;
	while (ft_isalnum(cmd[*i + len + 1]))
		len++;
	if (cmd[*i + 1] == '?' || ft_isdigit(cmd[*i + 1]))
		len = 1;
	if (len == 0)
		write(1, &cmd[*i], 1);
	else
		print_env(a, cmd, i, len, c);
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
