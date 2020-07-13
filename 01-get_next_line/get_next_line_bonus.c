/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohlee <yohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 02:33:22 by yohlee            #+#    #+#             */
/*   Updated: 2020/07/13 11:08:35 by yohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*combine_str(char *s1, char *s2)
{
	int		i;
	int		j;
	int		len;
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

int		move_lines(char **line, t_list *mv_info, char *new_line)
{
	if (!(*line = ft_substr(mv_info->lines, 0, new_line - mv_info->lines)))
		return (-1);
	++new_line;
	ft_memmove(mv_info->lines, new_line, ft_strlen(new_line) + 1);
	return (1);
}

int		read_lines(int fd, char **line, char *buf, t_list *mv_info)
{
	char	*new_line;
	int		bytes;

	while ((bytes = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[bytes] = '\0';
		if (!(mv_info->lines = combine_str(mv_info->lines, buf)))
			return (-1);
		if ((new_line = ft_strchr(mv_info->lines, '\n')))
		{
			if (!(move_lines(line, mv_info, new_line)))
				return (-1);
			return (1);
		}
	}
	if (bytes == 0)
		*line = (mv_info->lines) ? ft_strdup(mv_info->lines) : ft_strdup("");
	else if (bytes == -1)
		*line = ft_strdup("");
	free(mv_info->lines);
	mv_info->lines = 0;
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static t_list	*fd_info;
	t_list			*mv_info;
	char			*buf;
	char			*new_line;
	int				ret;

	if (fd < 0 || !line || BUFFER_SIZE < 1 || read(fd, NULL, 0) < 0)
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
	if (mv_info->lines && (new_line = ft_strchr(mv_info->lines, '\n')))
		return (move_lines(line, mv_info, new_line));
	if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	ret = read_lines(fd, line, buf, mv_info);
	free(buf);
	buf = 0;
	return (ret);
}
