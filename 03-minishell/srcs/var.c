/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohlee <yohlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 18:40:41 by yohlee            #+#    #+#             */
/*   Updated: 2020/07/19 02:47:31 by yohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_init_envp(t_arg *a)
{
	int		i;
	char	**envp;

	i = 0;
	while (a->envp[i])
		i++;
	envp = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (a->envp[i])
	{
		envp[i] = ft_strdup(a->envp[i]);
		i++;
	}
	envp[i] = 0;
	a->envp = envp;
	return (1);
}

int		ft_init_var(t_arg *a)
{
	int		i;

	ft_init_envp(a);
	i = 0;
	a->vars = 0;
	a->ret = 0;
	while (a->envp[i])
		i++;
	a->var = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (a->envp[i])
	{
		a->var[i] = ft_strdup(a->envp[i]);
		a->vars++;
		i++;
	}
	a->var[i] = 0;
	return (0);
}

int		ft_check_var(char *line)
{
	char	*str;
	int		i;

	str = ft_strtok(line, '=');
	i = 0;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '0') || str[i] == '_' || \
			(str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
			i++;
		else
		{
			free(str);
			return (1);
		}
	}
	free(str);
	return (0);
}

char	*ft_find_var(t_arg *a, char *var, int len)
{
	int		i;
	char	*ret;

	if (!ft_strcmp(var, "$?"))
	{
		ret = ft_itoa(a->ret);
		ft_strlcpy(a->str, ret, ft_strlen(ret) + 1);
		free(ret);
		return (a->str);
	}
	i = 0;
	var++;
	while (a->var[i])
	{
		if (!ft_strncmp(a->var[i], var, len))
			return (a->var[i] + len + 1);
		i++;
	}
	return (0);
}
