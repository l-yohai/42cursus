/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeong <jujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 18:38:35 by yohlee            #+#    #+#             */
/*   Updated: 2020/07/19 21:57:54 by jujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_export_only(t_arg *a)
{
	char	**tmp;
	char	*change;
	int		i;
	int		j;

	i = 0;
	while (a->envp[i])
		i++;
	tmp = (char **)malloc(sizeof(char *) * (i + 1));
	i = -1;
	while (a->envp[++i])
		tmp[i] = a->envp[i];
	tmp[i] = 0;
	i = 0;
	while (tmp[i])
	{
		j = i + 1;
		while (tmp[j])
		{
			if (ft_strcmp(tmp[i], tmp[j]) > 0)
			{
				change = tmp[i];
				tmp[i] = tmp[j];
				tmp[j] = change;
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (tmp[i])
	{
		if (ft_strncmp(tmp[i], "_=", 2))
		{
			write(a->fd, tmp[i], ft_strlen(tmp[i]));
			write(a->fd, "\n", 1);
		}
		i++;
	}
	free(tmp);
	return (0);
}

int		ft_export(t_arg *a)
{
	int		i;
	int		j;
	int		len;
	char	**tmp;
	char	**lines;

	a->ret = 0;
	lines = ft_split(a->line, ' ');
	if (!lines[1])
	{
		ft_free(lines);
		ft_export_only(a);
		return (0);
	}
	j = 0;
	while (lines[++j])
	{
		free(a->line);
		a->line = ft_strdup(lines[j]);
		if (lines[j][0] >= '0' && lines[j][0] <= '9')
		{
			write(2, "export: not an identifier: ", 27);
			write(2, a->line, ft_strlen(a->line));
			write(2, "\n", 1);
			a->ret = 1;
			break ;
		}
		if (ft_check_var(a->line))
		{
			write(2, "export: not valid in this context: ", 35);
			i = 0;
			while (a->line[i] && a->line[i] != '=')
				write(2, &a->line[i++], 1);
			write(2, "\n", 1);
			a->ret = 1;
			break ;
		}
		if (lines[j][0] == '=')
		{
			if (!lines[j][1])
			{
				if (j == 1)
					write(2, "minishell: bad assignment\n", 27);
				else
					write(2, "export: not valid in this context:\n", 35);
				a->ret = 1;
				break ;
			}
			if (lines[j][1])
			{
				write(2, "minishell: ", 11);
				write(2, &lines[j][1], ft_strlen(&lines[j][1]));
				write(2, "not found\n", 10);
				a->ret = 1;
				break ;
			}
		}
		len = ft_strchr(a->line, '=') - a->line;
		if (!ft_strchr(a->line, '='))
		{
			char	*temp;
			len = ft_strlen(a->line);
			temp = a->line;
			a->line = (char *)malloc(len + 4);
			a->line[0] = '\0';
			ft_strcat(a->line, temp);
			ft_strcat(a->line, "=\'\'");
			free(temp);
			//printf("a->line = %s\n", a->line);
		}
		i = 0;
		while (a->envp[i])
		{
			if (!ft_strncmp(a->envp[i], a->line, len + 1))
			{
				free(a->envp[i]);
				a->envp[i] = ft_strdup(a->line);
				ft_set_var(a);
				break ;
			}
			i++;
		}
		if (!a->envp[i])
		{
			tmp = (char **)malloc(sizeof(char *) * (i + 2));
			i = -1;
			while (a->envp[++i])
				tmp[i] = a->envp[i];
			tmp[i] = ft_strdup(a->line);
			tmp[++i] = 0;
			free(a->envp);
			a->envp = tmp;
			ft_set_var(a);
		}
		a->ret = 0;
	}
	ft_free(lines);
	return (a->ret);
}
