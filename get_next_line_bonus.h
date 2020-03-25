/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohlee <yohlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 23:47:11 by yohlee            #+#    #+#             */
/*   Updated: 2020/03/09 08:52:37 by yohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 32
#endif

# include <stdlib.h>
# include <unistd.h>

typedef struct		s_list
{
	int				fd;
	char			*lines;
	struct s_list	*next;
}					t_list;

/*
** get_next_line_utils_bonus.c
*/

void				*ft_memmove(void *dst, const void *src, size_t len);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strchr(const char *s, int c);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s);

/*
** get_next_line_bonus.c
*/

t_list				*make_new_list(int fd);
char				*str_dup_cat(char *s1, char *s2);
int					get_line(char *lines, char **line, char *found_chr);
char				*read_lines(int fd, char **line, char *lines);
int					get_next_line(int fd, char **line);

#endif
