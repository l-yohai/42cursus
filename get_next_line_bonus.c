/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohlee <yohlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 16:20:03 by yohlee            #+#    #+#             */
/*   Updated: 2020/03/09 08:52:36 by yohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/*
** a single static variable.
** multiple file descriptors.
*/

t_list	*make_new_list(int fd)
{
	t_list	*new;

	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	new->fd = fd;
	new->lines = 0;
	new->next = 0;
	return (new);
}

char	*str_dup_cat(char *s1, char *s2)
{
	int		i;
	int		j;
	int 	len;
	char	*res;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = -1;
	while (s1[++i])
		res[i] = s1[i];
	free(s1);
	s1 = 0;
	j = -1;
	while (s2[++j])
		res[i + j] = s2[j];
	res[len] = '\0';
	return (res);
}

int		get_line(char *lines, char **line, char *found_chr)
{
	*line = ft_substr(lines, 0, found_chr - lines);
	++found_chr;
	ft_memmove(lines, found_chr, ft_strlen(found_chr) + 1);
	return (1);
}

char	*read_lines(int fd, char **line, char *lines)
{
	char		*found_chr;
	int			bytes;
	char		buf[BUFFER_SIZE + 1];

	while (((bytes = read(fd, buf, BUFFER_SIZE)) > 0))
	{
		buf[bytes] = '\0';
		lines = str_dup_cat(lines, buf);
		if ((found_chr = ft_strchr(lines, '\n')))
		{
			get_line(lines, line, found_chr);
			return (lines);
		}
	}
	if (lines)
	{
		*line = ft_strdup(lines);
		free(lines);
		lines = 0;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static t_list	*fd_info;
	t_list			*mv_info;
	char			*found_chr;

	if (!fd || fd > 65536 || !line || BUFFER_SIZE < 1 || read(fd, NULL, 0) < 0)
		return (-1);
	if (!fd_info)
		fd_info = make_new_list(fd);
	mv_info = fd_info;
	while (mv_info->fd != fd)
	{
		if (!mv_info->next)
			mv_info->next = make_new_list(fd);
		mv_info = mv_info->next;
	}
	if (mv_info->lines && (found_chr = ft_strchr(mv_info->lines, '\n')))
		return (get_line(mv_info->lines, line, found_chr));
	if ((mv_info->lines = read_lines(fd, line, mv_info->lines)))
		return (1);
	return (0);
}
