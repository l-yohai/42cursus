/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohlee <yohlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 09:43:00 by yohlee            #+#    #+#             */
/*   Updated: 2020/07/20 20:57:43 by yohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		set_equal(t_arg *a)
{
	int		len;
	char	*tmp;

	len = ft_strchr(a->line, '=') - a->line;
	if (!ft_strchr(a->line, '='))
	{
		len = ft_strlen(a->line);
		tmp = a->line;
		a->line = (char *)malloc(len + 4);
		a->line[0] = '\0';
		ft_strcat(a->line, tmp);
		ft_strcat(a->line, "=\'\'");
		free(tmp);
	}
	a->ret = 0;
	return (len);
}

void	set_export(t_arg *a, char **tmp, int len)
{
	int	i;

	i = -1;
	while (a->envp[++i])
	{
		if (!ft_strncmp(a->envp[i], a->line, len + 1))
		{
			free(a->envp[i]);
			a->envp[i] = ft_strdup(a->line);
			ft_set_var(a);
			break ;
		}
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
}

void	start_export(t_arg *a, char **lines, char **tmp)
{
	int	i;

	i = 0;
	while (lines[++i])
	{
		free(a->line);
		a->line = ft_strdup(lines[i]);
		if (lines[i][0] >= '0' && lines[i][0] <= '9')
		{
			error_identifier(a);
			break ;
		}
		if (ft_check_var(a->line))
		{
			error_context(a);
			break ;
		}
		if (lines[i][0] == '=')
		{
			error_equal(a, lines, i);
			break ;
		}
		set_export(a, tmp, set_equal(a));
	}
}
