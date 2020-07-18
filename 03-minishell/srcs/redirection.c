/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohlee <yohlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 18:36:20 by yohlee            #+#    #+#             */
/*   Updated: 2020/07/19 02:35:23 by yohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		start_redirection_in(t_arg *a, char *file)
{
	int		i;
	int		len;
	int		fd;
	char	*tmp;

	i = 0;
	len = 0;
	file += 1;
	while (*file && *file == ' ')
		file++;
	while (file[i] && file[i++] != ' ')
		len++;
	file = ft_strldup(file, len);
	if ((fd = open(file, O_RDONLY)) < 0)
		return (ft_error_file(file));
	tmp = ft_strldup(a->line, ft_strchr(a->line, '<') - a->line);
	free(a->line);
	a->line = tmp;
	free(file);
	return (fd);
}

int		ft_redirection_in(t_arg *a)
{
	char	*file;

	if ((file = ft_strchr(a->line, '<')))
		return (start_redirection_in(a, file));
	return (1);
}

int		start_redirection_out(t_arg *a, char *file, int pos, int opt)
{
	int		i;
	int		len;
	int		fd;
	char	*tmp;

	i = 0;
	len = 0;
	file += pos;
	while (*file && *file == ' ')
		file++;
	while (file[i] && file[i++] != ' ')
		len++;
	file = ft_strldup(file, len);
	if ((fd = open(file, O_RDWR | opt | S_IROTH, 0644)) < 0)
		return (ft_error_file(file));
	tmp = ft_strldup(a->line, ft_strchr(a->line, '>') - a->line);
	free(a->line);
	a->line = tmp;
	free(file);
	return (fd);
}

int		ft_redirection_out(t_arg *a)
{
	char	*file;

	if ((file = ft_strchr(a->line, '>')))
	{
		if (*(file + 1) == '>')
			return (start_redirection_out(a, file, 2, O_APPEND));
		else
			return (start_redirection_out(a, file, 1, O_CREAT));
	}
	return (1);
}

int		ft_rediretion(t_arg *a)
{
	int		fd;

	fd = ft_redirection_in(a);
	if (fd > 2)
	{
		dup2(fd, STDIN_FILENO);
		close(fd);
	}
	fd = ft_redirection_out(a);
	if (fd > 2)
	{
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
	return (0);
}
