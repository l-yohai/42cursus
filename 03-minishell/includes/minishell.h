/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohlee <yohlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 14:56:36 by jujeong           #+#    #+#             */
/*   Updated: 2020/07/21 12:34:45 by yohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <errno.h>
# include <string.h>
# include "../libft/libft.h"

# define BUFFER_SIZE 2048

typedef struct	s_child
{
	int			i;
	char		**paths;
	char		cmd[1024];
	char		*tok;
	char		**lines;
}				t_child;

typedef struct	s_arg
{
	int			argc;
	char		**argv;
	char		**envp;
	char		*line;
	char		*echo;
	char		pwd[1024];
	int			pid;
	char		**var;
	int			vars;
	int			ret;
	char		str[16];
	int			fd;
	int			len;
	int			check;
}				t_arg;

typedef struct	s_pipe
{
	int			fd[2];
	int			pid1;
	int			pid2;
	char		*line1;
	char		*line2;
	int			status1;
	int			status2;
}				t_pipe;

/*
**				cd.c
*/

int				ft_cd(t_arg *a);

/*
**				convert.c
*/

void			ft_convert(t_arg *a);

/*
**				echo.c
*/

void			print_echo(t_arg *a, char *cmd);
int				ft_echo(t_arg *a);

/*
**				echo_print.c
*/

void			print_env(t_arg *a, char *cmd, int *i, char c);
void			print_cmd(t_arg *a, char *cmd, int *i, char c);
void			print_space(t_arg *a, char *cmd, int *i);
void			print_quotes(t_arg *a, char *cmd, int *i);
void			print_no_special_char(t_arg *a, char *cmd, int *i);

/*
**				echo_utils.c
*/

int				find_echo_newline(char **cmd);
void			move_space(char *cmd, int *i, char c);
void			check_space(t_arg *a, char *cmd, int *i, char c);
void			parse_env(t_arg *a, char *cmd, int *i, char c);
void			parse_env_quotes(t_arg *a, char *cmd, int *i, char c);

/*
**				env.c
*/

int				ft_env(t_arg *a);

/*
**				exec.c
*/

int				ft_built_in(t_arg *a, int ret);
int				ft_exec(t_arg *a);
int				ft_exec_semi(t_arg *a);

/*
**				exit.c
*/

int				ft_exit(t_arg *a);

/*
**				export.c
*/

int				ft_export(t_arg *a);

/*
**				export_utils.c
*/

int				set_equal(t_arg *a);
void			set_export(t_arg *a, char **tmp, int len);
void			start_export(t_arg *a, char **lines, char **tmp);

/*
**				get_next_line.c
*/

char			*combine_str(char *s1, char *s2);
int				move_lines(char **line, char **lines, char *new_line);
int				read_lines(int fd, char **line, char **lines, char *buf);
int				all_free(char *lines, char *new_line, char *buf);
int				get_next_line(int fd, char **line);

/*
**				path.c
*/

int				ft_findpath(char **envp, char *line, t_child c);

/*
**				pipe.c
*/

int				ft_pipe(t_arg *a);

/*
**				prompt.c
*/

int				ft_child(t_arg *a);
void			get_prompt_design(void);
int				ft_prompt(t_arg *a);

/*
**				pwd.c
*/

int				ft_pwd(t_arg *a, int newline);

/*
**				redirection.c
*/

int				ft_redirection_out(t_arg *a);
int				ft_redirection_in(t_arg *a);
int				ft_rediretion(t_arg *a);

/*
**				set.c
*/

char			*ft_find_var(t_arg *a, char *var, int len);
int				ft_set_var(t_arg *a);

/*
**				unset.c
*/

int				ft_unset(t_arg *a);

/*
**				utils.c
*/

void			error_identifier(t_arg *a);
void			error_context(t_arg *a);
void			error_equal(t_arg *a, char **lines, int i);
int				ft_error_file(char *file);
int				ft_free(char **strs);

/*
**				var.c
*/

int				ft_check_var(char *line);
int				ft_init_var(t_arg *a);

#endif
