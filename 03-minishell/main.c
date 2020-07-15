/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohlee <yohlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 20:01:10 by yohlee            #+#    #+#             */
/*   Updated: 2020/07/15 10:40:36 by yohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**g_envp;

void	ft_free(void *s)
{
	free(s);
	s = 0;
}

void	ft_free_2d(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	str = 0;
}

void	exit_shell(void)
{
	if (g_envp)
		ft_free_2d(g_envp);
	write(1, "\n", 1);
	exit(0);
}

int	ft_strlen_2d(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	init_envp(int argc, char **argv, char **envp)
{
	int	i;

	if (!(g_envp = (char **)malloc(sizeof(char *) * (ft_strlen_2d(envp) + 1))))
		return (-1);
	i = 0;
	while (envp[i])
	{
		if (!(g_envp[i] = ft_strdup(envp[i])))
			return (-1);
	}
	return (0);
}

char	*ft_strjoinch(char const *s1, char c)
{
	char	*new_str;
	size_t	i;
	size_t	s1_len;

	if (!s1 || !c)
		return (NULL);
	s1_len = ft_strlen(s1);
	new_str = ft_strnew(s1_len + 1);
	if (!new_str)
		return (NULL);
	i = -1;
	while (++i < s1_len)
		*(new_str + i) = *(s1 + i);
	*(new_str + i) = c;
	return (new_str);
}

int		ft_strendswith(char *s1, char *s2)
{
	int		i;

	i = -1;
	while (s1[++i])
		if (s1[i] == s2[0])
			if (ft_strncmp(s1 + i, s2, ft_strlen(s2)) == 0)
				return (1);
	return (0);
}

int		ft_strstartswith(char *s1, char *s2)
{
	int	i;

	i = -1;
	while (s2[++i])
		if (s1[i] != s2[i])
			return (0);
	return (1);
}

char	*ft_strjoincl(char *s1, char *s2, int free_both)
{
	char	*new;

	if (!(new = ft_strjoin(s1, s2)))
		return (NULL);
	free(s1);
	s1 = NULL;
	if (free_both)
	{
		free(s2);
		s2 = NULL;
	}
	return (new);
}

char	*ft_pathjoin(char *p1, char *p2)
{
	char	*tmp2;

	if (!p2 || !p1)
		return (NULL);
	if (!ft_strendswith(p1, "/"))
	{
		if (p2[0] == '/')
			return (ft_strjoin(p1, p2));
		else
		{
			tmp2 = ft_strjoincl(ft_strjoinch(p1, '/'), p2, 0);
			return (tmp2);
		}
	}
	else
	{
		if (p2[0] == '/')
			return (ft_strjoin(p1, p2 + 1));
		else
			return (ft_strjoin(p1, p2));
	}
}

char	*get_env_var(char *var)
{
	int		i;
	char	*tmp;

	i = -1;
	while (g_envp[++i])
	{
		tmp = ft_strjoinch(var, '=');
		if (ft_strstartswith(g_envp[i], tmp))
		{
			free(tmp);
			return (ft_strchr(g_envp[i], '=') + 1);
		}
		free(tmp);
	}
	return (NULL);
}

char	*parse_home_path(char *path, int reverse_parse)
{
	char	*home_path;
	char	*new;

	if (!path)
		return (NULL);
	home_path = get_env_var("HOME");
	if (!ft_strstartswith(path, reverse_parse ? "~" : home_path))
		return (ft_strdup(path));
	if (reverse_parse)
		new = ft_pathjoin(home_path, path + 1);
	else
	{
		if (*(path + ft_strlen(home_path)) == '\0')
			new = ft_strdup("~");
		else
			new = ft_pathjoin("~", path + ft_strlen(home_path));
	}
	return (new);
}

void	print_prompt_msg(void)
{
	char	*cwd;
	char	buff[4096 + 1];
	char	*parsed_cwd;

	cwd = getcwd(buff, 4096);
	parsed_cwd = parse_home_path(cwd, 0);
	ft_putstr(parsed_cwd);
	free(parsed_cwd);
	ft_putstr(" \033[31m︻\033[0m\033[32m┳\033[0m\033[33mデ");
	ft_putstr("\033[0m\033[34m═\033[0m\033[35m—\033[0m$ ");
}

int main(int argc, char **argv, char **envp)
{
	char	*input;
	char	**commands;
	int		ret;

	// if (init_envp(argc, argv, envp) == -1)
	// 	exit_shell();
	print_prompt_msg();
	// ft_free_2d(g_envp);
	return (0);
}