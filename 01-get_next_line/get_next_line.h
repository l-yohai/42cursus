/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohlee <yohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 00:38:43 by yohlee            #+#    #+#             */
/*   Updated: 2020/07/13 11:08:13 by yohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <stdlib.h>
# include <unistd.h>

/*
** get_next_line_utils.c
*/

char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
void	*ft_memmove(void *dst, const void *src, size_t len);
char	*ft_substr(char const *s, unsigned int start, size_t len);

/*
** get_next_line.c
*/

char	*combine_str(char *s1, char *s2);
int		move_lines(char **line, char **lines, char *new_line);
int		read_lines(int fd, char **line, char **lines, char *buf);
int		all_free(char *lines, char *new_line, char *buf);
int		get_next_line(int fd, char **line);

#endif
