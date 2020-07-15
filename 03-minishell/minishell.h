/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeong <jujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 14:56:36 by jujeong           #+#    #+#             */
/*   Updated: 2020/07/14 23:37:21 by jujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <errno.h>
# include <string.h>
# include "libft/libft.h"

# define BUFFER_SIZE 2048

typedef struct	s_child
{
	int		i;
	char	**paths;
	char	cmd[1024];
	char	*tok;
	char	**lines;
}				t_child;

typedef struct	s_arg
{
	int		argc;
	char	**argv;
	char	**envp;
	char	*line;
	char	echo[1024];
	char	pwd[1024];
	int		pid;
	char	**var;
	int		vars;
	int		ret;
	char	str[16];
	int		fd;
}				t_arg;

int		get_next_line(int fd, char **line);
int		read_line(int fd, char **line, char **lines);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *str, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);

char	*ft_strtok(char *str, char sep);
char	*ft_strcat(char *src, char *dst);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strtok_s(char *str, char *sep, int *size);
int		ft_free(char **strs);
char	*ft_strldup(char *src, int len);

int		ft_cd(t_arg *a);
int		ft_set_var(t_arg *a);
char	*ft_find_var(t_arg *a, char *var, int len);
void	ft_convert(t_arg *a);
int		ft_redirection_out(t_arg *a);
int		ft_redirection_in(t_arg *a);
int		ft_rediretion(t_arg *a);
int		ft_error_file(char *file);
int		ft_pipe(t_arg *a);

int		ft_print_var(t_arg *a); // 임시 확인용

#endif
