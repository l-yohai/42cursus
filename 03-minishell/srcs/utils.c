/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohlee <yohlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 23:32:36 by jujeong           #+#    #+#             */
/*   Updated: 2020/07/20 20:57:48 by yohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error_identifier(t_arg *a)
{
	write(2, "export: not an identifier: ", 27);
	write(2, a->line, ft_strlen(a->line));
	write(2, "\n", 1);
	a->ret = 1;
}

void	error_context(t_arg *a)
{
	int	i;

	write(2, "export: not valid in this context: ", 35);
	i = 0;
	while (a->line[i] && a->line[i] != '=')
	{
		write(2, &a->line[i], 1);
		i++;
	}
	write(2, "\n", 1);
	a->ret = 1;
}

void	error_equal(t_arg *a, char **lines, int i)
{
	if (!lines[i][1])
	{
		if (i == 1)
			write(2, "minishell: bad assignment\n", 27);
		else
			write(2, "export: not valid in this context:\n", 35);
		a->ret = 1;
	}
	else if (lines[i][1])
	{
		write(2, "minishell: ", 11);
		write(2, &lines[i][1], ft_strlen(&lines[i][1]));
		write(2, "not found\n", 10);
		a->ret = 1;
	}
}

int		ft_error_file(char *file)
{
	write(2, "minishell: ", 12);
	write(2, strerror(errno), ft_strlen(strerror(errno)));
	write(2, ": ", 2);
	write(2, file, ft_strlen(file));
	write(2, "\n", 1);
	free(file);
	return (0);
}

int		ft_free(char **strs)
{
	int		i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
	return (0);
}
