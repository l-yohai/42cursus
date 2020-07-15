/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeong <jujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 20:37:35 by jujeong           #+#    #+#             */
/*   Updated: 2020/06/11 15:40:47 by jujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		get_next_line(int fd, char **line)
{
	static char	*lines[1024] = {0};
	char		buf[BUFFER_SIZE + 1];
	char		*temp;
	int			rsize;

	if (BUFFER_SIZE < 1 || !line || fd < 0)
		return (-1);
	if (!lines[fd])
	{
		lines[fd] = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		lines[fd][0] = 0;
	}
	while ((rsize = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[rsize] = '\0';
		temp = ft_strjoin(lines[fd], buf);
		free(lines[fd]);
		lines[fd] = temp;
		if (ft_strchr(lines[fd], '\n'))
			break ;
	}
	if (rsize < 0)
		return (-1);
	return (read_line(fd, line, lines));
}

int		read_line(int fd, char **line, char **lines)
{
	int		len;
	char	*temp;

	len = 0;
	while (lines[fd][len] && lines[fd][len] != '\n')
		len++;
	if (lines[fd][len] == '\n')
	{
		*line = ft_substr(lines[fd], 0, len);
		temp = ft_strdup(lines[fd] + len + 1);
		free(lines[fd]);
		lines[fd] = temp;
		return (1);
	}
	*line = ft_strdup(lines[fd]);
	free(lines[fd]);
	lines[fd] = 0;
	return (0);
}
