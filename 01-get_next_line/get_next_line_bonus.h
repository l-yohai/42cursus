/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohlee <yohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 02:33:38 by yohlee            #+#    #+#             */
/*   Updated: 2020/07/13 11:08:50 by yohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

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

char				*ft_strchr(const char *s, int c);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s);
void				*ft_memmove(void *dst, const void *src, size_t len);
char				*ft_substr(char const *s, unsigned int start, size_t len);

/*
** get_next_line_bonus.c
*/

t_list				*make_new_list(int fd);
char				*combine_str(char *s1, char *s2);
int					move_lines(char **line, t_list *mv_info, char *new_line);
int					read_lines(int fd, char **line, char *buf, t_list *mv_info);
int					get_next_line(int fd, char **line);

#endif
