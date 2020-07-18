/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohlee <yohlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 20:37:35 by jujeong           #+#    #+#             */
/*   Updated: 2020/07/18 23:03:16 by yohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

int		move_lines(char **line, char **lines, char *new_line)
{
	if (!(*line = ft_substr(*lines, 0, new_line - *lines)))
		return (-1);
	++new_line;
	ft_memmove(*lines, new_line, ft_strlen(new_line) + 1);
	return (1);
}

int		read_lines(int fd, char **line, char **lines, char *buf)
{
	char	*new_line;
	int		bytes;
	while ((bytes = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[bytes] = '\0';
		if (!(*lines = combine_str(*lines, buf)))
			return (-1);
		if ((new_line = ft_strchr(*lines, '\n')))
		{
			if (!(move_lines(line, lines, new_line)))
				return (-1);
			return (1);
		}
	}
	if (bytes == 0)
		*line = (*lines) ? ft_strdup(*lines) : ft_strdup("");
	else if (bytes == -1)
		*line = ft_strdup("");
	free(*lines);
	*lines = 0;
	return (0);
}

int		all_free(char *lines, char *new_line, char *buf)
{
	if (lines)
	{
		free(lines);
		lines = 0;
	}
	if (new_line)
	{
		free(new_line);
		new_line = 0;
	}
	if (buf)
	{
		free(buf);
		buf = 0;
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*lines;
	char		*new_line;
	char		*buf;
	int			ret;
	if (fd < 0 || !line || BUFFER_SIZE < 1 || read(fd, NULL, 0) < 0)
		return (-1);
	if (lines && (new_line = ft_strchr(lines, '\n')))
		return (move_lines(line, &lines, new_line));
	if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
	{
		all_free(lines, new_line, buf);
		return (-1);
	}
	ret = read_lines(fd, line, &lines, buf);
	free(buf);
	buf = 0;
	return (ret);
}
