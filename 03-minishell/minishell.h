
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohlee <yohlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 14:56:36 by jujeong           #+#    #+#             */
/*   Updated: 2020/07/17 18:50:58 by yohlee           ###   ########.fr       */
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
# include <sys/stat.h>
# include <sys/wait.h>
# include <signal.h>
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
	char	*echo;
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

void	ft_convert(t_arg *a);

/*
**		echo.c
*/

void	parse_env_quotes(t_arg *a, char *cmd, int *i, char c);
void	parse_env(t_arg *a, char *cmd, int *i, char c);
int		find_echo_newline(char **cmd);
void	print_echo(t_arg *a, char *cmd);

int		ft_echo(t_arg *a);

/*
**		echo_utils.c
*/

void	move_space(char *cmd, int *i, char c);
void	print_cmd(t_arg *a, char *cmd, int *i, char c);
void	print_space(t_arg *a, char *cmd, int *i);
void	print_quotes(t_arg *a, char *cmd, int *i);
void	print_no_special_char(t_arg *a, char *cmd, int *i);


int		ft_env(t_arg *a);

int		ft_exec(t_arg *a);
int		ft_exec_semi(t_arg *a);
int		ft_built_in(t_arg *a, int ret);

int		ft_exit(t_arg *a);

int		ft_export(t_arg *a);

int		ft_findpath(char **envp, char *line, t_child c);

int		ft_pipe(t_arg *a);

int		ft_child(t_arg *a);
int		ft_prompt(t_arg *a);

int		ft_pwd(t_arg *a, int newline);

int		ft_redirection_out(t_arg *a);
int		ft_redirection_in(t_arg *a);
int		ft_rediretion(t_arg *a);

int		ft_unset(t_arg *a);

int		ft_set_var(t_arg *a);
char	*ft_find_var(t_arg *a, char *var, int len);
int		ft_check_var(char *line);
int		ft_init_var(t_arg *a);

int		ft_error_file(char *file);
int		ft_free(char **strs);
void	get_prompt_design(void);

int		ft_print_var(t_arg *a); // 임시 확인용

#endif
